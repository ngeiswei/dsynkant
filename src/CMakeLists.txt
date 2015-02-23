add_library(dsynkant-dssi SHARED
  dssidsynkant)

target_link_libraries(dsynkant-dssi
  dsynkant
  dssiplugin)

add_library(dsynkant-vst SHARED
  vstdsynkant)

add_subdirectory(dsynkant)
add_subdirectory(dssi)

add_custom_command(TARGET dsynkant-dssi POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  $<TARGET_FILE:dsynkant-dssi>
  ../dsynkant-dssi.so)

install(FILES ${CMAKE_BINARY_DIR}/dsynkant-dssi.so DESTINATION lib/dssi)
