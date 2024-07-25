#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int *)malloc(sizeof(int)); // 动态分配内存
    *ptr = 42;
    printf("Value: %d\n", *ptr);

    free(ptr); // 释放内存
    // 此时 ptr 变为野指针，指向已释放的内存区域

    // 继续使用野指针
    printf("After free: %d\n", *ptr); // 未定义行为，可能输出垃圾值或崩溃

    return 0;
}