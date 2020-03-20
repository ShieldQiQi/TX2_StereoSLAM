;; Auto-generated. Do not edit!


(when (boundp 'zed_interfaces::objects)
  (if (not (find-package "ZED_INTERFACES"))
    (make-package "ZED_INTERFACES"))
  (shadow 'objects (find-package "ZED_INTERFACES")))
(unless (find-package "ZED_INTERFACES::OBJECTS")
  (make-package "ZED_INTERFACES::OBJECTS"))

(in-package "ROS")
;;//! \htmlinclude objects.msg.html


(defclass zed_interfaces::objects
  :super ros::object
  :slots (_objects ))

(defmethod zed_interfaces::objects
  (:init
   (&key
    ((:objects __objects) (let (r) (dotimes (i 0) (push (instance zed_interfaces::object_stamped :init) r)) r))
    )
   (send-super :init)
   (setq _objects __objects)
   self)
  (:objects
   (&rest __objects)
   (if (keywordp (car __objects))
       (send* _objects __objects)
     (progn
       (if __objects (setq _objects (car __objects)))
       _objects)))
  (:serialization-length
   ()
   (+
    ;; zed_interfaces/object_stamped[] _objects
    (apply #'+ (send-all _objects :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; zed_interfaces/object_stamped[] _objects
     (write-long (length _objects) s)
     (dolist (elem _objects)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; zed_interfaces/object_stamped[] _objects
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _objects (let (r) (dotimes (i n) (push (instance zed_interfaces::object_stamped :init) r)) r))
     (dolist (elem- _objects)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get zed_interfaces::objects :md5sum-) "f74a9cc2a8c886c042be0d913eabb9fd")
(setf (get zed_interfaces::objects :datatype-) "zed_interfaces/objects")
(setf (get zed_interfaces::objects :definition-)
      "# Array of `object_stamped` topics
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
")



(provide :zed_interfaces/objects "f74a9cc2a8c886c042be0d913eabb9fd")


