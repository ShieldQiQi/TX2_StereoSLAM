;; Auto-generated. Do not edit!


(when (boundp 'zed_interfaces::start_object_detection)
  (if (not (find-package "ZED_INTERFACES"))
    (make-package "ZED_INTERFACES"))
  (shadow 'start_object_detection (find-package "ZED_INTERFACES")))
(unless (find-package "ZED_INTERFACES::START_OBJECT_DETECTION")
  (make-package "ZED_INTERFACES::START_OBJECT_DETECTION"))
(unless (find-package "ZED_INTERFACES::START_OBJECT_DETECTIONREQUEST")
  (make-package "ZED_INTERFACES::START_OBJECT_DETECTIONREQUEST"))
(unless (find-package "ZED_INTERFACES::START_OBJECT_DETECTIONRESPONSE")
  (make-package "ZED_INTERFACES::START_OBJECT_DETECTIONRESPONSE"))

(in-package "ROS")





(defclass zed_interfaces::start_object_detectionRequest
  :super ros::object
  :slots (_confidence _tracking _people _vehicles ))

(defmethod zed_interfaces::start_object_detectionRequest
  (:init
   (&key
    ((:confidence __confidence) 0.0)
    ((:tracking __tracking) nil)
    ((:people __people) nil)
    ((:vehicles __vehicles) nil)
    )
   (send-super :init)
   (setq _confidence (float __confidence))
   (setq _tracking __tracking)
   (setq _people __people)
   (setq _vehicles __vehicles)
   self)
  (:confidence
   (&optional __confidence)
   (if __confidence (setq _confidence __confidence)) _confidence)
  (:tracking
   (&optional __tracking)
   (if __tracking (setq _tracking __tracking)) _tracking)
  (:people
   (&optional __people)
   (if __people (setq _people __people)) _people)
  (:vehicles
   (&optional __vehicles)
   (if __vehicles (setq _vehicles __vehicles)) _vehicles)
  (:serialization-length
   ()
   (+
    ;; float32 _confidence
    4
    ;; bool _tracking
    1
    ;; bool _people
    1
    ;; bool _vehicles
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _confidence
       (sys::poke _confidence (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; bool _tracking
       (if _tracking (write-byte -1 s) (write-byte 0 s))
     ;; bool _people
       (if _people (write-byte -1 s) (write-byte 0 s))
     ;; bool _vehicles
       (if _vehicles (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _confidence
     (setq _confidence (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; bool _tracking
     (setq _tracking (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _people
     (setq _people (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _vehicles
     (setq _vehicles (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass zed_interfaces::start_object_detectionResponse
  :super ros::object
  :slots (_done ))

(defmethod zed_interfaces::start_object_detectionResponse
  (:init
   (&key
    ((:done __done) nil)
    )
   (send-super :init)
   (setq _done __done)
   self)
  (:done
   (&optional __done)
   (if __done (setq _done __done)) _done)
  (:serialization-length
   ()
   (+
    ;; bool _done
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _done
       (if _done (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _done
     (setq _done (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass zed_interfaces::start_object_detection
  :super ros::object
  :slots ())

(setf (get zed_interfaces::start_object_detection :md5sum-) "3dc3fed99897ebf70695916b3c7b7cdd")
(setf (get zed_interfaces::start_object_detection :datatype-) "zed_interfaces/start_object_detection")
(setf (get zed_interfaces::start_object_detection :request) zed_interfaces::start_object_detectionRequest)
(setf (get zed_interfaces::start_object_detection :response) zed_interfaces::start_object_detectionResponse)

(defmethod zed_interfaces::start_object_detectionRequest
  (:response () (instance zed_interfaces::start_object_detectionResponse :init)))

(setf (get zed_interfaces::start_object_detectionRequest :md5sum-) "3dc3fed99897ebf70695916b3c7b7cdd")
(setf (get zed_interfaces::start_object_detectionRequest :datatype-) "zed_interfaces/start_object_detectionRequest")
(setf (get zed_interfaces::start_object_detectionRequest :definition-)
      "


float32 confidence


bool tracking


bool people


bool vehicles



---
bool done

")

(setf (get zed_interfaces::start_object_detectionResponse :md5sum-) "3dc3fed99897ebf70695916b3c7b7cdd")
(setf (get zed_interfaces::start_object_detectionResponse :datatype-) "zed_interfaces/start_object_detectionResponse")
(setf (get zed_interfaces::start_object_detectionResponse :definition-)
      "


float32 confidence


bool tracking


bool people


bool vehicles



---
bool done

")



(provide :zed_interfaces/start_object_detection "3dc3fed99897ebf70695916b3c7b7cdd")


