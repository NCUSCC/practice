#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int *p = arr;

    // 修改数组元素
    for (int i = 0; i < 5; i++) {
        *(p + i) += 10;
    }

    // 打印修改后的数组
    for (int i = 0; i < 5; i++) {
        printf("Element %d: %d\n", i, *(p + i));
    }

    return 0;
}
