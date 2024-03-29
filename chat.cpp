#include "chat.h"

//установка цвета текста консоли
void SetColor(int text, int bg){
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}

Chat::Chat(std::string n) : _name(n) {}

Chat::~Chat() = default;

void Chat::working()
{
    char choice;
    bool b{true};
    while(b) {
        SetColor(11, 0);
        std::cout << "\n********* START CHAT **********" << std::endl;
        std::cout << "0 - Exit " << std::endl;
        std::cout << "1 - Create new User " << std::endl;
        std::cout << "2 - Enter the chat as a user " << std::endl;
        std::cout << "3 - Show info about user by index " << std::endl;
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
        case '3':
            userInfo();
            break;
        default:
            SetColor(4, 0);
            std::cout << "Retry please..." << std::endl;
            break;
        }
    }
}

void Chat::createUser()
{
    SetColor(7, 0);
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
        SetColor(4, 0);
        std::cout << "Error. This login already exists." << std::endl;
    }
    else if (name == "all" || getHavingName(name))
    {
        SetColor(4, 0);
        std::cout << "Error. This name already exists." << std::endl;
    }
    else
    {
         std::shared_ptr<User> user (new User(login, password, name));
         _users.push_back(user);
    }
}

std::shared_ptr<User> Chat::getCurentUserName() const
{
    return _curentUserName;
}

void Chat::chatEntry()
{
    SetColor(7, 0);
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
        SetColor(4, 0);
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
        SetColor(9, 0);
        std::cout << "\n********** " << "User " << _curentUserName->getUserName() << " **********" << std::endl;
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
            SetColor(4, 0);
            std::cout << "Retry please..." << std::endl;
            break;
        }
    }
}

std::shared_ptr<User> Chat::getHavingLogin(const std::string& login) const
{
    for (auto& user : _users)
    {
        if (login == user->getUserLogin())
            return std::shared_ptr<User>(user);
    }
    return nullptr;
}

std::shared_ptr<User> Chat::getHavingName(const std::string& name) const
{
    for (auto& user : _users)
    {
        if (name == user->getUserName())
            return std::shared_ptr<User>(user);
    }
    return nullptr;
}

void Chat::readMessages()
{
    SetColor(10, 0);    //общие
    std::cout << "\n********** Messages to all **********" << std::endl;
    for (auto& message : _messages)
    {
        if (message->getTo() == "all")
        {
            std::cout << "\nFrom " << message->getFrom() << " : " << message->getMessage() << std::endl;
        }
    }

    SetColor(14, 0);    //личные входящие
    std::cout << "\n********** Messages to " << _curentUserName->getUserName() << " **********" << std::endl;
    for (auto& message : _messages)
    {
        if (_curentUserName->getUserName() == message->getTo())
        {
            std::cout << "\nFrom " << message->getFrom() << " : " << message->getMessage() << std::endl;
        }
    }
    std::cout << "--------------end----------------" << std::endl;
 }

void Chat::writeMessage()
{
    SetColor(7, 0);
    std::string to;
    std::cout << "To (all or user name): ";
    std::cin >> to;
    std::string text;
    std::cout << "Message text: ";
    std::cin.ignore();
    getline(std::cin, text);

    if (to == "all")
    {
        std::shared_ptr<Message> message (new Message(_curentUserName->getUserName(), "all", text));
        _messages.push_back(message);
    }
    else if (getHavingName(to))
    {
        std::shared_ptr<Message> message (new Message(_curentUserName->getUserName(), getHavingName(to)->getUserName(), text));
        _messages.push_back(message);
    }
    else
    {
        SetColor(4, 0);
        std::cout << "Error. No username." << std::endl;
    }
}

void Chat::userInfo()
{
    try {
        std::cout << "Enter user index" << std::endl;
        unsigned int choice;
        while (!(std::cin >> choice)) {
            std::cout << "Input Error\n";
            std::cin.clear();
            fflush(stdin);
        }
        if(choice >= users().size()) throw ChatError(0);
        else
            showUserInfo(choice);
    } 
    catch (ChatError& ex) {
        SetColor(4, 0);
        std::cout << ex.what() << std::endl;
    }
}

void Chat::showUserInfo(unsigned int choice)
{
    SetColor(7, 0);
    std::cout << "Info about user " << users().at(choice)->getUserName() << std::endl;
    std::cout << "User login: " << users().at(choice)->getUserLogin() << std::endl;
    std::cout << "User password: " << users().at(choice)->getUserPassword() << std::endl;
    std::cout << "User name: " << users().at(choice)->getUserName() << std::endl;
    int a{0}, b{0};
    for(auto mes : _messages) {
        if (mes->getFrom() == users().at(choice)->getUserName()) a++;
        if (mes->getTo() == users().at(choice)->getUserName()) b++;
    }
    std::cout << "Number of outgoing messages: " << a << std::endl;
    std::cout << "Number of incoming messages: " << b << std::endl;
}