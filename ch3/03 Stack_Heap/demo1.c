#include <stdio.h>
#include <stdlib.h>

void stackExample() {
    // 栈上的局部变量
    int stackVar = 10;
    printf("Stack variable value: %d, address: %p\n", stackVar, (void*)&stackVar);

    // 栈上的数组
    int stackArray[3] = {1, 2, 3};
    printf("Stack array values: %d, %d, %d\n", stackArray[0], stackArray[1], stackArray[2]);
    printf("Stack array address: %p\n", (void*)stackArray);
}

void heapExample() {
    // 在堆上分配单个整数大小的内存
    int *heapVar = (int*)malloc(sizeof(int));
    if (heapVar == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    *heapVar = 20;
    printf("Heap variable value: %d, address: %p\n", *heapVar, (void*)heapVar);

    // 在堆上分配一个整数数组
    int *heapArray = (int*)malloc(3 * sizeof(int));
    if (heapArray == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        free(heapVar); // 在失败前释放已分配的内存
        exit(EXIT_FAILURE);
    }
    heapArray[0] = 4;
    heapArray[1] = 5;
    heapArray[2] = 6;
    printf("Heap array values: %d, %d, %d\n", heapArray[0], heapArray[1], heapArray[2]);
    printf("Heap array address: %p\n", (void*)heapArray);

    // 释放堆内存
    free(heapVar);
    free(heapArray);
}

void stackDynamicArrayExample() {
    // 动态分配栈上的数组
    int n = 5;
    int stackArray[n]; // 这是C99标准允许的变长数组，实际是栈上的数组
    for (int i = 0; i < n; i++) {
        stackArray[i] = i + 1;
    }
    for (int i = 0; i < n; i++) {
        printf("Stack dynamic array element %d: %d\n", i, stackArray[i]);
    }
}

int main() {
    printf("--- Stack Example ---\n");
    stackExample();
    printf("--- Heap Example ---\n");
    heapExample();
    printf("--- Stack Dynamic Array Example ---\n");
    stackDynamicArrayExample();
    return 0;
}