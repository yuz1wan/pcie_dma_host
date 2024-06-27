add_library(
    _DRIVER
    "${CMAKE_CURRENT_SOURCE_DIR}/config_gui.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/host_driver.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/host_driver.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/audio_dma.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/audio_dma.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/wave.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/wave.h"
)

target_link_libraries(
    _DRIVER
    PUBLIC _INFERENCE
)

target_include_directories(
    _DRIVER 
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}"
)