#include "chat.h"

int main()
{
    Chat* chat = new Chat("OurChat");
    chat->working();

    delete chat;
    return 0;
}