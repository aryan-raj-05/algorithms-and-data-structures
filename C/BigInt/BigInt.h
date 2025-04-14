#ifndef BIGINT_H
#define BIGINT_H

#include <stdlib.h>

typedef struct {
    u_int32_t digits[16];
    int size;
} BigInt;

#endif