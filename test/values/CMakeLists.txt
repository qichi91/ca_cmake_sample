cmake_minimum_required(VERSION 3.11.0)

project(
    test_values
    VERSION 0.0.0
    DESCRIPTION
        "Test : Value Objects"
    LANGUAGES CXX
)

# add the library target
add_library(${PROJECT_NAME} OBJECT)

# add sources to the library target
target_sources(${PROJECT_NAME} PRIVATE
unittest_values.cpp
)

# define the C++ standard needed to compile this library and make it visible to dependers
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_11)

target_include_directories(${PROJECT_NAME} PRIVATE
                            ${CMAKE_SOURCE_DIR}/src/Domain/values
                            ${CMAKE_SOURCE_DIR}/test/include/Catch2)