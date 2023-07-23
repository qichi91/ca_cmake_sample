cmake_minimum_required(VERSION 3.13.0)

# ターゲット名: srcCompileObjects  は利用するターゲット毎に変える事
# src  : srcCompileObjects
# test : testCompileObjects

# テスト対象の場合はPUBLICにする
# set the include directories
target_include_directories(
    srcCompileObjects
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}"

    # PRIVATE include
)
