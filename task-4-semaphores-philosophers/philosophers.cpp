#include "utils.h"
#include "semaphores_i.h"

#define NUM_PHIL 4
#define SLEEP_TIME 2
#define PHIL1 "\033[96mPhilosopher 1 "
#define PHIL2 "\033[93mPhilosopher 2 "
#define PHIL3 "\033[95mPhilosopher 3 "
#define PHIL4 "\033[92mPhilosopher 4 "
#define TAKE_LEFT "took left fork\n"
#define TAKE_RIGHT "took right fork\n"
#define EATS "eats\n"
#define PUT_LEFT "put left\n"
#define PUT_RIGHT "put right\n"


int main(){
    int forksSemaphores[NUM_PHIL] = {
        semget(123, 1, IPC_CREAT | 0666),
        semget(124, 1, IPC_CREAT | 0666),
        semget(125, 1, IPC_CREAT | 0666),
        semget(126, 1, IPC_CREAT | 0666),
    };

    for (int forksSemaphore : forksSemaphores) {
        semctl(forksSemaphore, 0, SETVAL, 1);
    }

    if (!fork()) {
        // phil 1
        semdec(forksSemaphores[0]);
        std::cout << PHIL1 << TAKE_LEFT;
        sleep(SLEEP_TIME);
        semdec(forksSemaphores[1]);
        std::cout << PHIL1 << TAKE_RIGHT;
        sleep(SLEEP_TIME);
        std::cout << PHIL1 << EATS;
        seminc(forksSemaphores[0]);
        std::cout << PHIL1 << PUT_LEFT;
        sleep(SLEEP_TIME);
        seminc(forksSemaphores[1]);
        std::cout << PHIL1 << PUT_RIGHT;
        sleep(SLEEP_TIME);
    } else if (!fork()) {
        // phil 2
        semdec(forksSemaphores[1]);
        std::cout << PHIL2 << TAKE_LEFT;
        sleep(SLEEP_TIME);
        semdec(forksSemaphores[2]);
        std::cout << PHIL2 << TAKE_RIGHT;
        sleep(SLEEP_TIME);
        std::cout << PHIL2 << EATS;
        seminc(forksSemaphores[1]);
        std::cout << PHIL2 << PUT_LEFT;
        sleep(SLEEP_TIME);
        seminc(forksSemaphores[2]);
        std::cout << PHIL2 << PUT_RIGHT;
        sleep(SLEEP_TIME);
    } else if (!fork()) {
        // phil 3
        semdec(forksSemaphores[2]);
        std::cout << PHIL3 << TAKE_LEFT;
        sleep(SLEEP_TIME);
        semdec(forksSemaphores[3]);
        std::cout << PHIL3 << TAKE_RIGHT;
        sleep(SLEEP_TIME);
        std::cout << PHIL3 << EATS;
        seminc(forksSemaphores[2]);
        std::cout << PHIL3 << PUT_LEFT;
        sleep(SLEEP_TIME);
        seminc(forksSemaphores[3]);
        std::cout << PHIL3 << PUT_RIGHT;
        sleep(SLEEP_TIME);
    } else {
        // phil 4
        semdec(forksSemaphores[0]);
        std::cout << PHIL4 << TAKE_RIGHT;
        sleep(SLEEP_TIME);
        semdec(forksSemaphores[3]);
        std::cout << PHIL4 << TAKE_LEFT;
        sleep(SLEEP_TIME);
        std::cout << PHIL4 << EATS;
        seminc(forksSemaphores[0]);
        std::cout << PHIL4 << PUT_RIGHT;
        sleep(SLEEP_TIME);
        seminc(forksSemaphores[3]);
        std::cout << PHIL4 << PUT_LEFT;
        sleep(SLEEP_TIME);
    }

    return 0;
}