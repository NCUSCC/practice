#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#define N 500  // 使用500x500矩阵进行测试

void multiply(std::vector<std::vector<int>>& mat1, std::vector<std::vector<int>>& mat2, std::vector<std::vector<int>>& res) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            res[i][j] = 0;
            for (int k = 0; k < N; k++)
                res[i][j] += mat1[i][k] * mat2[k][j];
        }
    }
}

int main() {
    std::vector<std::vector<int>> mat1(N, std::vector<int>(N)), mat2(N, std::vector<int>(N)), res(N, std::vector<int>(N));
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

    std::cout << "Matrix multiplication took " << time_taken << " seconds to execute \n";
    return 0;
}