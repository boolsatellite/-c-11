cmake_minimum_required(VERSION 3.16)
project(cpp11)

add_compile_options(-fno-elide-constructors) #πÿ±’±‡“Î∆˜”≈ªØ
set(CMAKE_CXX_STANDARD 11)

add_executable(cpp11 31.general_properties_unicode.cpp)
