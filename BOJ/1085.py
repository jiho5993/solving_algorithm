import sys

if __name__ == '__main__':
    x, y, w, h = map(int, sys.stdin.readline().split())
    a, b = w-x, h-y
    print(min(a, b, x, y))