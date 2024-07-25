#include <stdio.h>

// 递归函数
void causeStackOverflow(int depth) {
    int arr[1000]; // 分配一个相对较大的数组来增加栈使用量
    printf("Recursion depth: %d, Array address: %p\n", depth, (void*)arr);
    causeStackOverflow(depth + 1); // 递归调用，增加栈深度
}

int main() {
    // 程序开始时的栈深度
    int initialDepth = 1;

    // 开始递归调用，导致栈溢出
    causeStackOverflow(initialDepth);

    return 0;
}