# sum_squares.py
def sum_of_squares(n):
    total = 0
    for i in range(n):
        total += i * i
    return total

if __name__ == "__main__":
    result = sum_of_squares(1000000)
    print(result)