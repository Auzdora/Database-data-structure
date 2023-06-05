add_library(
    dature_hash
    STATIC
    extendible_hash_table.cpp
)

target_include_directories(dature_hash PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)

set(ALL_OBJECT_FILES
    ${ALL_OBJECT_FILES} $<TARGET_OBJECTS:dature_hash>
    PARENT_SCOPE)
