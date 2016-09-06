dp = [[0]*(100) for i in range(0, 100)]

def botuplcs(s1, s2):
    for i in range(0, len(s1)+1):
        for j in range(0, len(s2)+1):
            if i == 0 or j == 0:
                dp[i][j] = 0
            elif s1[i-1] == s2[j-1]:
                dp[i][j] = dp[i-1][j-1] + 1
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])


s1 = input()
s2 = input()
botuplcs(s1, s2)
for i in range(len(s1)+1):
    for j in range(len(s2)+1):
        print(dp[i][j], end=" ")
    print()


