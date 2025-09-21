cmake_minimum_required(VERSION 3.21)
project(SFMLExample)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 3 REQUIRED COMPONENTS Graphics Audio Network)
find_library(COCOA_FRAMEWORK Cocoa)
find_library(IOKIT_FRAMEWORK IOKit)
find_library(COREFOUNDATION_FRAMEWORK CoreFoundation)

add_library(rignis-engine STATIC src/engine_configuration.cpp src/engine.cpp src/entity.cpp src/screen.cpp)

target_include_directories(rignis-engine
    PUBLIC # <- makes headers available to users of MyLib
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Link SFML
target_link_libraries(rignis-engine PRIVATE
    SFML::Graphics
    SFML::Audio
    SFML::Network
    ${COCOA_FRAMEWORK}
    ${IOKIT_FRAMEWORK}
    ${COREFOUNDATION_FRAMEWORK})
