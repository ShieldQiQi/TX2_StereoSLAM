// Generated by gencpp from file zed_interfaces/stop_object_detectionResponse.msg
// DO NOT EDIT!


#ifndef ZED_INTERFACES_MESSAGE_STOP_OBJECT_DETECTIONRESPONSE_H
#define ZED_INTERFACES_MESSAGE_STOP_OBJECT_DETECTIONRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace zed_interfaces
{
template <class ContainerAllocator>
struct stop_object_detectionResponse_
{
  typedef stop_object_detectionResponse_<ContainerAllocator> Type;

  stop_object_detectionResponse_()
    : done(false)  {
    }
  stop_object_detectionResponse_(const ContainerAllocator& _alloc)
    : done(false)  {
  (void)_alloc;
    }



   typedef uint8_t _done_type;
  _done_type done;





  typedef boost::shared_ptr< ::zed_interfaces::stop_object_detectionResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::zed_interfaces::stop_object_detectionResponse_<ContainerAllocator> const> ConstPtr;

}; // struct stop_object_detectionResponse_

typedef ::zed_interfaces::stop_object_detectionResponse_<std::allocator<void> > stop_object_detectionResponse;

typedef boost::shared_ptr< ::zed_interfaces::stop_object_detectionResponse > stop_object_detectionResponsePtr;
typedef boost::shared_ptr< ::zed_interfaces::stop_object_detectionResponse const> stop_object_detectionResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::zed_interfaces::stop_object_detectionResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::zed_interfaces::stop_object_detectionResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace zed_interfaces

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'geometry_msgs': ['/opt/ros/melodic/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/melodic/share/std_msgs/cmake/../msg'], 'zed_interfaces': ['/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::zed_interfaces::stop_object_detectionResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::zed_interfaces::stop_object_detectionResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::zed_interfaces::stop_object_detectionResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::zed_interfaces::stop_object_detectionResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::zed_interfaces::stop_object_detectionResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::zed_interfaces::stop_object_detectionResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::zed_interfaces::stop_object_detectionResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "89bb254424e4cffedbf494e7b0ddbfea";
  }

  static const char* value(const ::zed_interfaces::stop_object_detectionResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x89bb254424e4cffeULL;
  static const uint64_t static_value2 = 0xdbf494e7b0ddbfeaULL;
};

template<class ContainerAllocator>
struct DataType< ::zed_interfaces::stop_object_detectionResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "zed_interfaces/stop_object_detectionResponse";
  }

  static const char* value(const ::zed_interfaces::stop_object_detectionResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::zed_interfaces::stop_object_detectionResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool done\n"
"\n"
;
  }

  static const char* value(const ::zed_interfaces::stop_object_detectionResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::zed_interfaces::stop_object_detectionResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.done);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct stop_object_detectionResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::zed_interfaces::stop_object_detectionResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::zed_interfaces::stop_object_detectionResponse_<ContainerAllocator>& v)
  {
    s << indent << "done: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.done);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ZED_INTERFACES_MESSAGE_STOP_OBJECT_DETECTIONRESPONSE_H
