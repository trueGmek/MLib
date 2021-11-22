cmake_minimum_required(VERSION 3.20)
project(MLibExe)

set(CMAKE_CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED TRUE)

add_library(MLib INTERFACE 
    ${PROJECT_SOURCE_DIR}/include/matrix.h 
    # ${PROJECT_SOURCE_DIR}/include/vector.h
)

target_include_directories( MLib INTERFACE
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
)

set(SOURCES 
    src/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE MLib)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

set(TESTS_PATH
    tests
)

add_executable(tests 
    ${TESTS_PATH}/matrix_costructors.cc
    ${TESTS_PATH}/matrix_operators.cc
    ${TESTS_PATH}/matrix_addition.cc    
    ${TESTS_PATH}/matrix_multiplication.cc
    ${TESTS_PATH}/matrix_transpose.cc
    ${TESTS_PATH}/matrix_rows_columns.cc
    ${TESTS_PATH}/matrix_LU_factorization.cc
    ${TESTS_PATH}/matrix_substitutions.cc
    ${TESTS_PATH}/matrix_inverse.cc
    ${TESTS_PATH}/matrix_identity.cc
    ${TESTS_PATH}/matrix_determinant.cc
)

target_link_libraries( tests gtest_main MLib gtest gmock)

include(GoogleTest)
gtest_discover_tests(tests)
