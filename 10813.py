import sys

if __name__ == '__main__':
    n, m = map(int, sys.stdin.readline().split())
    arr = []
    for i in range(1, n + 1): arr.append(i)
    for _ in range(m):
        a, b = map(int, sys.stdin.readline().split())
        arr[a - 1], arr[b - 1] = arr[b - 1], arr[a - 1]
    for i in arr: print(i, end=' ')