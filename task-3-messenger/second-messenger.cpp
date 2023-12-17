#include "common.h"

int main(){
    int queue = msgget(123456, 0666 | IPC_CREAT);

    Message message = {};
    msgrcv(queue, &message, sizeof(message.text), 12678, 0);

    std::cout << message.text << "\n";

    Message message1 = {};
    message1.key = 12677;
    std::cin.getline( message1.text, 100);
    msgsnd(queue, &message1, sizeof(message1.text), 0);

    return 0;
}