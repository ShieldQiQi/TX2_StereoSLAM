
(cl:in-package :asdf)

(defsystem "qt_tutorials-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "TwoInts" :depends-on ("_package_TwoInts"))
    (:file "_package_TwoInts" :depends-on ("_package"))
  ))