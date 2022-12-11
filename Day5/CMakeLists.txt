add_executable(aoc_day5)

target_sources(aoc_day5 PRIVATE supply_stacks.cpp)

configure_file(stacks_of_crates.txt ${CMAKE_CURRENT_BINARY_DIR}/stacks_of_crates.txt COPYONLY)
configure_file(test.txt ${CMAKE_CURRENT_BINARY_DIR}/test.txt COPYONLY)