from math import sqrt

A=int(input())
for i in range(2,int(sqrt(A))+1):
    if A%i==0:
        print("0")
        break
else:
    print("1")