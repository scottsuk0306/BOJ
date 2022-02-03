n, m = map(int, input().split())
dp = [[0] * (m+1) for _ in range(n+1)]

def go(n, m):
    if n==m:
        return 1
    elif m==1:
        return n
    else:
        if dp[n][m] != 0:
            return dp[n][m]
        else:
            dp[n][m] = go(n-1, m-1) + go(n-1, m)
            return dp[n][m]

print(go(n, m))