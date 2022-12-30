#-----------------------------------------------------------------#
# Setup                                                           #
#-----------------------------------------------------------------#

cmake_minimum_required(VERSION 3.13...3.22 FATAL_ERROR)

project(gaviota VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#-----------------------------------------------------------------#
# OS dependecies                                                  #
#-----------------------------------------------------------------#

if(UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif()

if(LINUX)
    message(STATUS "Linux OS build")
    # if required in the future
    # set(ADITIONAL_LIBRARIES "")

elseif(WIN32 OR MSVC OR MSYS OR MINGW)
    message(STATUS "Windows OS build")
    # if required in the future
    # set(ADITIONAL_LIBRARIES "")

elseif(APPLE)
    message(STATUS "Mac OS build")
    # if required in the future
    # set(ADITIONAL_LIBRARIES "")

else()
    message(STATUS "OS not supported")
endif()

#-----------------------------------------------------------------#
# Libraries                                                       #
#-----------------------------------------------------------------#

set(INCLUDE_DIRS
    "${CMAKE_SOURCE_DIR}/third_party/spdlog/include")

set(LOCAL_INCLUDE_DIRS
    "${CMAKE_SOURCE_DIR}/gaviota/core"
    "${CMAKE_SOURCE_DIR}/gaviota/core/managers")

include_directories(${LOCAL_INCLUDE_DIRS} ${LOCAL_INCLUDE})

#-----------------------------------------------------------------#
# Source files                                                    #
#-----------------------------------------------------------------#

set(SOURCE_FILES
    "${CMAKE_SOURCE_DIR}/gaviota/gaviota.cpp"
    "${CMAKE_SOURCE_DIR}/gaviota/core/application.cpp")

add_executable(gaviota ${SOURCE_FILES})

target_include_directories(gaviota PRIVATE ${LOCAL_INCLUDE_DIRS} ${INCLUDE_DIRS})