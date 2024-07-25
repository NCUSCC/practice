#include <stdio.h>  // 包含标准输入输出库的头文件

int main() {
    // 定义四种基本数据类型的变量
    int intVar;         // 整数类型，通常占用 4 字节
    float floatVar;     // 浮点类型，用于存储小数，通常占用 4 字节
    double doubleVar;   // 双精度浮点类型，精度比 float 高，通常占用 8 字节
    char charVar;       // 字符类型，用于存储单个字符，通常占用 1 字节

    // printf 是标准输入输出库中的一个函数，用于打印格式化的输出到屏幕上
    // %zu 是一种格式说明符，用于打印 size_t 类型的整数（通常是无符号整数）
    // %p 是一种格式说明符，用于打印指针地址
    // sizeof 运算符用于计算数据类型或变量的大小，以字节为单位
    // & 运算符用于获取变量的地址

    printf("Size and address of int: %zu bytes, %p\n", sizeof(intVar), (void*)&intVar);
    // 打印 int 类型变量的大小和地址
    // (void*)&intVar 将 intVar 的地址强制转换为 void* 类型，以符合 %p 的要求

    printf("Size and address of float: %zu bytes, %p\n", sizeof(floatVar), (void*)&floatVar);
    // 打印 float 类型变量的大小和地址

    printf("Size and address of double: %zu bytes, %p\n", sizeof(doubleVar), (void*)&doubleVar);
    // 打印 double 类型变量的大小和地址

    printf("Size and address of char: %zu bytes, %p\n", sizeof(charVar), (void*)&charVar);
    // 打印 char 类型变量的大小和地址

    return 0;  // 返回 0 表示程序成功结束
}