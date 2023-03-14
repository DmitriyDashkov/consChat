#pragma once
#include <string>
class User
{
    const std::string _login;
    std::string _password;
    std::string _name;

public:
    User();
    User(const std::string& login, const std::string& password, const std::string& name);
    ~User();
    
    std::string getUserLogin() const;
    std::string getUserPassword() const;
    void setUserPassword(std::string& password);
    std::string getUserName() const;
    void setUserName(std::string& name);  
};
