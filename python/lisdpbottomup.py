def lis(arr):
    n = len(arr)
    list = [1] * (n)
    for i in range(1, n):
        for j in range(0, i):
            if arr[i]>arr[j] and list[j]+1 > list[i]:
                list[i]=list[j]+1
    maxi = 0
    for i in range(0, n):
        if list[i] > maxi:
            maxi=list[i]
    return maxi

n=10
arr = [None]*(n)
for i in range(0, 10):
    arr[i]=eval(input())
print(lis(arr))