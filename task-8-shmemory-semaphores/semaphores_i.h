#ifndef OS_EXAM_PREP_SEMAPHORES_I_H
#define OS_EXAM_PREP_SEMAPHORES_I_H

#include <sys/sem.h>

/**
 * Increments semaphore.
 * @param sem id of semaphore to increment.
 */
void seminc(int sem) {
    struct sembuf op{};
    op.sem_num = 0;
    op.sem_op = 1;
    op.sem_flg = 0;
    semop(sem, &op, 1);
}

/**
 * Decrements semaphore.
 * @param sem id of semaphore to decrement.
 */
void semdec(int sem) {
    struct sembuf op{};
    op.sem_num = 0;
    op.sem_op = -1;
    op.sem_flg = 0;
    semop(sem, &op, 1);
}

#endif
