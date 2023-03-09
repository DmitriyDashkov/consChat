#include "chat.h"
#include "user.h"

Chat::Chat(string n) : _name(n)
{

}

void Chat::working()
{
    int choice;
    bool b{true};
    while(b) {
        std::cout << "********* START CHAT **********" << endl;
        std::cout << "0 - Exit " << endl;
        std::cout << "1 - Create new User " << endl;
        std::cout << "2 - Set current User " << endl;
        std::cout << "3 - Show chat " << endl;
        std::cout << "4 - To current user " << endl;
        std::cin >> choice;
        switch (choice) {
        case 0:
            b = false;
            break;
        case 1:
            createUser();
            break;
        case 2:
            setCurrentUser();
            break;
        case 3:
            showUsers();
            break;
        default:
            std::cout << "Retry please... " << endl;
            break;
        }
    }
}

void Chat::createUser()
{
    std::cout << "Creating a new user" << endl;
    std::cout << "Enter user login:" << endl;
    std::string login;
    std::cin >> login;
    std::cout << "Enter user password:" << endl;
    std::string password;
    std::cin >> password;
    std::cout << "Enter user name:" << endl;
    std::string name;
    std::cin >> name;
    if(login.length()!=0 && password.length()!=0 && name.length()!=0) {
        User* newUser = new User(login, password, name);
        addUser(newUser);
    }
}

void Chat::addUser(User* newUser)
{
    bool b{true};
    while (b) {
        std::cout << "Enter password for " << newUser->getUserLogin() << endl;
        std::string password;
        std::cin >> password;
        if(password == newUser->getUserPassword()) {
            users[numberOfUsers] = newUser;
            numberOfUsers++;
            std::cout << newUser->getUserLogin() << " entered the chat" << endl;
            b = false;
        }
        else {
            std::cout << "Incorrect password" << endl;
        }
    }
}

void Chat::showUsers()
{
    std::cout << "Now in chat: " << endl;
    for(int i=0; i<numberOfUsers; i++) {
        std::cout << users[i]->getUserLogin() << endl;
    }
}

void Chat::setCurrentUser()
{
    bool b {true};
    while (b) {
        std::cout << "Setting current user" << endl;
        for(int i=0; i<numberOfUsers; i++) {
            std::cout << i+1 << " - " << users[i]->getUserLogin() << endl;
        }
        int choice;
        std::cin >> choice;
        if((choice<0) || (choice>numberOfUsers)) {
            std::cout << "Retry please... " << endl;
        }
        else {
            currentUser = users[choice-1];
            std::cout << "Current user is " << users[choice-1]->getUserLogin() << endl;
            b = false;
        }
    }
}
