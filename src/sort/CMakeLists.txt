add_library(
    dature_sort
    STATIC
    basic_sort.cpp
)

target_include_directories(dature_sort PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)

set(ALL_OBJECT_FILES
    ${ALL_OBJECT_FILES} $<TARGET_OBJECTS:dature_sort>
    PARENT_SCOPE)
