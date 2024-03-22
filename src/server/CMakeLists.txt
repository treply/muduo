aux_source_directory(. SRC_LIST)
aux_source_directory(./db DB_LIST)

add_executable(ChatServer ${SRC_LIST} ${DB_LIST})
#指定链接时依赖的库文件
target_link_libraries(ChatServer muduo_net muduo_base mysqlclient pthread)
