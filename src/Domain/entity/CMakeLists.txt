cmake_minimum_required(VERSION 3.11.0)

project(
    domain_entity
    VERSION 0.0.0
    DESCRIPTION
        "Entity Objects"
    LANGUAGES CXX
)

# add the library target
add_library(${PROJECT_NAME} OBJECT)

# add sources to the library target
target_sources(${PROJECT_NAME} PRIVATE
# CHECK::ここにソースを追加
User.cpp
)

# define the C++ standard needed to compile this library and make it visible to dependers
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_11)


target_include_directories(${PROJECT_NAME} PRIVATE
${CMAKE_SOURCE_DIR}/src/Domain/values
)
# # set the include directories
# target_include_directories(
#     ${PROJECT_NAME}
#     PRIVATE ./
#     # PUBLIC include
# )
