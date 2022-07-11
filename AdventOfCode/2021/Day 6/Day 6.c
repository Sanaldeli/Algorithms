#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 300

const int8_t input[MAX] = {4, 5, 3, 2, 3, 3, 2, 4, 2, 1, 2, 4, 5, 2, 2, 2, 4, 1, 1, 1, 5, 1, 1, 2, 5, 2, 1, 1, 4, 4, 5, 5, 1, 2, 1, 1, 5, 3, 5, 2, 4, 3, 2, 4, 5, 3, 2, 1, 4, 1, 3, 1, 2, 4, 1, 1, 4, 1, 4, 2, 5, 1, 4, 3, 5, 2, 4, 5, 4, 2, 2, 5, 1, 1, 2, 4, 1, 4, 4, 1, 1, 3, 1, 2, 3, 2, 5, 5, 1, 1, 5, 2, 4, 2, 2, 4, 1, 1, 1, 4, 2, 2, 3, 1, 2, 4, 5, 4, 5, 4, 2, 3, 1, 4, 1, 3, 1, 2, 3, 3, 2, 4, 3, 3, 3, 1, 4, 2, 3, 4, 2, 1, 5, 4, 2, 4, 4, 3, 2, 1, 5, 3, 1, 4, 1, 1, 5, 4, 2, 4, 2, 2, 4, 4, 4, 1, 4, 2, 4, 1, 1, 3, 5, 1, 5, 5, 1, 3, 2, 2, 3, 5, 3, 1, 1, 4, 4, 1, 3, 3, 3, 5, 1, 1, 2, 5, 5, 5, 2, 4, 1, 5, 1, 2, 1, 1, 1, 4, 3, 1, 5, 2, 3, 1, 3, 1, 4, 1, 3, 5, 4, 5, 1, 3, 4, 2, 1, 5, 1, 3, 4, 5, 5, 2, 1, 2, 1, 1, 1, 4, 3, 1, 4, 2, 3, 1, 3, 5, 1, 4, 5, 3, 1, 3, 3, 2, 2, 1, 5, 5, 4, 3, 2, 1, 5, 1, 3, 1, 3, 5, 1, 1, 2, 1, 1, 1, 5, 2, 1, 1, 3, 2, 1, 5, 5, 5, 1, 1, 5, 1, 4, 1, 5, 4, 2, 4, 5, 2, 4, 3, 2, 5, 4, 1, 1, 2, 4, 3, 2, 1};
uint64_t list[9] = {0};

void initList();
uint64_t simulate(int simulateFor);

int main() {
    printf("Part 1: %lu\n", simulate(80));
    printf("Part 2: %lu\n", simulate(256));

    return 0;
}

uint64_t simulate(int simulateFor) {
    uint64_t size;
    // 1) Reset the list
    initList();

    // 2) Simulate
    for (int i = 0; i < simulateFor; i++) {
        uint64_t temp = list[0];
        list[0] = list[1];
        list[1] = list[2];
        list[2] = list[3];
        list[3] = list[4];
        list[4] = list[5];
        list[5] = list[6];
        list[6] = list[7];
        list[7] = list[8];
        list[6] += temp;
        list[8] = temp;
    }
    // 3) Return how many fishes have populated
    size = 0;
    for (int i = 0; i < 9; i++) size += list[i];
    return size;
}

void initList() {
    // initialize list with zeros
    for (int i = 0; i < 9; i++) list[i] = 0;

    // how many fishes for each element
    for (int i = 0; i < MAX; i++)
        list[input[i]]++;
}