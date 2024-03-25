#ifndef USERMODEL_H
#define USERMODEL_H
#include "user.hpp"

//user表的数据操作类
class UserModel{
public:
    //增
    bool insert(User &user);

    //根据id查
    User query(int id);
    
    //改
    bool updateState(User user);

    //重置状态
    void resetState();
};

#endif