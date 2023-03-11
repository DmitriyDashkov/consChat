#pragma once
#include <string>

class User

{
    const std::string _login; // нельзя поменть логин (const)
    std::string password_; // можно поменять пароль
    std::string name_; // можно поменять имя

public:
    User(const std::string& login, const std::string& password, const std::string& name) : _login(login), password_(password), name_(name)
    {}

    const std::string& getUserLogin() const

    {
        return _login;
    }

    const std::string& getUserPassword() const

    {
        return password_;
    }

    void setUserPassword(const std::string& password)

    {
        password_ = password;
    }

    const std::string& getUserName() const { return name_; }

    void setUserName(const std::string& name)

    {
        name_ = name;
    }

};
