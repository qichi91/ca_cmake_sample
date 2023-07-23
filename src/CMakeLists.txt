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
    PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/../include"
    "${CMAKE_CURRENT_SOURCE_DIR}/../include/Hypodermic/Hypodermic"
    "${CMAKE_CURRENT_SOURCE_DIR}/../include/json"
    "${CMAKE_CURRENT_SOURCE_DIR}/../include/spdlog/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/../include/spdlog_setup/include"
)

# CHECK::ここにサブディレクトリを追加
add_subdirectory(domain)
add_subdirectory(application)
add_subdirectory(registory)
add_subdirectory(infrastructure)
add_subdirectory(utility)

# 実行バイリの出力先(build/{project src path}/output)
set(EXECUTABLE_OUTPUT_PATH output)

# 実行ファイルの作成
add_executable(${PROJECT_NAME})

# 実行ファイルにソースを追加
target_sources(${PROJECT_NAME} PRIVATE main.cpp)

# 実行ファイルにコンパイル済みオブジェクトライブラリを追加
target_link_libraries(${PROJECT_NAME} PRIVATE srcCompileObjects)

# 実行ファイルと同じ場所にspdlog_setup用のファイルをコピー
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/utility/logger/logging.toml $<TARGET_FILE_DIR:${PROJECT_NAME}>)

# make installの出力先
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION release)