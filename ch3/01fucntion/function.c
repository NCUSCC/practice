#include <stdio.h>

// 函数：将传入的整数加一，并返回新的值
// 这是一个简单的函数，它接收一个整数参数并返回该参数加一的结果。
// 注意：这个函数接收的是参数的副本，而不是原始变量。
int increment(int a) {
    a = a + 1; // 这里的 a 是 main 函数中传入的 x 的副本
    return a;  // 返回加一后的值，这里也是副本的值
}

// 函数：将传入的整数加一（指针版本）
// 这个函数接收一个指向整数的指针，通过指针直接修改原始数据。
// 注意：虽然传递的是指针，但指针本身也是一个副本。
void incrementPointer(int *a) {
    *a = *a + 1; // 通过指针修改原始数据的值
}

// 函数：尝试改变指针的地址
// 这个函数演示了即使传递指针，函数内的修改也不会影响到原始的指针。
// 函数尝试修改指针 a 的指向，但这只是修改了指针副本的值。
void changePointer(int *a) {
    int b = 10;
    a = &b;  // 尝试改变指针 a 的地址，使其指向本地变量 b
    *a = *a + 1; // 实际上修改的是 b 的值，而不是 main 函数中的变量
}

int main() {
    int x = 5;      // 定义一个整数变量 x
    int result;     // 用于存储 increment 函数的返回值

    // 传递 x 的副本到 increment 函数
    // 在这个函数调用中，x 的值被传递给 increment 函数，increment 函数内对 a 的修改
    // 并不会影响到 main 函数中的 x。increment 返回加一后的值，被存储在 result 中。
    result = increment(x);
    printf("Original x: %d, Incremented result: %d\n", x, result); // x 不变, result 为6

    // 使用指针传递 x 的地址
    // 这里传递的是 x 的地址，incrementPointer 函数通过指针直接修改 x 的值。
    incrementPointer(&x);
    printf("Original x after pointer increment: %d\n", x); // x 被改变为6

    // 尝试改变指针的地址
    // 虽然在函数中修改了指针 a 的值，使其指向一个新的地址 b，但这不会影响到
    // main 函数中的 x，因为传递的指针也是副本。
    changePointer(&x);
    printf("Original x after trying to change pointer: %d\n", x); // x 保持不变

    return 0;
}