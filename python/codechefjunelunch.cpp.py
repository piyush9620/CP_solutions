import math
t=int(raw_input())
a=[1000000000000000]*(1000)
for z in range(0, t):
    n=int(raw_input())
    ans=1
    for i in range(0, n):
        a[i]=int(raw_input())
        ans=ans*a[i]
    print(int(math.sqrt(ans)))
