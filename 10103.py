ch, sa = 100, 100
n = int(input())
for _ in range(n):
    b, c = map(int, input().split())
    if b < c: ch -= c
    elif b > c: sa -= b
print(ch)
print(sa)