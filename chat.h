#pragma once
#include "user.h"
#include "Message.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Chat
{
private:
    std::string _name;                  //имя чата
    std::vector<User> _users;
    std::vector<Message> _messages;      //все сообщения
    std::shared_ptr<User> _curentUserName = nullptr;

public:
    Chat(std::string n);
    ~Chat();
    
    void working();                                         //работа чата
    void createUser();                                      //создать юзера
    std::shared_ptr<User> getCurentUserName() const;        //текущее имя пользователя
    void chatEntry();                                       //вход в чат
    void workingUser();                                     //работа чата от юзера
    std::shared_ptr<User> getHavingLogin(const std::string& name) const;//наличие логина
    std::shared_ptr<User> getHavingName(const std::string& name) const;//наличие имени
    void readMessages();                                    //чтение сообщений
    void writeMessage();                                    //написать сообщение
};
