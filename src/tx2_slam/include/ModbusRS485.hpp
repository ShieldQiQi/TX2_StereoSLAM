/////////////////////////////////////////////////////////////////////////

// All copyRights reserved
// Author: Qi
// Date: 2020:05:07
// contract me by: qi.shield95@foxmail.com
// This module use orbSlam2 and zed2 to build a map and save map

///////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2020, Qi.
//
// All rights reserved.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
///////////////////////////////////////////////////////////////////////////
#pragma once
#include <modbus.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <inttypes.h>
#include <stdint.h>
#include <ros/ros.h>

namespace tx2slam {

class ModbusRS485
{
public:
  ModbusRS485();
  ~ModbusRS485();

  bool WriteToPort();
  bool ReadFromPort();
  bool ReadandWrite();

#define SERVER_ID         17
#define INVALID_SERVER_ID 18

  const uint16_t UT_BITS_ADDRESS = 0x130;
  const uint16_t UT_BITS_NB = 0x25;
  const uint8_t  UT_BITS_TAB[5] = { 0xCD, 0x6B, 0xB2, 0x0E, 0x1B };
  const uint16_t UT_INPUT_BITS_ADDRESS = 0x1C4;
  const uint16_t UT_INPUT_BITS_NB = 0x16;
  const uint8_t  UT_INPUT_BITS_TAB[3] = { 0xAC, 0xDB, 0x35 };
  const uint16_t UT_REGISTERS_ADDRESS = 0x160;
  const uint16_t UT_REGISTERS_NB = 0x1;
  const uint16_t UT_REGISTERS_NB_MAX = 0x20;
  uint16_t UT_REGISTERS_TAB[1] = { 0x0000 };
  /* Raise a manual exception when this address is used for the first byte */
  const uint16_t UT_REGISTERS_ADDRESS_SPECIAL = 0x170;
  /* The response of the server will contains an invalid TID or slave */
  const uint16_t UT_REGISTERS_ADDRESS_INVALID_TID_OR_SLAVE = 0x171;
  /* The server will wait for 1 second before replying to test timeout */
  const uint16_t UT_REGISTERS_ADDRESS_SLEEP_500_MS = 0x172;
  /* The server will wait for 5 ms before sending each byte */
  const uint16_t UT_REGISTERS_ADDRESS_BYTE_SLEEP_5_MS = 0x173;
  /* If the following value is used, a bad response is sent.
     It's better to test with a lower value than
     UT_REGISTERS_NB_POINTS to try to raise a segfault. */
  const uint16_t UT_REGISTERS_NB_SPECIAL = 0x2;
  const uint16_t UT_INPUT_REGISTERS_ADDRESS = 0x108;
  const uint16_t UT_INPUT_REGISTERS_NB = 0x1;
  const uint16_t UT_INPUT_REGISTERS_TAB[1] = { 0x000A };
  const float    UT_REAL = 123456.00;
  const uint32_t UT_IREAL_ABCD = 0x0020F147;
  const uint32_t UT_IREAL_DCBA = 0x47F12000;
  const uint32_t UT_IREAL_BADC = 0x200047F1;
  const uint32_t UT_IREAL_CDAB = 0xF1470020;
  const int EXCEPTION_RC = 2;

  bool isConnected = 0;

private:
  const int NB_REPORT_SLAVE_ID = 10;
  uint8_t *tab_rp_bits = NULL;
  uint16_t *tab_rp_registers = NULL;
  uint16_t *tab_rp_registers_bad = NULL;
  modbus_t *ctx = NULL;
  int i;
  uint8_t value;
  int nb_points;
  int rc;
  float real;
  uint32_t old_response_to_sec;
  uint32_t old_response_to_usec;
  uint32_t new_response_to_sec;
  uint32_t new_response_to_usec;
  uint32_t old_byte_to_sec;
  uint32_t old_byte_to_usec;
  int use_backend = RTU;
  int success = FALSE;
  int old_slave;

  enum {
      TCP,
      TCP_PI,
      RTU
  };

  #define BUG_REPORT(_cond, _format, _args ...)     \
      printf("\nLine %d: assertion error for '%s': " _format "\n", __LINE__, # _cond, ## _args)

  #define ASSERT_TRUE(_cond, _format, __args...) {  \
      if (_cond) {                                  \
          printf("USB port response OK\n");                           \
      } else {                                      \
          BUG_REPORT(_cond, _format, ## __args);    \
      }                                             \
  };
};

ModbusRS485::ModbusRS485()
{
  // initialize the ttyUSB Port
  ctx = modbus_new_rtu("/dev/ttyUSB0", 115200, 'N', 8, 1);
  if (ctx == NULL) {
      ROS_ERROR("Unable to initialize the ttyUSB Port\n");
  }

  // set recovery mode if any error happens and set debug mode to enable output
  modbus_set_debug(ctx, TRUE);
  modbus_set_error_recovery(ctx, (modbus_error_recovery_mode)(MODBUS_ERROR_RECOVERY_LINK | MODBUS_ERROR_RECOVERY_PROTOCOL));

  // set the server ID
  modbus_set_slave(ctx, SERVER_ID);

  // set timeout if fail to connect the ttyUSB Port
  modbus_get_response_timeout(ctx, &old_response_to_sec, &old_response_to_usec);
  if (modbus_connect(ctx) == -1) {
    ROS_ERROR("Unable to connect to the ttyUSB Port: %s", modbus_strerror(errno));
    modbus_free(ctx);
  }else{
    isConnected = 1;
    ROS_INFO("connect to the ttyUSB Port sucessfully");
  }
  modbus_get_response_timeout(ctx, &new_response_to_sec, &new_response_to_usec);
  ASSERT_TRUE(old_response_to_sec == new_response_to_sec &&
              old_response_to_usec == new_response_to_usec, "");

  // Allocate and initialize the memory to store the bits
  nb_points = (UT_BITS_NB > UT_INPUT_BITS_NB) ? UT_BITS_NB : UT_INPUT_BITS_NB;
  tab_rp_bits = (uint8_t *) malloc(nb_points * sizeof(uint8_t));
  memset(tab_rp_bits, 0, nb_points * sizeof(uint8_t));
  // Allocate and initialize the memory to store the registers
  nb_points = (UT_REGISTERS_NB > UT_INPUT_REGISTERS_NB) ? UT_REGISTERS_NB : UT_INPUT_REGISTERS_NB;
  tab_rp_registers = (uint16_t *) malloc(nb_points * sizeof(uint16_t));
  memset(tab_rp_registers, 0, nb_points * sizeof(uint16_t));
}

ModbusRS485::~ModbusRS485()
{
  /* Free the memory */
  free(tab_rp_bits);
  free(tab_rp_registers);

  /* Close the connection */
  modbus_close(ctx);
  modbus_free(ctx);
}

bool ModbusRS485::WriteToPort()
{
  rc = modbus_write_registers(ctx, UT_REGISTERS_ADDRESS,
                              UT_REGISTERS_NB, UT_REGISTERS_TAB);
  return (rc == UT_REGISTERS_NB);
}

bool ModbusRS485::ReadFromPort()
{
  rc = modbus_read_registers(ctx, UT_REGISTERS_ADDRESS,
                             UT_REGISTERS_NB, tab_rp_registers);
  ASSERT_TRUE(rc == UT_REGISTERS_NB, "FAILED (nb points %d)\n", rc);

  for (i=0; i < UT_REGISTERS_NB; i++) {
      ASSERT_TRUE(tab_rp_registers[i] == UT_REGISTERS_TAB[i], "FAILED (%0X != %0X)\n",
                  tab_rp_registers[i], UT_REGISTERS_TAB[i]);
  }

  rc = modbus_read_registers(ctx, UT_REGISTERS_ADDRESS,
                             0, tab_rp_registers);
  ASSERT_TRUE(rc == -1, "FAILED (nb_points %d)\n", rc);
}

bool ModbusRS485::ReadandWrite()
{
  nb_points = (UT_REGISTERS_NB >
               UT_INPUT_REGISTERS_NB) ?
      UT_REGISTERS_NB : UT_INPUT_REGISTERS_NB;
  memset(tab_rp_registers, 0, nb_points * sizeof(uint16_t));

  /* Write registers to zero from tab_rp_registers and store read registers
     into tab_rp_registers. So the read registers must set to 0, except the
     first one because there is an offset of 1 register on write. */
  rc = modbus_write_and_read_registers(ctx,
                                       UT_REGISTERS_ADDRESS + 1,
                                       UT_REGISTERS_NB - 1,
                                       tab_rp_registers,
                                       UT_REGISTERS_ADDRESS,
                                       UT_REGISTERS_NB,
                                       tab_rp_registers);
  ASSERT_TRUE(rc == UT_REGISTERS_NB, "FAILED (nb points %d != %d)\n",
              rc, UT_REGISTERS_NB);

  ASSERT_TRUE(tab_rp_registers[0] == UT_REGISTERS_TAB[0],
              "FAILED (%0X != %0X)\n",
              tab_rp_registers[0], UT_REGISTERS_TAB[0]);

  for (i=1; i < UT_REGISTERS_NB; i++) {
      ASSERT_TRUE(tab_rp_registers[i] == 0, "FAILED (%0X != %0X)\n",
                  tab_rp_registers[i], 0);
  }
}


}

