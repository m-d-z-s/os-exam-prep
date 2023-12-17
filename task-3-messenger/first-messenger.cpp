#include "common.h"


int main(){
    int queue = msgget(123456, 0666 | IPC_CREAT);

    Message message = {};
    message.key = 12678;
    std::cin.getline(message.text,100);

    msgsnd(queue, &message, sizeof(message.text), 0);

    Message message1 = {};
    msgrcv(queue, &message1, sizeof(message1), 12677, 0);

    std::cout << message1.text << std::endl;

    return 0;
}