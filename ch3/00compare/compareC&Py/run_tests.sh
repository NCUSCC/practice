#!/bin/bash

# 运行次数
RUNS=100

# 初始化总时间
total_time_python=0
total_time_c=0

# 运行 Python 程序并记录总时间
echo "Running Python script..."
for i in $(seq 1 $RUNS); do
    start_time=$(date +%s.%N)
    python3 sum_squares.py > /dev/null
    end_time=$(date +%s.%N)
    elapsed=$(echo "$end_time - $start_time" | bc)
    total_time_python=$(echo "$total_time_python + $elapsed" | bc)
done

echo "Total time for Python ($RUNS runs): $total_time_python seconds"

# 运行 C 程序并记录总时间
echo "Running C program..."
for i in $(seq 1 $RUNS); do
    start_time=$(date +%s.%N)
    ./sum_squares > /dev/null
    end_time=$(date +%s.%N)
    elapsed=$(echo "$end_time - $start_time" | bc)
    total_time_c=$(echo "$total_time_c + $elapsed" | bc)
done

echo "Total time for C ($RUNS runs): $total_time_c seconds"