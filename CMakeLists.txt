cmake_minimum_required(VERSION 3.16)
project(cpp11)

set(CMAKE_CXX_STANDARD 11)

#add_executable(cpp11  4.snotstatic_member_sizeof.cpp 5.expand.cpp)

# 遍历项目根目录下所有的 .cpp 文件
file (GLOB files *.cpp)
foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    add_executable (${exe} ${file} expend_friend.cpp)
    message (\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ bin/${exe})
endforeach ()
