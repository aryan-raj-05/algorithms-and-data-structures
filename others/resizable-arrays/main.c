#include "vector.h"

#include <stdio.h>

int main() {
    vector v;
    int n = 9;

    initVector(&v);

    for(int i = 0; i < n; i++) {
        push_back(&v, i * 2);
    }

    printVector(&v);

    freeVector(&v);
}