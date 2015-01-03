cmake_minimum_required (VERSION 2.8)
project (DSynkant)

find_package (PkgConfig 0.16 REQUIRED)
pkg_check_modules(DSSI REQUIRED dssi>=1.0)

# uncomment to be in Release mode [default]
# set(CMAKE_BUILD_TYPE Release)

# uncomment to build in debug mode
# set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_FLAGS "-std=gnu++0x")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -g0")

add_subdirectory(src)
