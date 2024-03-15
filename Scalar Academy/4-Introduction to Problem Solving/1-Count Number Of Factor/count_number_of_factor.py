from math import sqrt

num=int(input())
factor=0
for i in range(1,int(sqrt(num))+1):
    if num%i==0:
        if num/i!=i:
            factor+=2
        else:
            factor+=1
print(factor)