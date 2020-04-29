# pragma once
#include "../include/ModbusRS485.hpp"
#include <serial/serial.h>

namespace tx2slam {

class Navigation
{
public:

  Navigation(int argc, char** argv);
  ~Navigation();

  void init();

  bool setTargetSpeed(float vLeft, float vRight, uint8_t direction);
  bool setTargetOmega(float omega, float omegaBias);
  float pidController(float omegaTarget, float omegaActual);


//  ModbusRS485 ser;
  serial::Serial ser;
  std::vector<uint8_t> speedArray;

private:

  int init_argc;
  char** init_argv;

  const float KP = 0.6;
  const float KI = 0.0;
  const float KD = 0.0;

};

bool Navigation::setTargetSpeed(float vLeft, float vRight, uint8_t direction)
{
  if(vLeft < 0)
    vLeft = 0;
  else if(vLeft > 1)
    vLeft = 1;

  if(vRight < 0)
    vRight = 0;
  else if(vRight > 1)
    vRight = 1;

  switch(direction)
  {
  case 0: // go straight
//    ser.UT_REGISTERS_TAB[0] = (((uint16_t)(vLeft/1*127)) << 8) | ((uint16_t)(vRight/1*127));
    speedArray[1] = (uint8_t)(vLeft/1*127);
    speedArray[2] = (uint8_t)(vRight/1*127);
    break;
  case 1: // turn left
//    ser.UT_REGISTERS_TAB[0] = (((uint16_t)(255-vLeft/1*127)) << 8) | ((uint8_t)(vRight/1*127));
    speedArray[1] = (uint8_t)(255-vLeft/1*127);
    speedArray[2] = (uint8_t)(vRight/1*127);
    break;
  case 2: // turn right
//    ser.UT_REGISTERS_TAB[0] = (((uint16_t)(vLeft/1*127)) << 8) | ((uint8_t)(255-vRight/1*127));
    speedArray[1] = (uint8_t)(vLeft/1*127);
    speedArray[2] = (uint8_t)(255-vRight/1*127);
    break;
  case 3: // go back
//    ser.UT_REGISTERS_TAB[0] = (((uint16_t)(255-vLeft/1*127)) << 8) | ((uint8_t)(255-vRight/1*127));
    speedArray[1] = (uint8_t)(255-vLeft/1*127);
    speedArray[2] = (uint8_t)(255-vRight/1*127);
    break;
  }

  ser.write(speedArray);

//  if(ser.WriteToPort()){
//    return true;
//  }else{
////    ROS_ERROR("Fail to send serial mag");
//    return false;
//  }
}

bool Navigation::setTargetOmega(float omega, float omegaBias)
{
  if(omega >= 0){
    setTargetSpeed((omega+omegaBias)*0.4,omega+omegaBias,1);
  }else{
    setTargetSpeed(-omega+omegaBias,(-omega+omegaBias)*0.4,2);
  }
  return true;
}

float Navigation::pidController(float omegaTarget, float omegaActual)
{
  static float Bias,omegaBias,Integral_bias,Last_Bias;
  Bias=omegaTarget-omegaActual;
  Integral_bias+=Bias;
  omegaBias=KP*Bias+KI*Integral_bias+KD*(Bias-Last_Bias);
  Last_Bias=Bias;

  return omegaBias;
}

Navigation::Navigation(int argc, char **argv) : init_argc(argc), init_argv(argv)
{
  try
  {
      ser.setPort("/dev/ttyUSB0");
      ser.setBaudrate(115200);
      serial::Timeout to = serial::Timeout::simpleTimeout(1000);
      ser.setTimeout(to);
      ser.open();
  }
  catch (serial::IOException& e)
  {
      ROS_ERROR_STREAM("Unable to open port ");
  }

  if(ser.isOpen())
  {
      ROS_INFO_STREAM("Serial Port initialized");
  }
  else
  {
      ROS_ERROR_STREAM("Unable to open port ");
  }

  speedArray.push_back(0xff);
  speedArray.push_back(0);
  speedArray.push_back(0);

}

Navigation::~Navigation()
{

}


}
