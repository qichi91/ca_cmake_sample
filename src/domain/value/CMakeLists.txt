cmake_minimum_required(VERSION 3.13.0)

# add sources to the library target
target_sources(srcCompileObjects PRIVATE

    # CHECK::ここにソースを追加
    "${CMAKE_CURRENT_SOURCE_DIR}/IntValue.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/StringValue.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/TypeNameValue.cpp"
    # "${CMAKE_CURRENT_SOURCE_DIR}/ThreeOctalDigitsValue.cpp"
)

# テスト対象の場合はPUBLICにする
# set the include directories
target_include_directories(
    srcCompileObjects
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}"

    # PRIVATE include
)
