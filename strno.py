t=int(input())
for tt in range(t):
    x,k=map(int,input().split())
    if(k==1 and x>1):
        print(1)
    else:
        qq=2**k
        flag=0
        if(qq==x):
            flag=1
        if((x-qq)%((2**k)-(2**(k-1)))==0):
            flag=1
        if(flag==1):
            print(1)
        else:
            print(0)