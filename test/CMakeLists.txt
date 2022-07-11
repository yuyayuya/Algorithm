add_executable(test_algorithm test_algorithm.cpp
    sort/test_sort.cpp
    tree/test_tree.cpp)

find_package(GTest REQUIRED)
target_link_libraries(test_algorithm GTest::GTest GTest::Main)
target_include_directories(test_algorithm PUBLIC
    ${PROJECT_SOURCE_DIR}/include
    ./sort
    ./tree
)