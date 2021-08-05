from sys import stdin

S = str(stdin.readline().rstrip())

for l in range(1, 4):
    f = S[:l]
    nxt, last = int(f), f

    i, tmp = 0, ""
    while i < len(S):
        cur = S[i:i+len(str(nxt))]
        if int(cur) != nxt:
            break
        tmp += cur
        i += len(str(nxt))
        nxt += 1

    if tmp == S:
        print(f, nxt-1)
        break