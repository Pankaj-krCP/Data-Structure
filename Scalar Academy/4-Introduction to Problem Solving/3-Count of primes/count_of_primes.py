from math import sqrt

n=int(input())
count_primes = 0
if n>=2:
    count_primes = 1
for i in range(3,n+1):
    for j in range(2,int(sqrt(i))+1):
        if i%j==0:
            break
    else:
        count_primes+=1

print(count_primes)