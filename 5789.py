if __name__ == '__main__':
    n = int(input())
    for _ in range(n):
        a = str(input())
        chk = False
        for i in range(0, len(a)//2):
            if a[i] == a[len(a)-i-1]: chk = True
            else: chk = False
        if chk: print("Do-it")
        else: print("Do-it-Not")