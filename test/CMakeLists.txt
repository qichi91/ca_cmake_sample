cmake_minimum_required(VERSION 3.13.0)

project(testExecutor
    VERSION 0.1.0
    DESCRIPTION
    "..."
    LANGUAGES C CXX)

# カバレッジを取る  locvのインストールが必要
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")

# サブディレクトリ全体のオブジェクトをまとめたオブジェクトライブラリを定義
add_library(testCompileObjects OBJECT "main.cpp")
target_include_directories(
    testCompileObjects
    PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/Catch2"
    # テスト対象クラスのヘッダーを取り込む
    "$<TARGET_PROPERTY:srcCompileObjects,INTERFACE_INCLUDE_DIRECTORIES>"
)

# CHECK::ここにサブディレクトリを追加
add_subdirectory(values)

# 実行バイリの出力先
set(EXECUTABLE_OUTPUT_PATH output)

# テストケースの実行バイナリ
add_executable(${PROJECT_NAME})

# add sources to the example executable
target_sources(${PROJECT_NAME} PRIVATE)
target_link_libraries(${PROJECT_NAME} PRIVATE

    # CHECK::ここにテストケースで使用する依存オブジェクトライブラリを追加
    srcCompileObjects
    testCompileObjects
)