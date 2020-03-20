
(cl:in-package :asdf)

(defsystem "zed_interfaces-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
               :std_msgs-msg
)
  :components ((:file "_package")
    (:file "object_stamped" :depends-on ("_package_object_stamped"))
    (:file "_package_object_stamped" :depends-on ("_package"))
    (:file "objects" :depends-on ("_package_objects"))
    (:file "_package_objects" :depends-on ("_package"))
  ))