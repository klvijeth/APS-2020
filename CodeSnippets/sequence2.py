MAX = 1000000
prime = [True for i in range(MAX + 1)] 
def prime_seq(): 
    prime[1] = False
    for p in range(2, MAX + 1): 
        if (prime[p] == True): 
            i = p * 2
            while(i <= MAX): 
                prime[i] = False
                i = i + p 
def solve(n,primes): 
    cnt = 0
    num = 1 
    total = 0  
    while (cnt < n): 
        if ( prime[num] ):  
            primes.append(num) 
            cnt = cnt + 1 
        num = num + 1   
    return total 
prime_seq() 
n = 50005
primes=[]
solve(n,primes)
t=int(input())
for q in range(t):
    n=int(input())
    seq=[]
    cnt=0
    i=3
    k=2
    tmp=0
    j=1
    seq.append(6)
    flag=0
    while(cnt<n-1):
        if(flag==1):
            tmp=i
            i=k
            k=tmp
            flag=0
        if(cnt%2==0):
            j+=1
            flag=1
        x=i*primes[j]
        seq.append(x)
        cnt+=1
    if(seq[n-1]%3==0 and seq[n-2]%3==0):
        if(n<5):
            seq[n-2]=primes[j-1]*primes[j]
            seq[n-1]=primes[j]*2
        else:
            seq[n-2]=5*primes[j-1]
            seq[n-1]=40
    if(seq[n-1]%2==0 and seq[n-2]%2==0):
        if(n<3500):
            seq[n-2]=primes[j-1]*primes[j]
            seq[n-1]=primes[j]*2
        else:
            seq[n-2]=5*primes[j-1]
            seq[n-1]=40
    if(seq[n-1]%3==0 and seq[n-2]%2==0):
        if(n<3500):
            seq[n-3]=primes[j-1]*primes[j]
            seq[n-2]=primes[j]*primes[j+1]
            seq[n-1]=primes[j+1]*2
        else:
            seq[n-3]=primes[j-1]*5
            seq[n-2]=5*primes[j]
            seq[n-1]=primes[j]*2
    tmp=' '.join(str(i) for i in seq)
    print(tmp)
