# DSynkant
add_subdirectory(dsynkant)

# DSSI plugin
if (HAVE_DSSI)
  add_library(dsynkant-dssi SHARED
    dssidsynkant)

  target_link_libraries(dsynkant-dssi
    dsynkant
    dssiplugin)

  add_subdirectory(dssi)

  add_custom_command(TARGET dsynkant-dssi POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    $<TARGET_FILE:dsynkant-dssi>
    ../dsynkant-dssi.so)

  install(FILES ${CMAKE_BINARY_DIR}/dsynkant-dssi.so DESTINATION lib/dssi)
endif (HAVE_DSSI)

# VST plugin
if (HAVE_VST)
  include_directories("${PROJECT_SOURCE_DIR}/VST3 SDK")

  target_link_libraries(dsynkant-dssi
    dsynkant
    TODO: add VST library link to have AudioEffectX and the like defined)

  add_library(dsynkant-vst SHARED
    vstdsynkant)
endif (HAVE_VST)
