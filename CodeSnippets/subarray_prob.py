t=int(input())
for ww in range(t):
    n,k=input().split()
    n=int(n)
    k=int(k)
    l=list(map(int,input().split()))
    count=0
    for i in range(0,n):
        for j in range(i,n):
            a=[]
            for qq in range(i,j+1):
                a.append(l[qq])
            a.sort()
            s=j-i+1
            m=k/s
            x=int(k/s)
            if((m-x)==0):
                m=int(m)
                flag=1
            else:
                m=x+1
                flag=0
            if(flag==1):
                x=a[s-1]
                f=a.count(x)
                if(f in a):
                    count+=1
            elif(m==1):
                x=a[k-1]            
                f=a.count(x)
                if(f in a):
                    count+=1
            else:
                ind=(m*s)-k
                ind=int(ind/m)
                ind=int(s-ind-1)
                x=a[ind]
                f=a.count(x)
                if(f in a):
                    count+=1
    print(count)