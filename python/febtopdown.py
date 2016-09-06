def feb(n, dp):
    if dp[n] is  not None:
        return dp[n]
    if n<2:
        dp[n]=n
    else:
        dp[n] = feb(n-1, dp) + feb(n-2, dp)
    return dp[n]

n=2
dp=[None]*(n+1)
print(feb(n, dp))




































