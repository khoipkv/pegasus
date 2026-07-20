project(Pegasus)

file(GLOB SOURCES "${CMAKE_CURRENT_LIST_DIR}/*.cpp")
add_library(rvzvfbfmin
    OBJECT
    ${SOURCES}
)
add_dependencies(rvzvfbfmin AutogenArchFiles)
target_link_libraries(rvzvfbfmin PUBLIC pegasuslibs)
