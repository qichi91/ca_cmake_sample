cmake_minimum_required(VERSION 3.13.0)

# add sources to the library target
target_sources(testCompileObjects PRIVATE

    # CHECK::ここにテストケースのソースファイルを追加
    "${CMAKE_CURRENT_SOURCE_DIR}/unittest_values.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/unittest_entity.cpp"
)

# テスト対象の場合はPUBLICにする
# set the include directories
target_include_directories(
    testCompileObjects
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}"

    # PRIVATE include
)
