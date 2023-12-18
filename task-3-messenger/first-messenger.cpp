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
/*
 * 0 0 110 100 000
 * 0 0 -rw-r-----
 * 1 1 001
 * 2 2 010
 * 3 3 011
 * 4 4 100
 * 5 5 101
 * 6 6 110
 * 7 7 111
 *
 *
 * */