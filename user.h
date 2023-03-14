#pragma once
#include <string>

class User
{
    const std::string _login; // Ð½ÐµÐ»ÑÐ·Ñ Ð¿Ð¾Ð¼ÐµÐ½ÑÑ Ð»Ð¾Ð³Ð¸Ð½ (const)
    std::string _password; // Ð¼Ð¾Ð¶Ð½Ð¾ Ð¿Ð¾Ð¼ÐµÐ½ÑÑÑ Ð¿Ð°ÑÐ¾Ð»Ñ
    std::string _name; // Ð¼Ð¾Ð¶Ð½Ð¾ Ð¿Ð¾Ð¼ÐµÐ½ÑÑÑ Ð¸Ð¼Ñ

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
    const string login_; // íåëüçÿ ïîìåíòü ëîãèí (const)
    string password_; // ìîæíî ïîìåíÿòü ïàðîëü
    string name_; // ìîæíî ïîìåíÿòü èìÿ

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

    const string& getUserName() const

    {
        return name_;
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

