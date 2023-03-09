#pragma once


#pragma once
#include <string>
using namespace std;

class User

{
    const string login_; // нельзя поменть логин (const)
    string password_; // можно поменять пароль
    string name_; // можно поменять имя

public:
    User(const string& login, const string& password, const string& name) : login_(login), password_(password), name_(name)
    {}

    const string& getUserLogin() const

    {
        return login_;
    }

    const string& getUserPassword() const

    {
        return password_;
    }

    void setUserPassword(const string& password)

    {
        password_ = password;
    }

    const string& setUserName() const { return name_; }

    void setUserName(const string& name)

    {
        name_ = name;
    }

};
