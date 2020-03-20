// Auto-generated. Do not edit!

// (in-package zed_interfaces.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------


//-----------------------------------------------------------

class start_remote_streamRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
    }
    else {
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type start_remote_streamRequest
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type start_remote_streamRequest
    let len;
    let data = new start_remote_streamRequest(null);
    return data;
  }

  static getMessageSize(object) {
    return 0;
  }

  static datatype() {
    // Returns string type for a service object
    return 'zed_interfaces/start_remote_streamRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'a6f55a6077162992b395e1b483a03367';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    
    
    uint8 codec=0
    
    
    
    uint16 port=30000
    
    
    uint32 bitrate=2000
    
    
    
    
    
    int32 gop_size=-1
    
    
    
    
    
    bool adaptative_bitrate=False
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new start_remote_streamRequest(null);
    return resolved;
    }
};

// Constants for message
start_remote_streamRequest.Constants = {
  CODEC: 0,
  PORT: 30000,
  BITRATE: 2000,
  GOP_SIZE: -1,
  ADAPTATIVE_BITRATE: false,
}

class start_remote_streamResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.result = null;
      this.info = null;
    }
    else {
      if (initObj.hasOwnProperty('result')) {
        this.result = initObj.result
      }
      else {
        this.result = false;
      }
      if (initObj.hasOwnProperty('info')) {
        this.info = initObj.info
      }
      else {
        this.info = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type start_remote_streamResponse
    // Serialize message field [result]
    bufferOffset = _serializer.bool(obj.result, buffer, bufferOffset);
    // Serialize message field [info]
    bufferOffset = _serializer.string(obj.info, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type start_remote_streamResponse
    let len;
    let data = new start_remote_streamResponse(null);
    // Deserialize message field [result]
    data.result = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [info]
    data.info = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.info.length;
    return length + 5;
  }

  static datatype() {
    // Returns string type for a service object
    return 'zed_interfaces/start_remote_streamResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '929b8c0d7b68510a3f501a60258c746e';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool result
    string info
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new start_remote_streamResponse(null);
    if (msg.result !== undefined) {
      resolved.result = msg.result;
    }
    else {
      resolved.result = false
    }

    if (msg.info !== undefined) {
      resolved.info = msg.info;
    }
    else {
      resolved.info = ''
    }

    return resolved;
    }
};

module.exports = {
  Request: start_remote_streamRequest,
  Response: start_remote_streamResponse,
  md5sum() { return 'c9f6f4c6411b7a0c79a7a7357650993c'; },
  datatype() { return 'zed_interfaces/start_remote_stream'; }
};
