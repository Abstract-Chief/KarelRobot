# set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/doc/examples)

# include_directories(../../include)

add_executable(stairs stairs.c)
target_link_libraries(stairs LINK_PUBLIC karel)
set_property(TARGET stairs PROPERTY CXX_STANDARD 11)


add_executable(training training.c)
target_link_libraries(training LINK_PUBLIC karel)
set_property(TARGET training PROPERTY CXX_STANDARD 11)
