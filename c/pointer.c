#include <stdio.h>

// 1. 指针函数：返回指针的函数
int* pointer_function(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] *= 2;
    }
    return arr;
}

// 2. 函数指针：指向函数的指针
void print_hello() {
    printf("Hello, World!\n");
}

void print_number(int num) {
    printf("Number: %d\n", num);
}

int main() {
    // 3. 指针的基础概念
    int a = 42;
    int *p = &a;
    printf("3. 指针 p 存储的地址: %p\n", (void *)p);
    printf("   a 的值: %d, p 指向的值: %d\n", a, *p);

    // 4. 指针的加减法
    int b = 10;
    int *q = &b;
    printf("4. 指针 q 的地址: %p\n", (void *)q);
    q++;
    printf("   q++ 后的地址: %p\n", (void *)q);
    q--;
    printf("   q-- 后的地址: %p\n", (void *)q);

    // 5. 指针和数组的关系
    int arr[3] = {1, 2, 3};
    int *arr_ptr = arr;
    printf("5. 数组 arr 的地址: %p\n", (void *)arr);
    printf("   arr_ptr 的值: %p\n", (void *)arr_ptr);
    printf("   通过指针访问数组元素: %d, %d, %d\n", arr_ptr[0], arr_ptr[1], arr_ptr[2]);

    // 使用指针函数
    int *new_arr = pointer_function(arr, 3);
    printf("   调用指针函数后数组元素: %d, %d, %d\n", new_arr[0], new_arr[1], new_arr[2]);

    // 6. 指向指针的指针
    int **pp = &p;
    printf("6. 指向指针的指针 pp 的地址: %p\n", (void *)pp);
    printf("   pp 指向的值(即 p 的地址): %p\n", (void *)*pp);
    printf("   通过 pp 访问 a 的值: %d\n", **pp);

    // 7. 函数指针的使用
    void (*func_ptr)();
    func_ptr = print_hello;
    printf("7. 函数指针 func_ptr 存储的地址: %p\n", (void *)func_ptr);
    func_ptr(); // 调用 print_hello 函数

    // 使用带参数的函数指针
    void (*num_func_ptr)(int);
    num_func_ptr = print_number;
    num_func_ptr(5);

    return 0;
}