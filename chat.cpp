#include "chat.h"
#include "user.h"

#include <limits>



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
        std::cout << "2 - Enter the chat as a user " << endl;
        std::cin >> choice;
        switch (choice) {
        case 0:
            b = false;
            break;
        case 1:
            createUser();
            break;
        case 2:
            chatEntry();
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
    users[numberOfUsers] = newUser;
    numberOfUsers++;
}

void Chat::chatEntry()
{
    bool b{true};
    while(b) {
        std::cout << "Chat entry" << endl;
        std::cout << "User choice:" << endl;
        for(int i=0; i<numberOfUsers; i++) {
            std::cout << i+1 << " - " << users[i]->getUserLogin() << endl;
        }
        int choice;
        std::cin >> choice;
        std::cout << "Enter password for " << users[choice-1]->getUserLogin() << endl;
        std::string password;
        std::cin >> password;
        if(password == users[choice-1]->getUserPassword()) {
            setCurrentUser(users[choice-1]);
            std::cout << "Current user is " << currentUser()->getUserLogin() << endl;
            workingUser();
            b = false;
        }
        else {
            std::cout << "Incorrect password" << endl;
        }
    }
}

void Chat::workingUser()
{
    bool b{true};

    while(b) {
        std::cout << "********** " << "User " << currentUser()->getUserLogin() << " **********" << endl;
        std::cout << "0 - back" << endl;
        std::cout << "1 - Show general chat" << endl;
        std::cout << "2 - Show inbox" << endl;
        std::cout << "3 - Show outgoing" << endl;
        std::cout << "4 - Message in general chat" << endl;
        std::cout << "5 - Private message" << endl;
        int choice;
        std::cin >> choice;
        switch (choice) {
        case 0:
            b = false;
            break;
        case 1:
            showGeneralChat();
            break;
        case 2:
            showInbox();
            break;
        case 3:
            showOutgoing();
            break;
        case 4:
            messageInGeneralChat();
            break;
        case 5:
            privateMessage();
            break;
        default:
            std::cout << "Retry please... " << endl;
            break;
        }
    }
}

void Chat::showGeneralChat()
{

}
void Chat::showInbox()
{
    std::cout << "Inbox messages:" << endl;
    for (unsigned int i=0; i<messages.size(); i++) {
        if(messages.at(i)->getTo() == currentUser()->getUserLogin()) {
            std::cout << "From " << messages.at(i)->getFrom() << ":       " << messages.at(i)->getMessage() << endl;
        }
    }
}
void Chat::showOutgoing()
{
    std::cout << "Outgoing messages:" << endl;
    for (unsigned int i=0; i<messages.size(); i++) {
        if(messages.at(i)->getFrom() == currentUser()->getUserLogin()) {
            std::cout << "To " << messages.at(i)->getTo() << ":       " << messages.at(i)->getMessage() << endl;
        }
    }
}
void Chat::messageInGeneralChat()
{

}
void Chat::privateMessage()
{
    std::cout << "To whom: " << endl;
    std::vector<User*> addressees;
    for(int i=0; i<numberOfUsers; i++) {
        if(users[i]->getUserLogin() != currentUser()->getUserLogin())
            addressees.push_back(users[i]);
    }
    for(unsigned int i=1; i<=addressees.size(); i++) {
        std::cout << i << " - " << addressees[i-1]->getUserLogin() << endl;
    }
    unsigned int choice;
    std::cin >> choice;
    std::cout << "Enter your message to " << addressees[choice-1]->getUserLogin() << ":" << endl;
    std::string mes;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, mes);
    Message *message = new Message(currentUser()->getUserLogin(),
                                   addressees[choice-1]->getUserLogin(),
                                    mes);
    messages.push_back(message);
    std::cout << "Message sent" << endl;
}
