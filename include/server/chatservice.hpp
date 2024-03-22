#ifndef CHATSERVICE_H
#define CHATSERVICE_H
#include <muduo/net/TcpConnection.h>
#include <unordered_map>
#include <functional>
#include "json.hpp"
using json = nlohmann::json;
using namespace muduo;
using namespace muduo::net;
using namespace std;
using namespace placeholders;

//表示处理消息的事件回调方法类型
using MsgHandler = std::function<void(const TcpConnectionPtr &conn, json &js, Timestamp time)>;

// 聊天服务器业务类
class ChatService
{
public:
    //获取单例对象的接口函数
    static ChatService* instance();
    // 处理登录业务
    void login(const TcpConnectionPtr &conn, json &js, Timestamp time);
    // 处理注册业务
    void reg(const TcpConnectionPtr &conn, json &js, Timestamp time);
    //获取消息对应处理器
    MsgHandler getHandler(int msgid);
private:
    ChatService();

    //存储消息id和对应的业务处理方法
    unordered_map<int, MsgHandler> _msgHandlerMAp;
};

#endif