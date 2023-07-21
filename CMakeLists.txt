cmake_minimum_required(VERSION 3.13.0)

# VSCodeのIntelliSenseにInclude Pathを設定するための設定
# cmakeのビルドを実行すると、ビルド先にcompile_commands.jsonが生成される
# .vscode/c_cpp_properties.jsonにcompile_commands.jsonのパスを設定するとインテリセンスが効く
#       "compileCommands": "${workspaceFolder}/build/compile_commands.json"
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# c++14定義
enable_language(CXX)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# CHECK::ここにサブディレクトリを追加
add_subdirectory(src)
add_subdirectory(test)
