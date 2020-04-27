import math
def isperfect(n):
    global arr
    if(n in arr):
        return 1
    else:
        if(n<arr[-1]):
            return 0
    for i in range(2,(n//2)+1):
        x=int(math.log(n,i))
        x=i**x
        if(x==n):
            arr.append(n)
            return 1
    return 0
def sum_func(n):
    s=0
    for i in range(1,int(math.sqrt(n)+1)):
        if(n%i==0):
            if(isperfect(i)):
                s+=i
            if(n!=i**2 and isperfect(n//i)):
                s+=n//i
    return s
t=int(input())
arr=[1]
arr1=[1]
for tt in range(t):
    n=int(input())
    s=0
    if(n<=len(arr1)):
        print(arr1[n-1])
    else:
        s=arr1[-1]
        l=len(arr1)+1
        for i in range(l,n+1):
            s+=sum_func(i)
            arr1.append(s)
        print(s)