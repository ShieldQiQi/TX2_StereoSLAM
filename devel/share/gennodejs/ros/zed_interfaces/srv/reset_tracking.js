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

class reset_trackingRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
    }
    else {
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type reset_trackingRequest
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type reset_trackingRequest
    let len;
    let data = new reset_trackingRequest(null);
    return data;
  }

  static getMessageSize(object) {
    return 0;
  }

  static datatype() {
    // Returns string type for a service object
    return 'zed_interfaces/reset_trackingRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'd41d8cd98f00b204e9800998ecf8427e';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new reset_trackingRequest(null);
    return resolved;
    }
};

class reset_trackingResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.reset_done = null;
    }
    else {
      if (initObj.hasOwnProperty('reset_done')) {
        this.reset_done = initObj.reset_done
      }
      else {
        this.reset_done = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type reset_trackingResponse
    // Serialize message field [reset_done]
    bufferOffset = _serializer.bool(obj.reset_done, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type reset_trackingResponse
    let len;
    let data = new reset_trackingResponse(null);
    // Deserialize message field [reset_done]
    data.reset_done = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 1;
  }

  static datatype() {
    // Returns string type for a service object
    return 'zed_interfaces/reset_trackingResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'e1e87fc9e9e6c154eca93b9fa292cc05';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool reset_done
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new reset_trackingResponse(null);
    if (msg.reset_done !== undefined) {
      resolved.reset_done = msg.reset_done;
    }
    else {
      resolved.reset_done = false
    }

    return resolved;
    }
};

module.exports = {
  Request: reset_trackingRequest,
  Response: reset_trackingResponse,
  md5sum() { return 'e1e87fc9e9e6c154eca93b9fa292cc05'; },
  datatype() { return 'zed_interfaces/reset_tracking'; }
};
