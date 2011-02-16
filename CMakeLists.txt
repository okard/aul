############################################
# CMake File for Audio Utility Library aul
############################################
cmake_minimum_required(VERSION 2.8) 

project(aul)

#include dirs
include_directories(src)
include_directories(include)

#Setup Libraries
find_package(OpenAL REQUIRED)

# Library
add_library(aul SHARED
            src/Device.cpp
            src/Source.cpp
            src/Stream.cpp
            src/ogg/OggStream.cpp)

#todo fix lib linking
target_link_libraries(aul ${OPENAL_LIBRARY} "ogg" "vorbis" "vorbisfile")

#tests
add_subdirectory(tests)
