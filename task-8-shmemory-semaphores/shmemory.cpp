#include "utils.h"
#include <unistd.h>

#define SHM_SIZE 128

void lowerSemaphore(int semaphore) {
    struct sembuf operation{};

    operation.sem_num = 0;
    operation.sem_op = (-1);
    operation.sem_flg = 0;

    semop(semaphore, &operation, 1);
}

void raiseSemaphore(int semaphore) {
    struct sembuf operation{};

    operation.sem_num = 0;
    operation.sem_op = 1;
    operation.sem_flg = 0;

    semop(semaphore, &operation, 1);
}

int main() {
    int shmemoryDesriptor = shmget(123456, SHM_SIZE, IPC_CREAT | 0666);

    int *array = (int *) shmat(shmemoryDesriptor, NULL, 0);
    array[0] = 0;
    for (int i = 1; i < SHM_SIZE; i++) {
        array[i] = i;
    }

    int pSemaphore = semget(2222, 1, IPC_CREAT | 0666);
    int cSemaphore = semget(2223, 1, IPC_CREAT | 0666);
    semctl(pSemaphore, 0, SETVAL, 1);
    semctl(cSemaphore, 0, SETVAL, 0);

    if (!fork()) {
        while (array[0] < SHM_SIZE) {
            lowerSemaphore(cSemaphore);
            std::cout << array[0] << ") child: " << array[array[0]] << "\n";
            array[0]++;
            raiseSemaphore(pSemaphore);
        }
    } else {
        while (array[0] < SHM_SIZE - 1) {
            lowerSemaphore(pSemaphore);
            std::cout << array[0] << ") parent: " << array[array[0]] << std::endl;
            array[0]++;
            raiseSemaphore(cSemaphore);
        }
    }

    return 0;
}
