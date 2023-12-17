#include <iostream>
#include <unistd.h>

int main(int argc, char *argv[]) {
    // 1. принимает строку
    // 2. сколько нужно раз ее вывести и номер поцесса
    char *stroke = argv[1];
    int count = atoi(argv[2]);
    int r;
    if (count > 100) return -1;

    for (int i = 0; i < count; ++i) {
        if (!fork()) {
            std::cout << stroke << "; id:  " << getpid() << std::endl;
            return 0;
        }
        wait(&r);
    }

    std::cout << "Im parent. Id:  " << getpid() << std::endl;


    return 0;
}
