cmake_minimum_required(VERSION 3.16)
project(EncryptionSuite)
list(PREPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include your headers
include_directories(include)

# Tell CMake where Qt cmake modules are
list(APPEND CMAKE_PREFIX_PATH "/opt/homebrew/opt/qt/lib/cmake")

# Find Qt
find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

# Collect sources
file(GLOB SOURCES "src/*.cpp")

# Create executable
add_executable(EncryptionSuite ${SOURCES})

# Link Qt libraries
target_link_libraries(EncryptionSuite
    PRIVATE
    Qt6::Core
    Qt6::Widgets
)