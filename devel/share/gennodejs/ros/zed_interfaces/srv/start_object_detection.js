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

class start_object_detectionRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.confidence = null;
      this.tracking = null;
      this.people = null;
      this.vehicles = null;
    }
    else {
      if (initObj.hasOwnProperty('confidence')) {
        this.confidence = initObj.confidence
      }
      else {
        this.confidence = 0.0;
      }
      if (initObj.hasOwnProperty('tracking')) {
        this.tracking = initObj.tracking
      }
      else {
        this.tracking = false;
      }
      if (initObj.hasOwnProperty('people')) {
        this.people = initObj.people
      }
      else {
        this.people = false;
      }
      if (initObj.hasOwnProperty('vehicles')) {
        this.vehicles = initObj.vehicles
      }
      else {
        this.vehicles = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type start_object_detectionRequest
    // Serialize message field [confidence]
    bufferOffset = _serializer.float32(obj.confidence, buffer, bufferOffset);
    // Serialize message field [tracking]
    bufferOffset = _serializer.bool(obj.tracking, buffer, bufferOffset);
    // Serialize message field [people]
    bufferOffset = _serializer.bool(obj.people, buffer, bufferOffset);
    // Serialize message field [vehicles]
    bufferOffset = _serializer.bool(obj.vehicles, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type start_object_detectionRequest
    let len;
    let data = new start_object_detectionRequest(null);
    // Deserialize message field [confidence]
    data.confidence = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [tracking]
    data.tracking = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [people]
    data.people = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [vehicles]
    data.vehicles = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 7;
  }

  static datatype() {
    // Returns string type for a service object
    return 'zed_interfaces/start_object_detectionRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'd390c3c6cd39e296e71a58be92b33ec6';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    
    
    
    float32 confidence
    
    
    bool tracking
    
    
    bool people
    
    
    bool vehicles
    
    
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new start_object_detectionRequest(null);
    if (msg.confidence !== undefined) {
      resolved.confidence = msg.confidence;
    }
    else {
      resolved.confidence = 0.0
    }

    if (msg.tracking !== undefined) {
      resolved.tracking = msg.tracking;
    }
    else {
      resolved.tracking = false
    }

    if (msg.people !== undefined) {
      resolved.people = msg.people;
    }
    else {
      resolved.people = false
    }

    if (msg.vehicles !== undefined) {
      resolved.vehicles = msg.vehicles;
    }
    else {
      resolved.vehicles = false
    }

    return resolved;
    }
};

class start_object_detectionResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.done = null;
    }
    else {
      if (initObj.hasOwnProperty('done')) {
        this.done = initObj.done
      }
      else {
        this.done = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type start_object_detectionResponse
    // Serialize message field [done]
    bufferOffset = _serializer.bool(obj.done, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type start_object_detectionResponse
    let len;
    let data = new start_object_detectionResponse(null);
    // Deserialize message field [done]
    data.done = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 1;
  }

  static datatype() {
    // Returns string type for a service object
    return 'zed_interfaces/start_object_detectionResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '89bb254424e4cffedbf494e7b0ddbfea';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool done
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new start_object_detectionResponse(null);
    if (msg.done !== undefined) {
      resolved.done = msg.done;
    }
    else {
      resolved.done = false
    }

    return resolved;
    }
};

module.exports = {
  Request: start_object_detectionRequest,
  Response: start_object_detectionResponse,
  md5sum() { return '3dc3fed99897ebf70695916b3c7b7cdd'; },
  datatype() { return 'zed_interfaces/start_object_detection'; }
};
