MAX = 1000000
prime = [True for i in range(MAX + 1)] 
def SieveOfEratosthenes(): 
    prime[1] = False
    for p in range(2, MAX + 1): 
        if (prime[p] == True): 
            i = p * 2
            while(i <= MAX): 
                prime[i] = False
                i = i + p 
def solve(n,a): 
    count = 0
    num = 1 
    total = 0  
    while (count < n): 
        if ( prime[num] ):  
            a.append(num) 
            count = count + 1 
        num = num + 1   
    return total 
SieveOfEratosthenes() 
n = 50000
a=[]
solve(n,a)
t=int(input())
for q in range(t):
    n=int(input())
    l=[]
    count=1
    i=0
    j=1
    while(count!=n+1):
        x=a[i]*a[j]
        l.append(x)
        i+=1
        j+=1
        count+=1
    l[n-1]=a[i-1]*2
    temp=' '.join(str(i) for i in l)
    print(temp)