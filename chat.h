#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Message.h"

#define MAX_USERS 100
#define MAX_MESSAGES 1000

class User;
class Message;
class Chat
{
private:
    std::string _name;                  //имя чата
    User* _currentUser = nullptr;       //текущий пользователь чата

public:
    Chat(std::string n);
    int numberOfUsers {0};                                  //количество юзеров в чате
    User* users[MAX_USERS];                                 //список юзеров
    int numberOfMessages {0};                               //количество всех сообщений
    std::vector<Message*> messages;                         //все сообщения
    void working();                                         //работа чата
    void createUser();                                      //создать юзера
    void addUser(User* newUser);                            //добавление юзера в чат
    User* currentUser()             {return _currentUser;}
    void setCurrentUser(User* u)    {_currentUser = u;}     //установить текущего пользователя чата
    void chatEntry();                                       //вход в чат
    void workingUser();                                     //работа чата от юзера
    void showGeneralChat();                                 //показать общий чат
    void showInbox();                                       //показать входящие текущего пользователя
    void showOutgoing();                                    //показать исходящие текущего пользователя
    void messageInGeneralChat();                            //сообщение в общий чат от текущего пользователя
    void privateMessage();                                  //личное сообщение от текущего пользователя
};
