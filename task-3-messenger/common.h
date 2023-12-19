#ifndef OS_EXAM_PREP_COMMON_H
#define OS_EXAM_PREP_COMMON_H

#include <ostream>
#include <unistd.h>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <random>
#include <sys/msg.h>
#include <string.h>

struct Message {
    long key;
    char text[100];
};

#endif //OS_EXAM_PREP_COMMON_H
