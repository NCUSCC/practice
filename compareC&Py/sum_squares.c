// sum_squares.c
#include <stdio.h>

unsigned long long sum_of_squares(int n) {
    unsigned long long total = 0;
    for (int i = 0; i < n; i++) {
        total += i * i;
    }
    return total;
}

int main() {
    unsigned long long result = sum_of_squares(1000000);
    printf("%llu\n", result);
    return 0;
}