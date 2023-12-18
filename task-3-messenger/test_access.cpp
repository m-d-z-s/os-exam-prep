#include <sys/file.h>

int main() {
    int file = open("test_file", O_CREAT , 0766);
}