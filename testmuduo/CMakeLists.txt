#配置头文件搜索路径
#include_directories()
#配置库文件
#link_directories()
set(SRC_LIST muduo_server.cpp)
#把.路径下的所有源文件放在SRC_LIST中
#aux_source_directory(. SRC_LIST)

#设置可执行文件最终存储路径
#set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)


add_executable(main ${SRC_LIST})

#表示目前文件需要连接的库文件
target_link_libraries(main muduo_net muduo_base pthread)