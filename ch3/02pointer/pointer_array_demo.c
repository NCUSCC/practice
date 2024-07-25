#include <stdio.h>

int main() {
    // 定义一个整型数组
    int arr[5] = {1, 2, 3, 4, 5};

    // 1. 数组名作为指针
    // 数组名本身是一个指针，指向数组的第一个元素
    int *arrPtr = arr; // 等价于 int *arrPtr = &arr[0];
    
    // 输出数组的首地址和第一个元素的地址，验证它们是相同的
    printf("Address of arr: %p\n", (void*)arr);
    printf("Address of arr[0]: %p\n", (void*)&arr[0]);
    
    // 2. 数组访问的语法糖
    // 使用数组下标和指针偏移访问数组元素
    printf("arr[2] using array syntax: %d\n", arr[2]);
    printf("arr[2] using pointer syntax: %d\n", *(arr + 2));

    // 3. 指针和数组的互换
    // 指针可以通过指针偏移量访问数组元素
    int *p = arr; // 指针 p 指向数组 arr 的第一个元素
    printf("p[2]: %d\n", p[2]); // 使用指针下标访问
    printf("*(p + 2): %d\n", *(p + 2)); // 使用指针加法访问

    // 修改指针所指向的值
    *p = 10;
    printf("After modifying *p, arr[0]: %d\n", arr[0]); // 验证 arr[0] 的值改变

    // 通过指针修改数组的其他元素
    *(p + 1) = 20;
    printf("After modifying *(p + 1), arr[1]: %d\n", arr[1]); // 验证 arr[1] 的值改变

    // 输出整个数组
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    // 4. 指针的非典型用法：使用整数下标访问指针
    // 虽然不常见，但合法的用法：2[arr] 和 2[p]，它们等价于 arr[2] 和 p[2]
    // 因为 a[i] 实际上是 *(a + i)，而 (i + a) 也指向同样的位置
    printf("2[arr] = %d\n", 2[arr]); // 输出 30
    printf("2[p] = %d\n", 2[p]);     // 输出 30

    return 0;
}