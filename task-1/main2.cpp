#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

int main() {

    if (!fork()) {
        // Код для второго дочернего процесса
        std::cout << "Child 2 ID: " << getpid() << std::endl;
        for (int i = 0; i < 10000; ++i) {
            std::cout << "Hello ";
        }
        std::cout << std::endl;
        return 0;
    }
    if (!fork()) {
        std::cout << "Child 1 ID: " << getpid() << std::endl;
        std::cout << "Child 1 says: Hello once!" << std::endl;
        return 0;
    }

    int status;

    pid_t finishedChild = wait(&status);
    std::cout << "Parent: Child " << finishedChild << " has finished." << std::endl;

    // Ждем завершения второго дочернего процесса
    finishedChild = wait(&status);
    std::cout << "Parent: Child " << finishedChild << " has finished." << std::endl;

    return 0;
}
