#include "utils.h"

void initPh(int id, int state){
    Philosopher philosopher = {id, state};
}

void seminc(int sem, int sem_op){
    struct sembuf op;
    op.sem_num = 0;
    op.sem_op = sem_op;
    op.sem_flg = 0;
    semop(sem, &op,1);
}

int main(){
    int numberOfPh = 5;

    char statePh[6][20] = {"thinking", "wants to eat", "takes left fork",
                           "takes right fork", "eating", "puts forks"
    };

    Philosopher philosophers[numberOfPh];

    for (int i = 0; i < numberOfPh; ++i) {
        if (!fork()){

        }
    }

}