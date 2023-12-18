#ifndef OS_EXAM_PREP_UTILS_H
#define OS_EXAM_PREP_UTILS_H

#include <ostream>
#include <unistd.h>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <random>
#include <sys/msg.h>
#include <sys/sem.h>
#include <sys/shm.h>
#define INDEX 26129


struct Philosopher{
    int id;
    int state;
};


#endif //OS_EXAM_PREP_UTILS_H
