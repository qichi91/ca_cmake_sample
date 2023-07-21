cmake_minimum_required(VERSION 3.11.0)

# CHECK::ここにサブディレクトリを追加
add_subdirectory(values)
add_subdirectory(entity)

add_library(domain OBJECT  $<TARGET_OBJECTS:domain_values> $<TARGET_OBJECTS:domain_entity>)