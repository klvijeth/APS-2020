t=int(input())
for tt in range(t):
    n=int(input())
    l=list(map(int,input().split()))
    c=0
    for i in range(n):
        if(l[i]%4==0):
            l[i]=4
        elif(l[i]%2==0):
            l[i]=2
    for i in range(n):
        if(l[i]%2!=0):
            c+=1
            try:
                xx=l[i+1:].count(2)
            except:
                xx=0
            if(xx==0):
                c+=n-(i+1)
            elif(xx==1):
                k=l[i+1:].index(2)
                j=0
                try:
                    j=l[i:].index(4)+i
                    c+=n-(j+1)+1
                    c+=min(j-i-1,k)
                except:
                    ty=1
                    c+=k
            else:
                j=l[i+1:].index(2)
                k=j
                j+=i+2
                j+=l[j:].index(2)
                try:
                    qq=i+l[i+1:].index(4)+1
                except:
                    qq=n+1
                j=min(j,qq)
                c+=n-(j+1)+1
                c+=min(qq-1-i,k)
        else:
            if(l[i]%4==0):
                c+=n-(i+1)+1
            else:
                try:
                    j=l[i+1:].index(2)+1+i
                except:
                    j=n
                try:
                    qq=l[i+1:].index(4)+i+1
                except:
                    qq=n+1
                j=min(j,qq)
                c+=n-(j+1)+1
        print(c)
    print(c)