#pragma once
#include <string>

class User

{
    const std::string _login; // нельзя поменть логин (const)
    std::string _password; // можно поменять пароль
    std::string _name; // можно поменять имя

public:
    User(const std::string& login, const std::string& password, const std::string& name) : _login(login), _password(password), _name(name)
    {}

    const std::string& getUserLogin() const

    {
        return _login;
    }

    const std::string& getUserPassword() const

    {
        return _password;
    }

    void setUserPassword(const std::string& password)

    {
        _password = password;
    }

    const std::string& getUserName() const { return _name; }

    void setUserName(const std::string& name)

    {
        _name = name;
    }

};