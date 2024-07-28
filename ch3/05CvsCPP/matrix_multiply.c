#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 500  // 使用500x500矩阵进行测试

void multiply(int mat1[][N], int mat2[][N], int res[][N]) {
    int i, j, k;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            res[i][j] = 0;
            for (k = 0; k < N; k++)
                res[i][j] += mat1[i][k] * mat2[k][j];
        }
    }
}

int main() {
    int mat1[N][N], mat2[N][N], res[N][N];
    srand(time(NULL));

    // 初始化矩阵
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            mat1[i][j] = rand() % 100;
            mat2[i][j] = rand() % 100;
        }
    }

    clock_t t;
    t = clock();
    multiply(mat1, mat2, res);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // 计算运行时间

    printf("Matrix multiplication took %f seconds to execute \n", time_taken);
    return 0;
}