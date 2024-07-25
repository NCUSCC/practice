#include <stdio.h>

int main() {
    // 1. 定义变量并打印它们的地址
    int x = 10; // 整数变量
    char c = 'A'; // 字符变量
    double d = 3.14; // 双精度浮点数变量

    // 打印每个变量的内存地址
    printf("Address of x: %p\n", (void*)&x);
    printf("Address of c: %p\n", (void*)&c);
    printf("Address of d: %p\n", (void*)&d);

    // 2. 定义指针并存储变量的地址
    int *intPointer = &x; // 指向整数的指针
    char *charPointer = &c; // 指向字符的指针
    double *doublePointer = &d; // 指向双精度浮点数的指针

    // 3. 通过指针访问和修改变量的值
    printf("Original value of x: %d\n", x);
    *intPointer = 20; // 通过指针修改 x 的值为 20
    printf("Modified value of x: %d\n", x);

    printf("Original value of c: %c\n", c);
    *charPointer = 'B'; // 通过指针修改 c 的值为 'B'
    printf("Modified value of c: %c\n", c);

    printf("Original value of d: %.2f\n", d);
    *doublePointer = 6.28; // 通过指针修改 d 的值为 6.28
    printf("Modified value of d: %.2f\n", d);

    return 0;
}