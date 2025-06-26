#include "vector.h"

void initVector(vector* v) {
    v->items = (int*)malloc(sizeof(int) * INIT_SIZE);
    v->size = 0;
    v->capacity = INIT_SIZE;
}

void push_back(vector* v, int item) {
    if ((v->size) >= (v->capacity)) {
        int newSize = v->capacity * GROWTH_FACTOR;
        v->capacity = newSize;
        v->items = (int*)realloc(v->items, newSize * sizeof(int));
    }
    v->items[v->size++] = item;
}

int itemAt(const vector* v, int index) {
    if (index < 0 || index >= v->size) {
        fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    return v->items[index];
}

void freeVector(vector* v) {
    free(v->items);
    v->size = 0;
    v->capacity = 0;
}

void printVector(const vector* v) {
    printf("Size of Vector: %d\n", v->size);
    printf("Max Capacity: %d\n", v->capacity);
    printf("Items in the Vector are:\n");
    for(int i = 0; i < (v->size); i++) {
        printf("%d ", itemAt(v, i));
    }
    printf("\n");
}