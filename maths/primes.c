/*
    For generating a large amount of primes, up to a certain number
    Not the most efficient ever but it works
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef unsigned long positive;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        puts("Usage: ./primes `n` (where `n` is the number to go up to)");
        return 0;
    }

    char *ptr[10];
    positive x;
    positive len = strtol(argv[1], ptr, 10);
    positive *nums = malloc(len * sizeof(positive));
    for (positive i = 0; i < len; i++) {
        nums[i] = true;
    }

    for (positive i = 2; i <= pow(len, .5); i++) {
        if (nums[i]) {
            for (positive j = pow(i, 2); j <= len; j += i) {
                nums[j] = false;
            }
        }
    }

    for (positive i = 2; i <= len; i++) {
        if (nums[i]) {
            printf("%ld\n", i);
        }
    }

    return 0;
}
