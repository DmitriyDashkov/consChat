#pragma once
#include "user.h"
#include "Message.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <exception>
using namespace std;

class Chat
{
private:
    std::string _name;                          //имя чата
    std::vector<shared_ptr<User>> _users;       //пользователи чата
    std::vector<shared_ptr<Message>> _messages; //все сообщения
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
    void userInfo();
    void showUserInfo(unsigned int);
    std::vector<shared_ptr<User>> users()   {return _users;}
};

class ChatError : public exception
{
private:
    int m_numError;
    const std::string m_message [1] {
                                "Incorrect access by index"     //0
                                };
public:
    ChatError() = default;
    ChatError(int num);
    int NumError() const                     {return m_numError;}
    const std::string Message(int i) const   {return m_message[i];}
    virtual const char* what() const noexcept override;
};
