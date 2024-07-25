#include <stdio.h>

int main() {
    int numbers[] = {10, 20, 30, 40, 50};
    int sum = 0;
    int n = sizeof(numbers) / sizeof(numbers[0]);

    for(int i = 0; i < n; i++) {
        sum += numbers[i];
    }

    double average = (double)sum / n;
    printf("The average is: %.2f\n", average);

    return 0;
}
