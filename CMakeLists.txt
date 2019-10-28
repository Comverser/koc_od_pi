cmake_minimum_required (VERSION 3.5)

project(koc_od_pi)

set(CMAKE_BUILD_TYPE Debug)
#set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK REQUIRED gtk+-3.0)

include_directories(${PROJECT_SOURCE_DIR}/src/libs)
include_directories(${GTK_INCLUDE_DIRS})
link_directories(${GTK_LIBRARY_DIRS})

file(GLOB SOURCES_APPS "src/apps/*.cpp")
file(GLOB SOURCES_LIBS "src/libs/*.cpp")

add_executable(demo ${SOURCES_APPS} ${SOURCES_LIBS})

add_definitions(${GTK_CFLAGS_OTHER})

find_library(wiringPi_LIB wiringPi)

target_link_libraries(demo ${wiringPi_LIB} ${GTK_LIBRARIES})
