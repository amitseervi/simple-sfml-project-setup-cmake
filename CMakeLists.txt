cmake_minimum_required(VERSION 3.21)
project(SFMLExample)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 3 REQUIRED COMPONENTS Graphics Audio Network)
find_library(COCOA_FRAMEWORK Cocoa)
find_library(IOKIT_FRAMEWORK IOKit)
find_library(COREFOUNDATION_FRAMEWORK CoreFoundation)


# Tell CMake where SFML is installed (adjust path if needed)
# SFML paths
# set(SFML_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/external/SFML/include")
# set(SFML_LIB_DIR "${CMAKE_SOURCE_DIR}/external/SFML/build/lib")

# Add SFML include and library dirs
# include_directories(${SFML_INCLUDE_DIR})
# link_directories(${SFML_LIB_DIR})

add_executable(sfml-app main.cpp)

# Link SFML
target_link_libraries(sfml-app PRIVATE
    SFML::Graphics
    SFML::Audio
    SFML::Network
    ${COCOA_FRAMEWORK}
    ${IOKIT_FRAMEWORK}
    ${COREFOUNDATION_FRAMEWORK})
