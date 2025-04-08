#include <stdio.h>

#include "dynamic_array.h"

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Error: Incorrect Use\n");
        exit(-1);
    }

    int length = atoi(argv[1]);

    array list;
    initArray(&list);

    for (int i = 0; i < length; i++) {
        push(&list, i);
    }

    // print_arr(&list);

    printf("\n\n");
    printf("Details of the array: \n");
    printf("Current Capacity: %d\n", list.capacity);
    printf("Space Occupied: %d\n", list.size);
    printf("Times Resized: %d\n", list.timesResized);

    delete_arr(&list);
}