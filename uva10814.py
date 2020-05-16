from math import gcd 

n = int(input())

for i in range(n):
    inn = input()
    a, b = inn.strip('\n').split(' / ')
    a = int(a); b = int(b)
    print(a//gcd(a, b), '/' ,b//gcd(a, b))
