import sys

if __name__ == '__main__':
    s, n = 1, int(sys.stdin.readline())
    for i in range(1, n+1): s *= i
    print(s)