import sys

def gcd(a, b):
    if b == 0: return a
    else: return gcd(b, a%b)

def lcm(a, b, c):
    return int((a*b)/c)

if __name__ == '__main__':
    n, k = map(int, sys.stdin.readline().split())
    a = int(gcd(n, k))
    print(a)
    print(lcm(n, k, a))