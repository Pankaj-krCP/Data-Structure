from math import sqrt

n = int(input())
ans = -1
for i in range(1,int(sqrt(n))+1):
    if i*i==n:
        ans=i
        break
print(ans)