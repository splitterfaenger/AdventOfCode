add_executable(aoc_day2)

target_sources(aoc_day2 PRIVATE rock_paper_scissor.cpp)

configure_file(rock_paper_scissor_results.txt ${CMAKE_CURRENT_BINARY_DIR}/rock_paper_scissor_results.txt COPYONLY)
