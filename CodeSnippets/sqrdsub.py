t=int(input())
for tt in range(t):
    n=int(input())
    l=list(map(int,input().split()))
    c=0
    tl=[]
    fl=[]
    ind1=0
    ind2=0
    for i in range(n):
        if(l[i]%4==0):
            l[i]=4
            fl.append(i)
        elif(l[i]%2==0):
            l[i]=2
            tl.append(i)
    
    ww=len(tl)
    pp=len(fl)
    for i in range(n):
        if(ind1<ww and i>tl[ind1]):
            ind1+=1
        if(ind2<pp and i>fl[ind2]):
            ind2+=1
        if(l[i]%2!=0):
            c+=1
            try:
                xx=len(tl[ind1:])
            except:
                xx=0
            if(xx==0):
                c+=n-(i+1)
            elif(xx==1):
                k=tl[ind1]-i-1
                j=0
                try:
                    j=fl[ind2]
                    c+=n-(j+1)+1
                    c+=min(j-i-1,k)
                except:
                    ty=1
                    c+=k
            else:
                j=tl[ind1]-i-1
                k=j
                j=tl[ind1+1]
                try:
                    qq=fl[ind2]
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
                    j=tl[ind1+1]
                except:
                    j=n
                try:
                    qq=fl[ind2]
                except:
                    qq=n+1
                j=min(j,qq)
                c+=n-(j+1)+1
    print(c)