#include "dynamic_array.h"

static void expand(array *arr) {
    int *new_array = realloc(arr->a, arr->capacity * FACTOR * sizeof(int));
    if (new_array == NULL) {
        fprintf(stderr, "Memory Allocation failed\n");
        exit(-1);
    }
    arr->a = new_array;
    arr->capacity *= 2;
    arr->timesResized++; // testing
}

static void shrink(array *arr) {
    if ((arr->size <= 8) || (arr->size * 4) >= (arr->capacity)) {
        return;
    }

    int new_capacity = arr->capacity / FACTOR;
    int *new_array = realloc(arr->a, new_capacity * sizeof(int));
    if (new_array == NULL) {
        fprintf(stderr, "Memory Allocation failed\n");
        exit(-1);
    }
    arr->a = new_array;
    arr->capacity = new_capacity;

    arr->timesResized++; // for testing
}

void initArray(array *arr) {
    arr->a = (int *) malloc(8 * sizeof(int));
    arr->capacity = 8;
    arr->size = 0;
    arr->timesResized = 0;  // testing
}

int at(array *arr, int index) {
    if (index >= arr->size || index < 0) {
        fprintf(stderr, "Index Out of Bounds");
        return __INT_MAX__;
    }
    return arr->a[index];
}

int find(array *arr, int value) {
    for(int i = 0; i < arr->size; i++) {
        if (arr->a[i] == value) {  return i;  }
    }
    return -1;
}

void push(array *arr, int value) {
    if (arr->size >= arr->capacity) {  expand(arr);  }
    arr->a[arr->size++] = value;
}

void insert_at(array *arr, int index, int value) { // TODO
    if (index = arr->size) {
        push(arr, value);
        return;
    }
}

void pop(array *arr) {
    if (arr->size == 0) {  return;  }
    arr->size--;
    shrink(arr);
}

void remove_at(array *arr, int index) { // TODO
    if (index == arr->size - 1) {  
        pop(arr);
        return;
    }
}

void delete_arr(array *arr) {
    free(arr->a);
    arr->a = NULL;
    arr->size = 0;
    arr->capacity = 0;
}

void print_arr(array *arr) {
    printf("[ ");
    for(int i = 0; i < arr->size; i++) {
        printf("%d", arr->a[i]);
        if (i < arr->size - 1) {  printf(", ");  }
    }
    printf(" ]\n");
}