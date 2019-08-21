from sys import stdin

paper = [[False]*101 for _ in range(101)]
rs = 0

if __name__ == '__main__':
    n = int(stdin.readline())
    for _ in range(n):
        a, b = map(int, stdin.readline().split())
        for i in range(a, a+10):
            for j in range(b, b+10):
                if not paper[i][j]: rs+=1
                paper[i][j] = True
    print(rs)