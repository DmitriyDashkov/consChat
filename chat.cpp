#include "chat.h"
#include "user.h"

Chat::Chat(string n) : m_name(n)
{

}

void Chat::addUser(User* newUser)
{
    users[numberOfUsers] = newUser;
    numberOfUsers++;
    cout << newUser->getUserLogin() << " entered the chat" << endl;
}
