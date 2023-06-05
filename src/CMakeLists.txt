add_subdirectory(hash)
add_subdirectory(sort)
add_library(dature STATIC ${ALL_OBJECT_FILES})

target_include_directories(
    dature PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    # $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)