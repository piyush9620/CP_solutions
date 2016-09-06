def feb(n, dp):
    for i in range(2, n):
        dp[i]=dp[i-1]+dp[i-2]

n=10
dp=[0]*(n+1)
dp[0]=0
dp[1]=1
feb(n, dp)
print(dp[n])