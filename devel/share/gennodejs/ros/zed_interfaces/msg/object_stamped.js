// Auto-generated. Do not edit!

// (in-package zed_interfaces.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let geometry_msgs = _finder('geometry_msgs');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class object_stamped {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.label = null;
      this.label_id = null;
      this.confidence = null;
      this.position = null;
      this.linear_vel = null;
      this.tracking_state = null;
      this.bbox_2d = null;
      this.bbox_3d = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('label')) {
        this.label = initObj.label
      }
      else {
        this.label = '';
      }
      if (initObj.hasOwnProperty('label_id')) {
        this.label_id = initObj.label_id
      }
      else {
        this.label_id = 0;
      }
      if (initObj.hasOwnProperty('confidence')) {
        this.confidence = initObj.confidence
      }
      else {
        this.confidence = 0.0;
      }
      if (initObj.hasOwnProperty('position')) {
        this.position = initObj.position
      }
      else {
        this.position = new geometry_msgs.msg.Point32();
      }
      if (initObj.hasOwnProperty('linear_vel')) {
        this.linear_vel = initObj.linear_vel
      }
      else {
        this.linear_vel = new geometry_msgs.msg.Vector3();
      }
      if (initObj.hasOwnProperty('tracking_state')) {
        this.tracking_state = initObj.tracking_state
      }
      else {
        this.tracking_state = 0;
      }
      if (initObj.hasOwnProperty('bbox_2d')) {
        this.bbox_2d = initObj.bbox_2d
      }
      else {
        this.bbox_2d = new Array(4).fill(new geometry_msgs.msg.Point32());
      }
      if (initObj.hasOwnProperty('bbox_3d')) {
        this.bbox_3d = initObj.bbox_3d
      }
      else {
        this.bbox_3d = new Array(8).fill(new geometry_msgs.msg.Point32());
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type object_stamped
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [label]
    bufferOffset = _serializer.string(obj.label, buffer, bufferOffset);
    // Serialize message field [label_id]
    bufferOffset = _serializer.int16(obj.label_id, buffer, bufferOffset);
    // Serialize message field [confidence]
    bufferOffset = _serializer.float32(obj.confidence, buffer, bufferOffset);
    // Serialize message field [position]
    bufferOffset = geometry_msgs.msg.Point32.serialize(obj.position, buffer, bufferOffset);
    // Serialize message field [linear_vel]
    bufferOffset = geometry_msgs.msg.Vector3.serialize(obj.linear_vel, buffer, bufferOffset);
    // Serialize message field [tracking_state]
    bufferOffset = _serializer.int8(obj.tracking_state, buffer, bufferOffset);
    // Check that the constant length array field [bbox_2d] has the right length
    if (obj.bbox_2d.length !== 4) {
      throw new Error('Unable to serialize array field bbox_2d - length must be 4')
    }
    // Serialize message field [bbox_2d]
    obj.bbox_2d.forEach((val) => {
      bufferOffset = geometry_msgs.msg.Point32.serialize(val, buffer, bufferOffset);
    });
    // Check that the constant length array field [bbox_3d] has the right length
    if (obj.bbox_3d.length !== 8) {
      throw new Error('Unable to serialize array field bbox_3d - length must be 8')
    }
    // Serialize message field [bbox_3d]
    obj.bbox_3d.forEach((val) => {
      bufferOffset = geometry_msgs.msg.Point32.serialize(val, buffer, bufferOffset);
    });
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type object_stamped
    let len;
    let data = new object_stamped(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [label]
    data.label = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [label_id]
    data.label_id = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [confidence]
    data.confidence = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [position]
    data.position = geometry_msgs.msg.Point32.deserialize(buffer, bufferOffset);
    // Deserialize message field [linear_vel]
    data.linear_vel = geometry_msgs.msg.Vector3.deserialize(buffer, bufferOffset);
    // Deserialize message field [tracking_state]
    data.tracking_state = _deserializer.int8(buffer, bufferOffset);
    // Deserialize message field [bbox_2d]
    len = 4;
    data.bbox_2d = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.bbox_2d[i] = geometry_msgs.msg.Point32.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [bbox_3d]
    len = 8;
    data.bbox_3d = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.bbox_3d[i] = geometry_msgs.msg.Point32.deserialize(buffer, bufferOffset)
    }
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    length += object.label.length;
    return length + 191;
  }

  static datatype() {
    // Returns string type for a message object
    return 'zed_interfaces/object_stamped';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'd424656ac6d81bea041e4eb6457725ad';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # Standard Header
    Header header
    
    # Object label
    string label
    
    # Object label ID
    int16 label_id
    
    # Object confidence level (1-99)
    float32 confidence
    
    # Object centroid
    geometry_msgs/Point32 position
    
    # Object velocity
    geometry_msgs/Vector3 linear_vel
    
    # Tracking state
    # 0 -> OFF (object not valid)
    # 1 -> OK
    # 2 -> SEARCHING (occlusion occurred, trajectory is estimated)
    int8 tracking_state 
    
    # 2D Bounding box projected to Camera image
    #      0 ------- 1
    #      |         |
    #      |         |
    #      |         |
    #      3 ------- 2
    geometry_msgs/Point32[4] bbox_2d
    
    # 3D Bounding box in world frame
    #      1 ------- 2
    #     /.        /|
    #    0 ------- 3 |
    #    | .       | |           
    #    | 5.......| 6
    #    |.        |/       
    #    4 ------- 7
    geometry_msgs/Point32[8] bbox_3d
    
    ================================================================================
    MSG: std_msgs/Header
    # Standard metadata for higher-level stamped data types.
    # This is generally used to communicate timestamped data 
    # in a particular coordinate frame.
    # 
    # sequence ID: consecutively increasing ID 
    uint32 seq
    #Two-integer timestamp that is expressed as:
    # * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
    # * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
    # time-handling sugar is provided by the client library
    time stamp
    #Frame this data is associated with
    string frame_id
    
    ================================================================================
    MSG: geometry_msgs/Point32
    # This contains the position of a point in free space(with 32 bits of precision).
    # It is recommeded to use Point wherever possible instead of Point32.  
    # 
    # This recommendation is to promote interoperability.  
    #
    # This message is designed to take up less space when sending
    # lots of points at once, as in the case of a PointCloud.  
    
    float32 x
    float32 y
    float32 z
    ================================================================================
    MSG: geometry_msgs/Vector3
    # This represents a vector in free space. 
    # It is only meant to represent a direction. Therefore, it does not
    # make sense to apply a translation to it (e.g., when applying a 
    # generic rigid transformation to a Vector3, tf2 will only apply the
    # rotation). If you want your data to be translatable too, use the
    # geometry_msgs/Point message instead.
    
    float64 x
    float64 y
    float64 z
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new object_stamped(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.label !== undefined) {
      resolved.label = msg.label;
    }
    else {
      resolved.label = ''
    }

    if (msg.label_id !== undefined) {
      resolved.label_id = msg.label_id;
    }
    else {
      resolved.label_id = 0
    }

    if (msg.confidence !== undefined) {
      resolved.confidence = msg.confidence;
    }
    else {
      resolved.confidence = 0.0
    }

    if (msg.position !== undefined) {
      resolved.position = geometry_msgs.msg.Point32.Resolve(msg.position)
    }
    else {
      resolved.position = new geometry_msgs.msg.Point32()
    }

    if (msg.linear_vel !== undefined) {
      resolved.linear_vel = geometry_msgs.msg.Vector3.Resolve(msg.linear_vel)
    }
    else {
      resolved.linear_vel = new geometry_msgs.msg.Vector3()
    }

    if (msg.tracking_state !== undefined) {
      resolved.tracking_state = msg.tracking_state;
    }
    else {
      resolved.tracking_state = 0
    }

    if (msg.bbox_2d !== undefined) {
      resolved.bbox_2d = new Array(4)
      for (let i = 0; i < resolved.bbox_2d.length; ++i) {
        if (msg.bbox_2d.length > i) {
          resolved.bbox_2d[i] = geometry_msgs.msg.Point32.Resolve(msg.bbox_2d[i]);
        }
        else {
          resolved.bbox_2d[i] = new geometry_msgs.msg.Point32();
        }
      }
    }
    else {
      resolved.bbox_2d = new Array(4).fill(new geometry_msgs.msg.Point32())
    }

    if (msg.bbox_3d !== undefined) {
      resolved.bbox_3d = new Array(8)
      for (let i = 0; i < resolved.bbox_3d.length; ++i) {
        if (msg.bbox_3d.length > i) {
          resolved.bbox_3d[i] = geometry_msgs.msg.Point32.Resolve(msg.bbox_3d[i]);
        }
        else {
          resolved.bbox_3d[i] = new geometry_msgs.msg.Point32();
        }
      }
    }
    else {
      resolved.bbox_3d = new Array(8).fill(new geometry_msgs.msg.Point32())
    }

    return resolved;
    }
};

module.exports = object_stamped;
