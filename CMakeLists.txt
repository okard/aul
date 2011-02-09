############################################
# CMake File for Audio Utility Library aul
############################################
CMAKE_MINIMUM_REQUIRED(VERSION 2.8) 

PROJECT(aul)

#include dirs
INCLUDE_DIRECTORIES(src)
INCLUDE_DIRECTORIES(include)

# Library
ADD_LIBRARY(aul SHARED
            src/Device.cpp
            src/Source.cpp)

TARGET_LINK_LIBRARIES(aul "openal")

#tests
ADD_SUBDIRECTORY(tests)
