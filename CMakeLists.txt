cmake_minimum_required(VERSION 3.8)
project(randbot)
set(TARGET ${CMAKE_PROJECT_NAME})
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Ofast")

find_package(Qt5Core REQUIRED)

find_package(Boost 1.67.0 REQUIRED COMPONENTS thread system)
include_directories(${Boost_INCLUDE_DIRS})

find_package(OpenSSL REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/lib/libtelegram/include)

file(GLOB randbot_SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_executable(${TARGET} ${randbot_SOURCES})

target_link_libraries(${TARGET} ${Boost_LIBRARIES} ${OPENSSL_LIBRARIES})
