; Auto-generated. Do not edit!


(cl:in-package zed_interfaces-msg)


;//! \htmlinclude objects.msg.html

(cl:defclass <objects> (roslisp-msg-protocol:ros-message)
  ((objects
    :reader objects
    :initarg :objects
    :type (cl:vector zed_interfaces-msg:object_stamped)
   :initform (cl:make-array 0 :element-type 'zed_interfaces-msg:object_stamped :initial-element (cl:make-instance 'zed_interfaces-msg:object_stamped))))
)

(cl:defclass objects (<objects>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <objects>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'objects)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name zed_interfaces-msg:<objects> is deprecated: use zed_interfaces-msg:objects instead.")))

(cl:ensure-generic-function 'objects-val :lambda-list '(m))
(cl:defmethod objects-val ((m <objects>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader zed_interfaces-msg:objects-val is deprecated.  Use zed_interfaces-msg:objects instead.")
  (objects m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <objects>) ostream)
  "Serializes a message object of type '<objects>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'objects))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'objects))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <objects>) istream)
  "Deserializes a message object of type '<objects>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'objects) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'objects)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'zed_interfaces-msg:object_stamped))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<objects>)))
  "Returns string type for a message object of type '<objects>"
  "zed_interfaces/objects")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'objects)))
  "Returns string type for a message object of type 'objects"
  "zed_interfaces/objects")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<objects>)))
  "Returns md5sum for a message object of type '<objects>"
  "f74a9cc2a8c886c042be0d913eabb9fd")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'objects)))
  "Returns md5sum for a message object of type 'objects"
  "f74a9cc2a8c886c042be0d913eabb9fd")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<objects>)))
  "Returns full string definition for message of type '<objects>"
  (cl:format cl:nil "# Array of `object_stamped` topics~%object_stamped[] objects~%~%================================================================================~%MSG: zed_interfaces/object_stamped~%# Standard Header~%Header header~%~%# Object label~%string label~%~%# Object label ID~%int16 label_id~%~%# Object confidence level (1-99)~%float32 confidence~%~%# Object centroid~%geometry_msgs/Point32 position~%~%# Object velocity~%geometry_msgs/Vector3 linear_vel~%~%# Tracking state~%# 0 -> OFF (object not valid)~%# 1 -> OK~%# 2 -> SEARCHING (occlusion occurred, trajectory is estimated)~%int8 tracking_state ~%~%# 2D Bounding box projected to Camera image~%#      0 ------- 1~%#      |         |~%#      |         |~%#      |         |~%#      3 ------- 2~%geometry_msgs/Point32[4] bbox_2d~%~%# 3D Bounding box in world frame~%#      1 ------- 2~%#     /.        /|~%#    0 ------- 3 |~%#    | .       | |           ~%#    | 5.......| 6~%#    |.        |/       ~%#    4 ------- 7~%geometry_msgs/Point32[8] bbox_3d~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Point32~%# This contains the position of a point in free space(with 32 bits of precision).~%# It is recommeded to use Point wherever possible instead of Point32.  ~%# ~%# This recommendation is to promote interoperability.  ~%#~%# This message is designed to take up less space when sending~%# lots of points at once, as in the case of a PointCloud.  ~%~%float32 x~%float32 y~%float32 z~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'objects)))
  "Returns full string definition for message of type 'objects"
  (cl:format cl:nil "# Array of `object_stamped` topics~%object_stamped[] objects~%~%================================================================================~%MSG: zed_interfaces/object_stamped~%# Standard Header~%Header header~%~%# Object label~%string label~%~%# Object label ID~%int16 label_id~%~%# Object confidence level (1-99)~%float32 confidence~%~%# Object centroid~%geometry_msgs/Point32 position~%~%# Object velocity~%geometry_msgs/Vector3 linear_vel~%~%# Tracking state~%# 0 -> OFF (object not valid)~%# 1 -> OK~%# 2 -> SEARCHING (occlusion occurred, trajectory is estimated)~%int8 tracking_state ~%~%# 2D Bounding box projected to Camera image~%#      0 ------- 1~%#      |         |~%#      |         |~%#      |         |~%#      3 ------- 2~%geometry_msgs/Point32[4] bbox_2d~%~%# 3D Bounding box in world frame~%#      1 ------- 2~%#     /.        /|~%#    0 ------- 3 |~%#    | .       | |           ~%#    | 5.......| 6~%#    |.        |/       ~%#    4 ------- 7~%geometry_msgs/Point32[8] bbox_3d~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Point32~%# This contains the position of a point in free space(with 32 bits of precision).~%# It is recommeded to use Point wherever possible instead of Point32.  ~%# ~%# This recommendation is to promote interoperability.  ~%#~%# This message is designed to take up less space when sending~%# lots of points at once, as in the case of a PointCloud.  ~%~%float32 x~%float32 y~%float32 z~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <objects>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'objects) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <objects>))
  "Converts a ROS message object to a list"
  (cl:list 'objects
    (cl:cons ':objects (objects msg))
))
