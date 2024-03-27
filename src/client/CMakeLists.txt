aux_source_directory(. SRC_LIST)

add_executable(ChatClient ${SRC_LIST})
#指定链接时依赖的库文件 
target_link_libraries(ChatClient pthread)
