from math import sqrt

A = int(input())
tmp=1
for i in range(2,int(sqrt(A))+1):
    if A%i==0:
        tmp+=i+A//i
if tmp==A:
    print("1")
else:
    print("0")