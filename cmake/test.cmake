
find_package(GTest CONFIG REQUIRED)

set(TEST_NAME Footest)
set(TEST_SOURCE 
    ${CMAKE_SOURCE_DIR}/test/test_solid_principles.cpp
    ${CMAKE_SOURCE_DIR}/src/solid_principles/intro.cpp
    )
add_executable(${TEST_NAME} ${TEST_SOURCE})

target_link_libraries(${TEST_NAME} GTest::gtest)
add_test("${TEST_NAME}_42" ${TEST_NAME})