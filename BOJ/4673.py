if __name__ == '__main__':
    arr = [False]*100001
    for i in range(1, 10001):
        a, b, s = str(i), int(i), int(i)
        for j in a: s += int(j)
        if s <= 10001: arr[s] = True
    for i in range(1, 10001):
        if not arr[i]: print(i)