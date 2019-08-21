from sys import stdin

if __name__ == '__main__':
    n, k = map(int, stdin.readline().split())
    arr = list(map(int, stdin.readline().split(',')))
    for i in range(k):
        for j in range(n-i-1):
            arr[j] = arr[j+1]-arr[j]
    for i in range(n-k):
        if i == n-k-1: print(arr[i])
        else: print(arr[i], end=',')