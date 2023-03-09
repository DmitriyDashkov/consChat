#pragma once

#include <iostream>
#include <string>

#define MAX_USERS 100

class User;
class Chat
{
private:
    std::string _name;

public:
    Chat(std::string n);
    int numberOfUsers {0};              //количество юзеров в чате
    User* users[MAX_USERS];             //список юзеров
    void working();                     //работа чата
    void addUser(User* newUser);        //добавить юзера в чат
    User* currentUser = nullptr;        //текущий пользователь чата
    void setCurrentUser();             //установить текущего пользователя чата
    void createUser();
    void showUsers();                   //показать список юзеров
};
