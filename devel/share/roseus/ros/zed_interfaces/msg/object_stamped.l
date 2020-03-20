;; Auto-generated. Do not edit!


(when (boundp 'zed_interfaces::object_stamped)
  (if (not (find-package "ZED_INTERFACES"))
    (make-package "ZED_INTERFACES"))
  (shadow 'object_stamped (find-package "ZED_INTERFACES")))
(unless (find-package "ZED_INTERFACES::OBJECT_STAMPED")
  (make-package "ZED_INTERFACES::OBJECT_STAMPED"))

(in-package "ROS")
;;//! \htmlinclude object_stamped.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass zed_interfaces::object_stamped
  :super ros::object
  :slots (_header _label _label_id _confidence _position _linear_vel _tracking_state _bbox_2d _bbox_3d ))

(defmethod zed_interfaces::object_stamped
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:label __label) "")
    ((:label_id __label_id) 0)
    ((:confidence __confidence) 0.0)
    ((:position __position) (instance geometry_msgs::Point32 :init))
    ((:linear_vel __linear_vel) (instance geometry_msgs::Vector3 :init))
    ((:tracking_state __tracking_state) 0)
    ((:bbox_2d __bbox_2d) (let (r) (dotimes (i 4) (push (instance geometry_msgs::Point32 :init) r)) r))
    ((:bbox_3d __bbox_3d) (let (r) (dotimes (i 8) (push (instance geometry_msgs::Point32 :init) r)) r))
    )
   (send-super :init)
   (setq _header __header)
   (setq _label (string __label))
   (setq _label_id (round __label_id))
   (setq _confidence (float __confidence))
   (setq _position __position)
   (setq _linear_vel __linear_vel)
   (setq _tracking_state (round __tracking_state))
   (setq _bbox_2d __bbox_2d)
   (setq _bbox_3d __bbox_3d)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:label
   (&optional __label)
   (if __label (setq _label __label)) _label)
  (:label_id
   (&optional __label_id)
   (if __label_id (setq _label_id __label_id)) _label_id)
  (:confidence
   (&optional __confidence)
   (if __confidence (setq _confidence __confidence)) _confidence)
  (:position
   (&rest __position)
   (if (keywordp (car __position))
       (send* _position __position)
     (progn
       (if __position (setq _position (car __position)))
       _position)))
  (:linear_vel
   (&rest __linear_vel)
   (if (keywordp (car __linear_vel))
       (send* _linear_vel __linear_vel)
     (progn
       (if __linear_vel (setq _linear_vel (car __linear_vel)))
       _linear_vel)))
  (:tracking_state
   (&optional __tracking_state)
   (if __tracking_state (setq _tracking_state __tracking_state)) _tracking_state)
  (:bbox_2d
   (&rest __bbox_2d)
   (if (keywordp (car __bbox_2d))
       (send* _bbox_2d __bbox_2d)
     (progn
       (if __bbox_2d (setq _bbox_2d (car __bbox_2d)))
       _bbox_2d)))
  (:bbox_3d
   (&rest __bbox_3d)
   (if (keywordp (car __bbox_3d))
       (send* _bbox_3d __bbox_3d)
     (progn
       (if __bbox_3d (setq _bbox_3d (car __bbox_3d)))
       _bbox_3d)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; string _label
    4 (length _label)
    ;; int16 _label_id
    2
    ;; float32 _confidence
    4
    ;; geometry_msgs/Point32 _position
    (send _position :serialization-length)
    ;; geometry_msgs/Vector3 _linear_vel
    (send _linear_vel :serialization-length)
    ;; int8 _tracking_state
    1
    ;; geometry_msgs/Point32[4] _bbox_2d
    (apply #'+ (send-all _bbox_2d :serialization-length))
    ;; geometry_msgs/Point32[8] _bbox_3d
    (apply #'+ (send-all _bbox_3d :serialization-length))
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; string _label
       (write-long (length _label) s) (princ _label s)
     ;; int16 _label_id
       (write-word _label_id s)
     ;; float32 _confidence
       (sys::poke _confidence (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; geometry_msgs/Point32 _position
       (send _position :serialize s)
     ;; geometry_msgs/Vector3 _linear_vel
       (send _linear_vel :serialize s)
     ;; int8 _tracking_state
       (write-byte _tracking_state s)
     ;; geometry_msgs/Point32[4] _bbox_2d
     (dolist (elem _bbox_2d)
       (send elem :serialize s)
       )
     ;; geometry_msgs/Point32[8] _bbox_3d
     (dolist (elem _bbox_3d)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; string _label
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _label (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; int16 _label_id
     (setq _label_id (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; float32 _confidence
     (setq _confidence (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; geometry_msgs/Point32 _position
     (send _position :deserialize buf ptr-) (incf ptr- (send _position :serialization-length))
   ;; geometry_msgs/Vector3 _linear_vel
     (send _linear_vel :deserialize buf ptr-) (incf ptr- (send _linear_vel :serialization-length))
   ;; int8 _tracking_state
     (setq _tracking_state (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _tracking_state 127) (setq _tracking_state (- _tracking_state 256)))
   ;; geometry_msgs/Point32[4] _bbox_2d
   (dotimes (i 4)
     (send (elt _bbox_2d i) :deserialize buf ptr-) (incf ptr- (send (elt _bbox_2d i) :serialization-length))
     )
   ;; geometry_msgs/Point32[8] _bbox_3d
   (dotimes (i 8)
     (send (elt _bbox_3d i) :deserialize buf ptr-) (incf ptr- (send (elt _bbox_3d i) :serialization-length))
     )
   ;;
   self)
  )

(setf (get zed_interfaces::object_stamped :md5sum-) "d424656ac6d81bea041e4eb6457725ad")
(setf (get zed_interfaces::object_stamped :datatype-) "zed_interfaces/object_stamped")
(setf (get zed_interfaces::object_stamped :definition-)
      "# Standard Header
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
")



(provide :zed_interfaces/object_stamped "d424656ac6d81bea041e4eb6457725ad")


