#include "utils.h"

int main(int argc, char **argv){
    char *path;
    if (argc == 1) {
        path = ".";
    }
    else {
        path = argv[1];
    }
    DIR *dir = opendir(path);

    if(dir == NULL) {
        perror("Ошибка при открытии папки");
        return 1;
    }

    struct dirent *entry = readdir(dir);
    while (entry != NULL) {
        std::cout << entry->d_name << "\n";
        entry = readdir(dir);
    }
    
    closedir(dir);
    
    return 0;
}
