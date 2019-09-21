from sys import stdin

prime = [False]*1041

def eratos():
    for i in range(2, 1041):
        if not prime[i]:
            for j in range(2*i, 1041, i):
                prime[j] = True
eratos()

if __name__ == '__main__':
    s = 0
    for i in str(stdin.readline()):
        if i != '\n':
            if 'a' <= i <= 'z':
                s += ord(i)-ord('a')+1
            else: s += ord(i)-ord('A')+27
    if not prime[int(s)]: print("It is a prime word.")
    else: print("It is not a prime word.")