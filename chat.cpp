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

void Chat::showUsers()
{
    cout << "Now in chat: " << endl;
    for(int i=0; i<numberOfUsers; i++) {
        cout << i << " - " << users[i]->getUserLogin() << endl;
    }
}

void Chat::setCurrentUser(User* currUser)
{
    currentUser = currUser;
}
