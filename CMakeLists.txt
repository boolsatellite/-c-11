cmake_minimum_required(VERSION 3.16)
project(cpp11)

add_compile_options(-fno-elide-constructors) #关闭编译器优化
set(CMAKE_CXX_STANDARD 11)

add_executable(cpp11 29.lambda.cpp)


# 遍历项目根目录下所有的 .cpp 文件
#[[
file (GLOB files *.cpp)
foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    add_executable (${exe} ${file} expend_friend.cpp 5.final_override.cpp)
    message (\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ bin/${exe})
endforeach ()
]]
