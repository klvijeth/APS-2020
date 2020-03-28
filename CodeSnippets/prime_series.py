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
print(a[n-1])