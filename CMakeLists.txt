cmake_minimum_required(VERSION 3.21)
project(ImageMatcher LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED On)
set(CMAKE_CXX_EXTENSIONS Off)

# Add our executables
add_subdirectory(src/matching_app)
