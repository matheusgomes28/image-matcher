find_package(OpenCV REQUIRED COMPONENTS core highgui imgproc)
find_package(fmt REQUIRED)

add_executable(matching_app main.cpp)

target_link_libraries(matching_app
 PRIVATE
  fmt::fmt
  opencv::core
  opencv::highgui
  opencv::imgproc)

install(TARGETS matching_app RUNTIME DESTINATION bin)
