add_executable(aoc_day1)

target_sources(aoc_day1 PRIVATE calorie_counter.cpp)

configure_file(calories.txt ${CMAKE_CURRENT_BINARY_DIR}/calories.txt COPYONLY)
