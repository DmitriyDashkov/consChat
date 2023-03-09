#pragma once

#include <iostream>
#include <string>

#define MAX_USERS 100

using namespace std;
class User;
class Chat
{
private:
    string m_name;

public:
    Chat(string n);
    int numberOfUsers {0};          //количество юзеров в чате
    User* users[MAX_USERS];         //список юзеров
    void showUsers();
    void addUser(User* newUser);    //добавить юзера в чат
    User* currentUser;              //текущий пользователь чата
    void setCurrentUser (User* u);  //установить текущего пользователя чата
};
