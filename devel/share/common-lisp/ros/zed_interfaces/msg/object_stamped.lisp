; Auto-generated. Do not edit!


(cl:in-package zed_interfaces-msg)


;//! \htmlinclude object_stamped.msg.html

(cl:defclass <object_stamped> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (label
    :reader label
    :initarg :label
    :type cl:string
    :initform "")
   (label_id
    :reader label_id
    :initarg :label_id
    :type cl:fixnum
    :initform 0)
   (confidence
    :reader confidence
    :initarg :confidence
    :type cl:float
    :initform 0.0)
   (position
    :reader position
    :initarg :position
    :type geometry_msgs-msg:Point32
    :initform (cl:make-instance 'geometry_msgs-msg:Point32))
   (linear_vel
    :reader linear_vel
    :initarg :linear_vel
    :type geometry_msgs-msg:Vector3
    :initform (cl:make-instance 'geometry_msgs-msg:Vector3))
   (tracking_state
    :reader tracking_state
    :initarg :tracking_state
    :type cl:fixnum
    :initform 0)
   (bbox_2d
    :reader bbox_2d
    :initarg :bbox_2d
    :type (cl:vector geometry_msgs-msg:Point32)
   :initform (cl:make-array 4 :element-type 'geometry_msgs-msg:Point32 :initial-element (cl:make-instance 'geometry_msgs-msg:Point32)))
   (bbox_3d
    :reader bbox_3d
    :initarg :bbox_3d
    :type (cl:vector geometry_msgs-msg:Point32)
   :initform (cl:make-array 8 :element-type 'geometry_msgs-msg:Point32 :initial-element (cl:make-instance 'geometry_msgs-msg:Point32))))
)

(cl:defclass object_stamped (<object_stamped>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <object_stamped>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'object_stamped)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name zed_interfaces-msg:<object_stamped> is deprecated: use zed_interfaces-msg:object_stamped instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <object_stamped>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader zed_interfaces-msg:header-val is deprecated.  Use zed_interfaces-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'label-val :lambda-list '(m))
(cl:defmethod label-val ((m <object_stamped>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader zed_interfaces-msg:label-val is deprecated.  Use zed_interfaces-msg:label instead.")
  (label m))

(cl:ensure-generic-function 'label_id-val :lambda-list '(m))
(cl:defmethod label_id-val ((m <object_stamped>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader zed_interfaces-msg:label_id-val is deprecated.  Use zed_interfaces-msg:label_id instead.")
  (label_id m))

(cl:ensure-generic-function 'confidence-val :lambda-list '(m))
(cl:defmethod confidence-val ((m <object_stamped>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader zed_interfaces-msg:confidence-val is deprecated.  Use zed_interfaces-msg:confidence instead.")
  (confidence m))

(cl:ensure-generic-function 'position-val :lambda-list '(m))
(cl:defmethod position-val ((m <object_stamped>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader zed_interfaces-msg:position-val is deprecated.  Use zed_interfaces-msg:position instead.")
  (position m))

(cl:ensure-generic-function 'linear_vel-val :lambda-list '(m))
(cl:defmethod linear_vel-val ((m <object_stamped>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader zed_interfaces-msg:linear_vel-val is deprecated.  Use zed_interfaces-msg:linear_vel instead.")
  (linear_vel m))

(cl:ensure-generic-function 'tracking_state-val :lambda-list '(m))
(cl:defmethod tracking_state-val ((m <object_stamped>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader zed_interfaces-msg:tracking_state-val is deprecated.  Use zed_interfaces-msg:tracking_state instead.")
  (tracking_state m))

(cl:ensure-generic-function 'bbox_2d-val :lambda-list '(m))
(cl:defmethod bbox_2d-val ((m <object_stamped>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader zed_interfaces-msg:bbox_2d-val is deprecated.  Use zed_interfaces-msg:bbox_2d instead.")
  (bbox_2d m))

(cl:ensure-generic-function 'bbox_3d-val :lambda-list '(m))
(cl:defmethod bbox_3d-val ((m <object_stamped>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader zed_interfaces-msg:bbox_3d-val is deprecated.  Use zed_interfaces-msg:bbox_3d instead.")
  (bbox_3d m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <object_stamped>) ostream)
  "Serializes a message object of type '<object_stamped>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'label))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'label))
  (cl:let* ((signed (cl:slot-value msg 'label_id)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'confidence))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'position) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'linear_vel) ostream)
  (cl:let* ((signed (cl:slot-value msg 'tracking_state)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'bbox_2d))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'bbox_3d))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <object_stamped>) istream)
  "Deserializes a message object of type '<object_stamped>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'label) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'label) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'label_id) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'confidence) (roslisp-utils:decode-single-float-bits bits)))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'position) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'linear_vel) istream)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'tracking_state) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
  (cl:setf (cl:slot-value msg 'bbox_2d) (cl:make-array 4))
  (cl:let ((vals (cl:slot-value msg 'bbox_2d)))
    (cl:dotimes (i 4)
    (cl:setf (cl:aref vals i) (cl:make-instance 'geometry_msgs-msg:Point32))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream)))
  (cl:setf (cl:slot-value msg 'bbox_3d) (cl:make-array 8))
  (cl:let ((vals (cl:slot-value msg 'bbox_3d)))
    (cl:dotimes (i 8)
    (cl:setf (cl:aref vals i) (cl:make-instance 'geometry_msgs-msg:Point32))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<object_stamped>)))
  "Returns string type for a message object of type '<object_stamped>"
  "zed_interfaces/object_stamped")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'object_stamped)))
  "Returns string type for a message object of type 'object_stamped"
  "zed_interfaces/object_stamped")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<object_stamped>)))
  "Returns md5sum for a message object of type '<object_stamped>"
  "d424656ac6d81bea041e4eb6457725ad")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'object_stamped)))
  "Returns md5sum for a message object of type 'object_stamped"
  "d424656ac6d81bea041e4eb6457725ad")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<object_stamped>)))
  "Returns full string definition for message of type '<object_stamped>"
  (cl:format cl:nil "# Standard Header~%Header header~%~%# Object label~%string label~%~%# Object label ID~%int16 label_id~%~%# Object confidence level (1-99)~%float32 confidence~%~%# Object centroid~%geometry_msgs/Point32 position~%~%# Object velocity~%geometry_msgs/Vector3 linear_vel~%~%# Tracking state~%# 0 -> OFF (object not valid)~%# 1 -> OK~%# 2 -> SEARCHING (occlusion occurred, trajectory is estimated)~%int8 tracking_state ~%~%# 2D Bounding box projected to Camera image~%#      0 ------- 1~%#      |         |~%#      |         |~%#      |         |~%#      3 ------- 2~%geometry_msgs/Point32[4] bbox_2d~%~%# 3D Bounding box in world frame~%#      1 ------- 2~%#     /.        /|~%#    0 ------- 3 |~%#    | .       | |           ~%#    | 5.......| 6~%#    |.        |/       ~%#    4 ------- 7~%geometry_msgs/Point32[8] bbox_3d~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Point32~%# This contains the position of a point in free space(with 32 bits of precision).~%# It is recommeded to use Point wherever possible instead of Point32.  ~%# ~%# This recommendation is to promote interoperability.  ~%#~%# This message is designed to take up less space when sending~%# lots of points at once, as in the case of a PointCloud.  ~%~%float32 x~%float32 y~%float32 z~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'object_stamped)))
  "Returns full string definition for message of type 'object_stamped"
  (cl:format cl:nil "# Standard Header~%Header header~%~%# Object label~%string label~%~%# Object label ID~%int16 label_id~%~%# Object confidence level (1-99)~%float32 confidence~%~%# Object centroid~%geometry_msgs/Point32 position~%~%# Object velocity~%geometry_msgs/Vector3 linear_vel~%~%# Tracking state~%# 0 -> OFF (object not valid)~%# 1 -> OK~%# 2 -> SEARCHING (occlusion occurred, trajectory is estimated)~%int8 tracking_state ~%~%# 2D Bounding box projected to Camera image~%#      0 ------- 1~%#      |         |~%#      |         |~%#      |         |~%#      3 ------- 2~%geometry_msgs/Point32[4] bbox_2d~%~%# 3D Bounding box in world frame~%#      1 ------- 2~%#     /.        /|~%#    0 ------- 3 |~%#    | .       | |           ~%#    | 5.......| 6~%#    |.        |/       ~%#    4 ------- 7~%geometry_msgs/Point32[8] bbox_3d~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Point32~%# This contains the position of a point in free space(with 32 bits of precision).~%# It is recommeded to use Point wherever possible instead of Point32.  ~%# ~%# This recommendation is to promote interoperability.  ~%#~%# This message is designed to take up less space when sending~%# lots of points at once, as in the case of a PointCloud.  ~%~%float32 x~%float32 y~%float32 z~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <object_stamped>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4 (cl:length (cl:slot-value msg 'label))
     2
     4
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'position))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'linear_vel))
     1
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'bbox_2d) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'bbox_3d) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <object_stamped>))
  "Converts a ROS message object to a list"
  (cl:list 'object_stamped
    (cl:cons ':header (header msg))
    (cl:cons ':label (label msg))
    (cl:cons ':label_id (label_id msg))
    (cl:cons ':confidence (confidence msg))
    (cl:cons ':position (position msg))
    (cl:cons ':linear_vel (linear_vel msg))
    (cl:cons ':tracking_state (tracking_state msg))
    (cl:cons ':bbox_2d (bbox_2d msg))
    (cl:cons ':bbox_3d (bbox_3d msg))
))
