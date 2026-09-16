# Set minimum CMake version
cmake_minimum_required(VERSION "3.21")

# Configure project and languages
project(libwavebird LANGUAGES C)

# Add CTest for running tests
include(CTest)

# Define the library
add_library(wavebird INTERFACE)
target_sources(wavebird INTERFACE src/bch3121.c src/packet.c)

# Specify the include paths
target_include_directories(wavebird INTERFACE include)

# Add the radio platform, if one was requested
# The protocol implementation (packet decoding, error correction) has no platform dependencies,
# so building without a platform is supported (e.g. for host-side tools and tests)
if(DEFINED WAVEBIRD_PLATFORM_EFR32)
  add_subdirectory(src/platform/efr32)
endif()

# Add the test target
if(NOT CMAKE_CROSSCOMPILING)
  add_subdirectory(test)
endif()
