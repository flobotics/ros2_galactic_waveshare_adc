cmake_minimum_required(VERSION 3.8)
project(ros2_galactic_waveshare_adc C CXX)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic -lpthread -lm -lwiringPi -lADS1256) 
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(ros2_galactic_waveshare_adc_interfaces REQUIRED)

add_library(ADS1256 SHARED
			src/ADS1256.c
			include/ADS1256.h
			src/DEV_Config.c
			include/DEV_Config.h
			include/Debug.h)
			
								
add_executable(ros2_galactic_waveshare_adc_node 
				src/ros2_galactic_waveshare_adc_node.cpp)
				
target_link_libraries(ros2_galactic_waveshare_adc_node 
						ADS1256)			
								
ament_target_dependencies(ros2_galactic_waveshare_adc_node
							rclcpp 
							std_msgs 
							ros2_galactic_waveshare_adc_interfaces
							)

target_compile_features(ros2_galactic_waveshare_adc_node PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17

ament_package()
