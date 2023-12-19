#include <sys/shm.h>
#include <iostream>
#include <unistd.h>
#include <sys/sem.h>

void seminc(int sem)
{
    struct sembuf op;
    op.sem_num = 0;
    op.sem_op = 1;
    op.sem_flg = 0;
    semop(sem, &op, 1);
}

void semdec(int sem)
{
    struct sembuf op;
    op.sem_num = 0;
    op.sem_op = -1;
    op.sem_flg = 0;
    semop(sem, &op, 1);
}

int main()
{
    int fs[4] = {semget(23450, 1, IPC_CREAT|0660), semget(23467, 1, IPC_CREAT|0660), semget(23478, 1, IPC_CREAT|0660), semget(23489, 1, IPC_CREAT|0660)};
    semctl(fs[0], 0, SETVAL, 1);
    semctl(fs[1], 0, SETVAL, 1);
    semctl(fs[2], 0, SETVAL, 1);
    semctl(fs[3], 0, SETVAL, 1);

    int cycles = 2;
    int sem_val;
    int sleep_time = 3;
    int wait_time = 1;
    int c = 0;

    if (!fork())
    {
        if (!fork())
        {
            while (c < cycles)
            {
                semdec(fs[0]);
                std::cout << "0: right-\n";
                sleep(wait_time);
                semdec(fs[1]);
                std::cout << "0: left-\nphilosopher 0 ate " << c + 1 << " times\n";
                sleep(wait_time);
                seminc(fs[0]);
                std::cout << "0: right+\n";
                sleep(wait_time);
                seminc(fs[1]);
                std::cout << "0: left+\n";
                c++;
                sleep(sleep_time);
            }
            return 0;
        }
        else
        {
            while (c < cycles)
            {
                semdec(fs[1]);
                std::cout << "1: right-\n";
                sleep(wait_time);
                semdec(fs[2]);
                std::cout << "1: left-\nphilosopher 1 ate "<< c + 1 <<" times\n";
                sleep(wait_time);
                seminc(fs[1]);
                std::cout << "1: right+\n";
                sleep(wait_time);
                seminc(fs[2]);
                std::cout << "1: left+\n";
                c++;
                sleep(sleep_time);
            }
        }
        return 0;
    }
    else
    {
        if (!fork())
        {
            while (c < cycles)
            {
                semdec(fs[2]);
                std::cout << "2: right-\n";
                sleep(wait_time);
                semdec(fs[3]);
                std::cout << "2: left-\nphilosopher 2 ate "<< c + 1 <<" times\n";
                sleep(wait_time);
                seminc(fs[2]);
                std::cout << "2: right+\n";
                sleep(wait_time);
                seminc(fs[3]);
                std::cout << "2: left+\n";
                c++;
                sleep(sleep_time);
            }
            return 0;
        }
        else
        {
            while (c < cycles)
            {
                semdec(fs[0]);
                std::cout << "3: left-\n";
                sleep(wait_time);
                semdec(fs[3]);
                std::cout << "3: right-\nphilosopher 3 ate "<< c + 1 <<" times\n";
                sleep(wait_time);
                seminc(fs[0]);
                std::cout << "3: left+\n";
                sleep(wait_time);
                seminc(fs[3]);
                std::cout << "3: right+\n";
                c++;
                sleep(sleep_time);
            }
        }
    }
    return 0;
}