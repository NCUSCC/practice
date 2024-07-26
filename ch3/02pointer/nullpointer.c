#include <stdio.h>

int main() {
    int a= 0;
    int *ptr = &a; // 未初始化的指针，指向未知的内存地址

    // 尝试访问 ptr 所指向的值
    *ptr = 10; // 这行代码会导致未定义行为，可能会崩溃
    printf("Value pointed by ptr: %d\n", *ptr); // 可能导致崩溃

    return 0;
}