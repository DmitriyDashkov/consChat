#pragma once
#include "user.h"
#include "Message.h"
#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include "Message.h"
=======



#define MAX_USERS 100
#define MAX_MESSAGES 1000


struct UserLoginExp : public std::exception
{
    const char* what() const noexcept { return "attantion: user login is busy"; }
};

class User;
class Message;
=======
//class User;
//class Message;
class Chat
{
private:
    std::string _name;                  //имя чата
    //User* _currentUser = nullptr;       //текущий пользователь чата
    std::vector<User> _users;
    std::vector<Message> _messages;      //все сообщения
    std::shared_ptr<User> _curentUserName = nullptr;

public:
    Chat(std::string n);
    int numberOfUsers {0};                                  //количество юзеров в чате
    //User* users[MAX_USERS];                                 //список юзеров
    int numberOfMessages {0};                               //количество всех сообщений
    
    void working();                                         //работа чата
    void createUser();                                      //создать юзера
    //void addUser(User* newUser);                            //добавление юзера в чат
    //User* currentUser()             {return _currentUser;}
    //void setCurrentUser(User* u)    {_currentUser = u;}     //установить текущего пользователя чата
    std::shared_ptr<User> getCurentUserName() const;        //текущее имя пользователя
    void chatEntry();                                       //вход в чат
    void workingUser();                                     //работа чата от юзера
    std::shared_ptr<User> getHavingLogin(const std::string& name) const;//наличие логина 
    std::shared_ptr<User> getHavingName(const std::string& name) const;//наличие имени 
    void readMessages();                                    //чтение сообщений
    void writeMessage();                                    //написать сообщение
    //void showOutgoing();                                    //показать исходящие текущего пользователя
    //void messageInGeneralChat();                            //сообщение в общий чат от текущего пользователя
    //void privateMessage();                                  //личное сообщение от текущего пользователя
};
