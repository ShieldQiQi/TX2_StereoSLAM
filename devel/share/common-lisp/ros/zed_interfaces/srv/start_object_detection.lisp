; Auto-generated. Do not edit!


(cl:in-package zed_interfaces-srv)


;//! \htmlinclude start_object_detection-request.msg.html

(cl:defclass <start_object_detection-request> (roslisp-msg-protocol:ros-message)
  ((confidence
    :reader confidence
    :initarg :confidence
    :type cl:float
    :initform 0.0)
   (tracking
    :reader tracking
    :initarg :tracking
    :type cl:boolean
    :initform cl:nil)
   (people
    :reader people
    :initarg :people
    :type cl:boolean
    :initform cl:nil)
   (vehicles
    :reader vehicles
    :initarg :vehicles
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass start_object_detection-request (<start_object_detection-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <start_object_detection-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'start_object_detection-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name zed_interfaces-srv:<start_object_detection-request> is deprecated: use zed_interfaces-srv:start_object_detection-request instead.")))

(cl:ensure-generic-function 'confidence-val :lambda-list '(m))
(cl:defmethod confidence-val ((m <start_object_detection-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader zed_interfaces-srv:confidence-val is deprecated.  Use zed_interfaces-srv:confidence instead.")
  (confidence m))

(cl:ensure-generic-function 'tracking-val :lambda-list '(m))
(cl:defmethod tracking-val ((m <start_object_detection-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader zed_interfaces-srv:tracking-val is deprecated.  Use zed_interfaces-srv:tracking instead.")
  (tracking m))

(cl:ensure-generic-function 'people-val :lambda-list '(m))
(cl:defmethod people-val ((m <start_object_detection-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader zed_interfaces-srv:people-val is deprecated.  Use zed_interfaces-srv:people instead.")
  (people m))

(cl:ensure-generic-function 'vehicles-val :lambda-list '(m))
(cl:defmethod vehicles-val ((m <start_object_detection-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader zed_interfaces-srv:vehicles-val is deprecated.  Use zed_interfaces-srv:vehicles instead.")
  (vehicles m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <start_object_detection-request>) ostream)
  "Serializes a message object of type '<start_object_detection-request>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'confidence))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'tracking) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'people) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'vehicles) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <start_object_detection-request>) istream)
  "Deserializes a message object of type '<start_object_detection-request>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'confidence) (roslisp-utils:decode-single-float-bits bits)))
    (cl:setf (cl:slot-value msg 'tracking) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'people) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'vehicles) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<start_object_detection-request>)))
  "Returns string type for a service object of type '<start_object_detection-request>"
  "zed_interfaces/start_object_detectionRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'start_object_detection-request)))
  "Returns string type for a service object of type 'start_object_detection-request"
  "zed_interfaces/start_object_detectionRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<start_object_detection-request>)))
  "Returns md5sum for a message object of type '<start_object_detection-request>"
  "3dc3fed99897ebf70695916b3c7b7cdd")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'start_object_detection-request)))
  "Returns md5sum for a message object of type 'start_object_detection-request"
  "3dc3fed99897ebf70695916b3c7b7cdd")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<start_object_detection-request>)))
  "Returns full string definition for message of type '<start_object_detection-request>"
  (cl:format cl:nil "~%~%~%float32 confidence~%~%~%bool tracking~%~%~%bool people~%~%~%bool vehicles~%~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'start_object_detection-request)))
  "Returns full string definition for message of type 'start_object_detection-request"
  (cl:format cl:nil "~%~%~%float32 confidence~%~%~%bool tracking~%~%~%bool people~%~%~%bool vehicles~%~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <start_object_detection-request>))
  (cl:+ 0
     4
     1
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <start_object_detection-request>))
  "Converts a ROS message object to a list"
  (cl:list 'start_object_detection-request
    (cl:cons ':confidence (confidence msg))
    (cl:cons ':tracking (tracking msg))
    (cl:cons ':people (people msg))
    (cl:cons ':vehicles (vehicles msg))
))
;//! \htmlinclude start_object_detection-response.msg.html

(cl:defclass <start_object_detection-response> (roslisp-msg-protocol:ros-message)
  ((done
    :reader done
    :initarg :done
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass start_object_detection-response (<start_object_detection-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <start_object_detection-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'start_object_detection-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name zed_interfaces-srv:<start_object_detection-response> is deprecated: use zed_interfaces-srv:start_object_detection-response instead.")))

(cl:ensure-generic-function 'done-val :lambda-list '(m))
(cl:defmethod done-val ((m <start_object_detection-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader zed_interfaces-srv:done-val is deprecated.  Use zed_interfaces-srv:done instead.")
  (done m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <start_object_detection-response>) ostream)
  "Serializes a message object of type '<start_object_detection-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'done) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <start_object_detection-response>) istream)
  "Deserializes a message object of type '<start_object_detection-response>"
    (cl:setf (cl:slot-value msg 'done) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<start_object_detection-response>)))
  "Returns string type for a service object of type '<start_object_detection-response>"
  "zed_interfaces/start_object_detectionResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'start_object_detection-response)))
  "Returns string type for a service object of type 'start_object_detection-response"
  "zed_interfaces/start_object_detectionResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<start_object_detection-response>)))
  "Returns md5sum for a message object of type '<start_object_detection-response>"
  "3dc3fed99897ebf70695916b3c7b7cdd")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'start_object_detection-response)))
  "Returns md5sum for a message object of type 'start_object_detection-response"
  "3dc3fed99897ebf70695916b3c7b7cdd")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<start_object_detection-response>)))
  "Returns full string definition for message of type '<start_object_detection-response>"
  (cl:format cl:nil "bool done~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'start_object_detection-response)))
  "Returns full string definition for message of type 'start_object_detection-response"
  (cl:format cl:nil "bool done~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <start_object_detection-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <start_object_detection-response>))
  "Converts a ROS message object to a list"
  (cl:list 'start_object_detection-response
    (cl:cons ':done (done msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'start_object_detection)))
  'start_object_detection-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'start_object_detection)))
  'start_object_detection-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'start_object_detection)))
  "Returns string type for a service object of type '<start_object_detection>"
  "zed_interfaces/start_object_detection")