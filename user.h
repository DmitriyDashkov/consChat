#pragma once
#include <string>

class User
{
    const std::string _login; // нельзя поменть логин (const)
    std::string _password; // можно поменять пароль
    std::string _name; // можно поменять имя

public:
    User();
    User(const std::string& login, const std::string& password, const std::string& name);
    ~User();
    
    const std::getUserLogin() const;
    const std::getUserPassword() const;
    void setUserPassword(std::string& password);
    const std::getUserName() const;
    void setUserName(std::string& name);  
};