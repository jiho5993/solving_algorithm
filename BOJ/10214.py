n = int(input())
for _ in range(n):
    Y, K = 0, 0
    for _ in range(9):
        b, c = map(int, input().split())
        Y, K = Y+b, K+c
    if Y == K: print("Draw")
    elif Y > K: print("Yonsei")
    else: print("Korea")
