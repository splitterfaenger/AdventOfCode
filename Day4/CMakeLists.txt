add_executable(aoc_day4)

target_sources(aoc_day4 PRIVATE check_pairs.cpp)

configure_file(pairs.txt ${CMAKE_CURRENT_BINARY_DIR}/pairs.txt COPYONLY)
configure_file(test.txt ${CMAKE_CURRENT_BINARY_DIR}/test.txt COPYONLY)
configure_file(campcleaning_input.txt ${CMAKE_CURRENT_BINARY_DIR}/campcleaning_input.txt COPYONLY)