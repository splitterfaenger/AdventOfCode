add_executable(aoc_day3)

target_sources(aoc_day3 PRIVATE rucksack.cpp)

configure_file(rucksacks.txt ${CMAKE_CURRENT_BINARY_DIR}/rucksacks.txt COPYONLY)
configure_file(test.txt ${CMAKE_CURRENT_BINARY_DIR}/test.txt COPYONLY)
