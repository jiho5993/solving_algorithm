import sys

dp = [0, 1]

if __name__ == '__main__':
    n = int(sys.stdin.readline())
    for i in range(2, n+1): dp.append(dp[i-1]+dp[i-2])
    print(dp[n])