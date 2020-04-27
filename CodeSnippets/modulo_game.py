t=int(input())
for i in range(0,t):
        a=list(map(int,input().split()))
        n=a[0]
        p=a[1]
        k=(n//2)+1
        m=n%k
        x=(p-m)*(p-m)
        if(n==1 or n==2):
            w=p*p*p
            print(w)
        elif(n==p):
            print(x)
        else:
            v=x+((p-n)*(p-n))+((p-n)*(p-m))
            print(v)