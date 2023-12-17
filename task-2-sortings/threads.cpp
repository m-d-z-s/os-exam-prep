#include "processes.h"

// pthread_t threadName;
// pthread_create(&threadName, nullptr, thread_function, data);
// pthread_join(threadName, nullptr);


void* fun1(void* args){
    int* array = static_cast<int*>(args);
    bubbleSort(array, N);
    writeStream(array, "pth_bubble.txt");
    return nullptr;
}

void* fun2(void* args){
    int* array = static_cast<int*>(args);
    shellSort(array, N);
    writeStream(array, "pth_shell.txt");
    return nullptr;
}

void* fun3(void* args){
    int* array = static_cast<int*>(args);
    quickSort(array, 0, N-1);
    writeStream(array, "pth_qs.txt");
    return nullptr;
}

void copyArray(const int *old, int *young){
    for (int i = 0; i < N; ++i) {
        young[i] = old[i];
    }

}


int main(){
    int *array = new int[N];
    for (int i = 0; i < N; ++i) {
        array[i] = rand();
    }


    pthread_t thread1;
    int *array1 = new int[N];
    copyArray(array, array1);
    pthread_create(&thread1, nullptr, fun1, array1);

    pthread_t thread2;
    int *array2 = new int[N];
    copyArray(array, array2);
    pthread_create(&thread2, nullptr, fun2, array2);

    pthread_t thread3;
    int *array3 = new int[N];
    copyArray(array,array3);
    pthread_create(&thread3, nullptr, fun3, array3);

    pthread_join(thread1, nullptr);
    pthread_join(thread2, nullptr);
    pthread_join(thread3, nullptr);
    writeStream(array, "init.txt");
}