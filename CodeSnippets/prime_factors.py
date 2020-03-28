import math
def is_prime(n):
    flag=0
    if(n==2):
        return True
    for i in range(2,int(math.sqrt(n))):
        if(n%i==0):
            return False
    return True
t=int(input())
for tt in range(t):
    n=int(input())
    if(n<2):
        print(0)
    else:
        count=0
        for i in range(2,int(math.sqrt(n))+1):
            if((n%i==0)):
                if(is_prime(i)):
                    count+=1
                if(is_prime(n//i)):
                    count+=1
        if(is_prime(n)):
            count+=1
        print(count)