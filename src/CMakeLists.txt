cmake_minimum_required(VERSION 3.13.0)

# projectは実行ファイルを作成するときにだけ設定する
project(cmaketest2
    VERSION 0.1.0
    DESCRIPTION
    "..."
    LANGUAGES C CXX)

# サブディレクトリ全体をコンパイルしたオブジェクトライブラリを定義
add_library(srcCompileObjects OBJECT "")
# include pathの設定
target_include_directories(
    srcCompileObjects
    PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include")

# CHECK::ここにサブディレクトリを追加
add_subdirectory(domain)

# 実行バイリの出力先(build/{project src path}/output)
set(EXECUTABLE_OUTPUT_PATH output)

# 実行ファイルの作成
add_executable(${PROJECT_NAME})

# 実行ファイルにソースを追加
target_sources(${PROJECT_NAME} PRIVATE main.cpp)

# 実行ファイルにコンパイル済みオブジェクトライブラリを追加
target_link_libraries(${PROJECT_NAME} PRIVATE srcCompileObjects)

# make installの出力先
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION release)