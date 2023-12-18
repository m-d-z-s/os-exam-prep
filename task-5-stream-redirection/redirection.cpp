#include "utils.h"
// запись текста в файл

int main(){
    int file = open("file_1.txt", O_CREAT | O_WRONLY | O_APPEND, 0666);
    dup2(file, 1);
    std::cout << "you" << std::endl;
}