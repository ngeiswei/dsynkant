cmake_minimum_required (VERSION 2.8)
project (DSynkant)

# Print pretty summary
include(Summary.cmake)

find_package (Boost 1.46 REQUIRED)
find_package (PkgConfig 0.16 REQUIRED)
pkg_check_modules(DSSI dssi>=1.0)

# uncomment to be in Release mode [default]
# set(CMAKE_BUILD_TYPE Release)

# uncomment to build in debug mode
# set(CMAKE_BUILD_TYPE Debug)

# default build type
IF (CMAKE_BUILD_TYPE STREQUAL "")
	SET(CMAKE_BUILD_TYPE Release)
ENDIF (CMAKE_BUILD_TYPE STREQUAL "")

set(CMAKE_CXX_FLAGS "-std=gnu++0x")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -g0")

if(Boost_FOUND)
  set(HAVE_DSYNKANT 1)
endif(Boost_FOUND)

if(HAVE_DSYNKANT AND DSSI_FOUND)
  set(HAVE_DSSI 1)
endif(HAVE_DSYNKANT AND DSSI_FOUND)

add_subdirectory(src)

summary_add("DSynkant" "Library of DSynkant" HAVE_DSYNKANT)
summary_add("DSynkant-DSSI" "DSSI plugin of DSynkant" HAVE_DSSI)
summary_add("DSynkant-VST" "VST plugin of DSynkant" HAVE_VST)
summary_show()
