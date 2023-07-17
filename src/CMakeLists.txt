cmake_minimum_required(VERSION 3.11.0)

project(cmaketest2
        VERSION 0.1.0
        DESCRIPTION
            "..."
        LANGUAGES C CXX)

add_subdirectory(Domain)

# 実行バイリの出力先
# set(EXECUTABLE_OUTPUT_PATH bin)
# add an example executable
add_executable(${PROJECT_NAME})
# add sources to the example executable
target_sources(${PROJECT_NAME} PRIVATE main.cpp)
# link libraries "hello" and "hello_header_only" to the example executable the
# libraries are described in the subdirectories
target_link_libraries(${PROJECT_NAME} PRIVATE
domain_values
)

# make installの出力先
# install(TARGETS ${PROJECT_NAME} DESTINATION /app)