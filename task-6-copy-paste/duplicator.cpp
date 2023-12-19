#include "utils.h"
#define N 20

void copyPaste(char *fileFrom, char *fileTo){
    int fileFromId = open(fileFrom, O_RDONLY, 0666);

    int fileToId = open(fileTo, O_CREAT | O_WRONLY, 0666);
    char buffer[N];

    int lenRead = read(fileFromId, buffer, N);
    std::cout << lenRead << "\n";

    while (lenRead > 0){
        write(fileToId, buffer, lenRead);
        lenRead = read(fileFromId, buffer, N);
        std::cout << lenRead << "\n";

    }

}

int main(){
    copyPaste("FileFrom.txt", "FileTo.txt");
    return 0;
}