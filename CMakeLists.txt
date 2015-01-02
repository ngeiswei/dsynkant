cmake_minimum_required (VERSION 2.8)
project (DSynkant)

find_package (PkgConfig 0.16 REQUIRED)
pkg_check_modules(DSSI REQUIRED dssi>=1.0)

add_subdirectory(src)
