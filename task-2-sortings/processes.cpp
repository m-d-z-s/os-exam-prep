#include "processes.h"

int main() {
    int *array = new int[N];
    for (int i = 0; i < N; ++i) {
       array[i] = rand();
    }
    if(!fork()){
        bubbleSort(array,N);
        writeStream(array, "bubble.txt");
    }
    if(!fork()){
        shellSort(array,N);
        writeStream(array, "shell.txt");
    }
    if(!fork()){
        quickSort(array, 0, N-1);
        writeStream(array, "qs.txt");
    }
    else{
        for (int i = 0; i < N; ++i) {
            std::cout << array[i] << "\n";
        }
    }

    return 0;
}
