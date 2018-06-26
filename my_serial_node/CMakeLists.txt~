cmake_minimum_required(VERSION 2.8.3)
project( my_serial_node )

# Find catkin
 find_package(catkin REQUIRED COMPONENTS
    roscpp
    serial
    std_msgs
    actionlib
    move_base_msgs 
    tf
    )
 
 catkin_package(
   CATKIN_DEPENDS
     serial
     std_msgs
    INCLUDE_DIRS include
 )
#增加自定义头文件
  include_directories(
  ${catkin_INCLUDE_DIRS}
  include/my_serial_node

 )
 
 
 set(serial_SRCS
      src/crc.cpp 
    include/my_serial_node/crc.h
   include/my_serial_node/global.h
)
 #增加静态库
     add_library(${PROJECT_NAME} ${serial_SRCS}
       )
  
  
add_executable( myserialnode src/myserialnode.cpp )
target_link_libraries( myserialnode  
					${catkin_LIBRARIES} 
					${PROJECT_NAME}
				  )

add_executable(talker src/talker.cpp)
target_link_libraries(talker ${catkin_LIBRARIES} ${PROJECT_NAME})

add_executable(listener src/listener.cpp)
target_link_libraries(listener ${catkin_LIBRARIES} ${PROJECT_NAME})

add_executable(listen_cmd src/listen_cmd.cpp)
target_link_libraries(listen_cmd ${catkin_LIBRARIES} ${PROJECT_NAME})

add_executable(movebase_goal src/movebase_goal.cpp)
target_link_libraries(movebase_goal ${catkin_LIBRARIES} ${PROJECT_NAME})
