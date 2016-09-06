ans = 0;
dp = [[None]*(100) for i in range(0, 100)]

def lca(s1, s2, n, m):
    if dp[n][m] is not None:
        return dp[n][m]
    if n == 0 or m == 0:
        dp[n][m] = 0
        return 0
    if s1[n-1] == s2[m-1]:
        ans = 1 + lca(s1, s2, n-1, m-1)
        dp[n][m] = ans
    else :
        ans = max(lca(s1, s2, n-1, m), lca(s1, s2, n, m-1))
        dp[n][m] = ans
    return ans


s1 = input()
s2 = input()

print(lca(s1, s2, len(s1), len(s2)))
print(dp[2][2])