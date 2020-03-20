// Auto-generated. Do not edit!

// (in-package zed_interfaces.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let object_stamped = require('./object_stamped.js');

//-----------------------------------------------------------

class objects {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.objects = null;
    }
    else {
      if (initObj.hasOwnProperty('objects')) {
        this.objects = initObj.objects
      }
      else {
        this.objects = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type objects
    // Serialize message field [objects]
    // Serialize the length for message field [objects]
    bufferOffset = _serializer.uint32(obj.objects.length, buffer, bufferOffset);
    obj.objects.forEach((val) => {
      bufferOffset = object_stamped.serialize(val, buffer, bufferOffset);
    });
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type objects
    let len;
    let data = new objects(null);
    // Deserialize message field [objects]
    // Deserialize array length for message field [objects]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.objects = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.objects[i] = object_stamped.deserialize(buffer, bufferOffset)
    }
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    object.objects.forEach((val) => {
      length += object_stamped.getMessageSize(val);
    });
    return length + 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'zed_interfaces/objects';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'f74a9cc2a8c886c042be0d913eabb9fd';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # Array of `object_stamped` topics
    object_stamped[] objects
    
    ================================================================================
    MSG: zed_interfaces/object_stamped
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
    const resolved = new objects(null);
    if (msg.objects !== undefined) {
      resolved.objects = new Array(msg.objects.length);
      for (let i = 0; i < resolved.objects.length; ++i) {
        resolved.objects[i] = object_stamped.Resolve(msg.objects[i]);
      }
    }
    else {
      resolved.objects = []
    }

    return resolved;
    }
};

module.exports = objects;
