#pragma once

#include <float.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

const long double A = 0.0;
const long double B = 0.5;
const int64_t MAX_ITERATIONS = 100;
const int64_t N = 10;
long double step = (B - A) / N;
uint64_t k = 100000;

long double Func(long double x) {
    return (x * (3 - x)) / powl((1 - x), 3);
    return 0.0;
}

int Task() {
    printf("                f(x) = x(3 - x) / (1 - x)^3\n");
    printf(" -------------------------------------------------------------\n");
    printf("  x   |     Taylor series      |      Function       | Iters |\n");
    printf(" -------------------------------------------------------------\n");
    long double x = A;
    while (fabsl(x - B) < LDBL_EPSILON * k || x < B) {
        int iterations_count = 1;
        long double sum_of_taylor = 0;
        while (iterations_count < MAX_ITERATIONS) {
            sum_of_taylor += (iterations_count * (iterations_count + 2)) * powl(x, iterations_count);
            if (fabsl(sum_of_taylor - Func(x)) >= LDBL_EPSILON * k) {
                iterations_count += 1;
            } else {
                printf(" %0.2Lf | %20.20Lf |% 20.15Lf | %5d |\n", x, sum_of_taylor, Func(x), iterations_count);
                printf(" -------------------------------------------------------------\n");
                break;
            }
        }
        x += step;
    }
    return 0;
}