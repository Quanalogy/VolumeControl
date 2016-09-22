cmake_minimum_required(VERSION 3.6)
project(VolumeControl)
find_package(ALSA)
if(NOT ALSA_LIBRARY)
    message(STATUS "Installing libasound2-dev")
    EXEC_PROGRAM("sudo apt-get install -y libasound2-dev")
endif(NOT ALSA_LIBRARY)
find_package(ALSA)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


set(SOURCE_FILES main.cpp)
add_executable(VolumeControl ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${ALSA_LIBRARY})
