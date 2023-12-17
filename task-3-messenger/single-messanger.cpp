#include "common.h"

int main(int argc, char *argv[]){
    int queue = msgget(123456, 0666 | IPC_CREAT);
    int key = atoi(argv[2]);

    if (argv[1][0] == 's'){
        Message message = {};
        message.key = key;

        char letter[100];
        char line[20];
        int count = 5;
        while(count--){
            // TODO: add letter size check
            std::cin.getline(line, 20);
            if (strcmp(line,"") == 0){
                break;
            }
            strcat(letter, line);
        }
        strcpy(message.text, letter);

        msgsnd(queue, &message, sizeof(message.text), 0);
    }
    if (argv[1][0] == 'r'){
        Message message = {};
        msgrcv(queue, &message, sizeof(message.text), key, 0);

        std::cout <<"Получил: "<< message.text << "\n";

    }
    return 0;
}
//strcopy