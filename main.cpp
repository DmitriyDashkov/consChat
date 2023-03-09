#include "user.h"
#include "chat.h"

int main()
{
    Chat* chat = new Chat("OurChat");
    User* user1 = new User("Svetlana", "123", "Svetlana");
    User* user2 = new User("Grigoriy", "123", "Grigoriy");
    User* user3 = new User("Dmitriy", "123", "Dmitriy");
    chat->addUser(user1);
    chat->addUser(user2);
    chat->addUser(user3);

    cout << "Set current User: " << endl;
    chat->showUsers();
    int currUser;
    cin >> currUser;
    chat->setCurrentUser(chat->users[currUser]);
    cout << "Current User is " << chat->currentUser->getUserLogin() << endl;

    return 0;
}
