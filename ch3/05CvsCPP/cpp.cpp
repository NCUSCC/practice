#include <iostream> // 包含输入输出流库
using namespace std; // 使用标准命名空间

// 定义一个名为 Numbers 的类
class Numbers {
private:
    int* data; // 指向整数数组的指针
    int size; // 数组的大小
public:
    // 构造函数，接受一个整数参数 size
    Numbers(int size) : size(size) {
        data = new int[size]; // 动态分配内存
        for (int i = 0; i < size; i++) {
            data[i] = i + 1; // 初始化数组，值为 1 到 size
        }
    }
    // 析构函数，释放动态分配的内存
    ~Numbers() {
        delete[] data; // 释放内存
    }
    // 打印数组中的所有元素
    void print() {
        for (int i = 0; i < size; i++) {
            cout << data[i] << endl; // 输出每个元素的值
        }
    }
};

int main() {
    Numbers numbers(5); // 创建一个 Numbers 对象，数组大小为 5
    numbers.print(); // 调用 print 方法，打印数组中的所有元素
    return 0; // 返回 0，表示程序成功结束
}