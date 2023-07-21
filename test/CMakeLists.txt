cmake_minimum_required(VERSION 3.11.0)

project(testExecutor
        VERSION 0.1.0
        DESCRIPTION
            "..."
        LANGUAGES C CXX)

# カバレッジを取る  locvのインストールが必要
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} --coverage")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")

# テストケースのサブディレクトリを追加する
add_subdirectory(values)

# 実行バイリの出力先
# set(EXECUTABLE_OUTPUT_PATH bin)
# テストケースの実行バイナリ
add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE main.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE
${CMAKE_SOURCE_DIR}/test/include/Catch2
)
target_link_libraries(${PROJECT_NAME} PRIVATE
# CHECK::ここにテストケースで使用する依存オブジェクトライブラリを追加
test_values
$<TARGET_OBJECTS:domain>
)