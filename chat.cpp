#include "chat.h"
#include <limits>
#include <windows.h>

//установка цвета текста консоли
void SetColor(int text, int bg){
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}

Chat::Chat(std::string n) : _name(n) {}

//Chat::~Chat()
//{

//}

void Chat::working()
{
    char choice;
    bool b{true};
    while(b) {
        std::cout << "\n********* START CHAT **********" << std::endl;
        std::cout << "0 - Exit " << std::endl;
        std::cout << "1 - Create new User " << std::endl;
        std::cout << "2 - Enter the chat as a user " << std::endl;
        std::cin >> choice;
        switch (choice) {
        case '0':
            b = false;
            break;
        case '1':
            createUser();
            break;
        case '2':
            chatEntry();
            break;
        default:
            std::cout << "Retry please... " << std::endl;
            break;
        }
    }
}

void Chat::createUser()
{
    std::cout << "Creating a new user" << std::endl;
    std::cout << "Enter user login:" << std::endl;
    std::string login;
    std::cin >> login;
    std::cout << "Enter user password:" << std::endl;
    std::string password;
    std::cin >> password;
    std::cout << "Enter user name:" << std::endl;
    std::string name;
    std::cin >> name;

    if (login == "all" || getHavingLogin(login))
    {
        std::cout << "Error. This login already exists." << std::endl;
    }
    else if (name == "all" || getHavingName(name))
    {
        std::cout << "Error. This name already exists." << std::endl;
    }
    else
    {
        User *user = new User (login, password, name);
//        std::unique_ptr<User> user (new User(login, password, name));
        _users.push_back(user);
    }
}

std::shared_ptr<User> Chat::getCurentUserName() const
{
    return _curentUserName;
}

void Chat::chatEntry()
{
    std::cout << "Enter login: ";
    std::string login;
    std::cin >> login;
    std::cout << "Enter password: ";
    std::string password;
    std::cin >> password;
    _curentUserName = getHavingLogin(login);
    if (_curentUserName == nullptr || (password != _curentUserName->getUserPassword()))
    {
        _curentUserName = nullptr;
        std::cout << "Error." << std::endl;
    }
    else
    {
        workingUser();
    }
}

void Chat::workingUser()
{
    bool b{true};

    while(b) {
        std::cout << "\n********** " << "User " << _curentUserName->getUserName() << " **********" << endl;
        std::cout << "0 - back" << std::endl;
        std::cout << "1 - read messages" << std::endl;
        std::cout << "2 - to write a message" << std::endl;

        char choice;
        std::cin >> choice;
        switch (choice) {
        case '0':
            b = false;
            break;
        case '1':
            readMessages();
            break;
        case '2':
            writeMessage();
            break;
        default:
            std::cout << "Retry please... " << std::endl;
            break;
        }
    }
}
q
std::shared_ptr<User> Chat::getHavingLogin(const std::string& login) const
{
    for (auto& user : _users)
    {
        if (login == user->getUserLogin())
            return std::make_shared<User>(user);
    }
    return nullptr;
}

std::shared_ptr<User> Chat::getHavingName(const std::string& name) const
{
    for (auto& user : _users)
    {
        if (name == user->getUserName())
            return std::make_shared<User>(user);
    }
    return nullptr;
}

void Chat::readMessages()
{
    std::string from;
    std::string to;

    for(auto& message : _messages)
    {
        if(_curentUserName->getUserName() == message->getFrom())
        {
            SetColor(2,0);    //личные исходящие
            std::cout << "\nMessage to " << message->getTo() << std::endl;
            std::cout << "text: " << message->getMessage() << std::endl;
        }

    }
    for(auto& message : _messages)
    {
        if(_curentUserName->getUserName() == message->getTo())
        {
            SetColor(3,0);    //личные входящие
            std::cout << "\nMessage from " << message->getFrom() << std::endl;
            std::cout << "text: " << message->getMessage() << std::endl;
        }

    }

    SetColor(4,0);    //общие
    std::cout << "\nGeneral chat messages: " << std::endl;
    for(auto& message : _messages)
    {
        if(message->getTo() == "all")
        {
            std::cout << message->getFrom() << " : "
                      << message->getMessage() << std::endl;
        }
    }
    SetColor(7,0);
    std::cout << "-----------end--------------" << std::endl;
 }

void Chat::writeMessage()
{
    std::string to;
    std::cout << "To: ";
    std::cin >> to;
    std::string text;
    std::cout << "Message text: ";
    std::cin.ignore();
    getline(std::cin, text);

    if (to == "all")
    {
        Message *message = new Message(_curentUserName->getUserName(), "all", text);
        _messages.push_back(message);
//        _messages.push_back(Message(_curentUserName->getUserName(), "all", text));
    }
    else if (getHavingName(to))
    {
        Message *message = new Message(_curentUserName->getUserName(), getHavingName(to)->getUserName(), text);
        _messages.push_back(message);
//        _messages.push_back(Message(_curentUserName->getUserName(), getHavingName(to)->getUserName(), text));
    }
    else
    {
        std::cout << "Error. No username." << std::endl;
    }   

}
