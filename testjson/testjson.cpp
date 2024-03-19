#include "json.hpp"
using json = nlohmann::json;

#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

// json数据序列化1
string func1()
{
    json js;
    js["msg_type"] = 2;
    js["from"] = "yang lan";
    js["to"] = "zzm";
    js["msg"] = "wo shi xiao zhu!!!";
    string s = js.dump(); // json数据对象序列化成json字符串

    // cout << s.c_str() << endl;
    return s;
}

// json数据序列化2
string func2()
{
    json js;
    // 添加数组
    js["id"] = {1, 2, 3, 4, 5};
    // 添加key-value
    js["name"] = "zhang san";
    // 添加对象
    js["msg"]["zhang san"] = "hello world";
    js["msg"]["liu shuo"] = "hello china";
    // 上面等同于下面这句一次性添加数组对象
    js["msg"] = {{"zhang san", "hello world"}, {"liu shuo", "hello china"}};
    // cout << js << endl;
    return js.dump();
}

// json容器序列化
string func3()
{
    json js;
    // 直接序列化一个vector容器
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(5);
    js["list"] = vec;
    // 直接序列化一个map容器
    map<int, string> m;
    m.insert({1, "黄山"});
    m.insert({2, "华山"});
    m.insert({3, "泰山"});
    js["path"] = m;
    // cout << js << endl;
    return js.dump();
}

int main()
{
    string recvBuf = func3();
    // 数据的反序列化 json字符串反序列化成数据对象（看作容器，方便访问）
    json jsBuf = json::parse(recvBuf);

    // cout << jsBuf["msg_type"] << endl;
    // cout << jsBuf["from"] << endl;
    // cout << jsBuf["to"] << endl;
    // cout << jsBuf["msg"] << endl;

    // cout << jsBuf["id"] << endl;
    // auto arr = jsBuf["id"];
    // cout << arr[2] << endl;
    // auto name = jsBuf["name"];
    // cout << name << endl;
    // auto arr2 = jsBuf["msg"];
    // cout << arr2["zhang san"] << endl;

    vector<int> vec = jsBuf["list"];
    cout << vec[2] << endl;
    map<int, string> map = jsBuf["path"];
    cout << map[2] << endl;
    for (int v : vec)
    {
        cout << v << endl;
    }
    for (auto &p : map)
    {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}