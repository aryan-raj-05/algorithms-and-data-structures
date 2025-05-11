#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdio.h>
#include <stdlib.h>

#define FACTOR 2

typedef struct {
    int *a;
    int size;
    int capacity;
    int timesResized; // for tests
} array;

void initArray(array *arr);

int at(array *arr, int index);

int find(array *arr, int value);

void push(array *arr, int value);

void insert_at(array *arr, int index, int value); // TODO

void pop(array *arr);

void remove_at(array *arr, int index); // TODO

void delete_arr(array *arr);

void print_arr(array *arr);

#endif