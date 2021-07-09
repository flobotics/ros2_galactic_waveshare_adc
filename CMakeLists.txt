cmake_minimum_required(VERSION 3.8)
project(ros2_galactic_waveshare_adc C CXX)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic -lpthread -lm -lwiringPi -ltest_lib -lros2_galactic_waveshare_adc_lib -L/home/ros2/dev_ws/install/test_lib/lib/ -I/home/ros2/dev_ws/install/test_lib/include) 
endif()

add_compile_options(-Wall -Wextra -Wpedantic -lpthread -lm -lwiringPi -ltest_lib -lros2_galactic_waveshare_adc_lib -L/home/ros2/dev_ws/install/test_lib/lib/ -I/home/ros2/dev_ws/install/test_lib/include)

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(ros2_galactic_waveshare_adc_interfaces REQUIRED)
find_package(ros2_galactic_waveshare_adc_lib CONFIG REQUIRED)
find_package(test_lib REQUIRED)
								
add_executable(ros2_galactic_waveshare_adc_node
				src/ros2_galactic_waveshare_adc_node.cpp
				src/ADS1256.c
				src/DEV_Config.c
				)
				

include_directories(../include)

#find_library(DRIVER NAMES test_lib)
#find_path(HEADERS NAMES test_lib.h HINTS ${AMENT_PREFIX_PATH})

target_include_directories(ros2_galactic_waveshare_adc_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)

#find_library(WIRINGPI_LIBRARIES NAMES wiringPi)
#target_link_libraries(OpenInsulin ${WIRINGPI_LIBRARIES})

#add_library(test_lib SHARED IMPORTED)
#set_property(TARGET test_lib PROPERTY IMPORTED_LOCATION "/home/ros2/dev_ws/install/test_lib/lib/libtest_lib.so")

			
								
ament_target_dependencies(ros2_galactic_waveshare_adc_node
							rclcpp 
							std_msgs 
							ros2_galactic_waveshare_adc_interfaces
							)
							
target_link_libraries(ros2_galactic_waveshare_adc_node
						wiringPi)
						
ament_export_dependencies(ros2_galactic_waveshare_adc_node)

target_compile_features(ros2_galactic_waveshare_adc_node PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17

install(TARGETS ros2_galactic_waveshare_adc_node
  DESTINATION ${PROJECT_NAME})

ament_package()
