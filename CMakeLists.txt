cmake_minimum_required(VERSION 3.0)

project(main)

#配置编译选项

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -g)  

#指定搜索子目录
add_subdirectory(testmuduo)
