add_library(dsynkant-dssi SHARED
  dssidsynkant
  dssi/dssiplugin)
target_link_libraries(dsynkant-dssi dsynkant)

add_subdirectory(dsynkant)
