import sys

def fac(a):
    s = 1
    for i in range(1, a+1): s *= i
    return s

if __name__ == '__main__':
    n, k = map(int, sys.stdin.readline().split())
    print(int(fac(n)/(fac(k)*fac(n-k))))