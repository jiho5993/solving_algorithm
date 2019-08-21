from sys import stdin

if __name__ == '__main__':
    n = int(stdin.readline())
    for _ in range(n):
        b = (stdin.readline()).split(' ')
        b[0] = "god"
        for i in b: print(i, end='')