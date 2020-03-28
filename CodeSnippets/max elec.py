import math
y=list(map(int,input().split(' ')))
n=y[0]
c=y[1]
flag=0
coin=1000
q=int(math.sqrt(n))
w=int(n/2)
flag2=0
print("1",w,flush=True)
x=int(input())
if(x==1):
    print("2",flush=True)
else:
    q=w+int(math.sqrt(n))
while(flag!=1 and q<=n):
    print("1",q,flush=True)
    x=int(input())
    if(x==1):
        flag=1
    else:
        q+=int(math.sqrt(n))
print("2",flush=True)
flag=0
y=q
q=q-int(math.sqrt(n))+1
flag1=0
while(flag!=1 and q<=n):
    print("1",q,flush=True)
    x=int(input())
    if(x==1):
        flag=1
    else:
        q+=1
    if(q==y):
        flag1=1
        break;
if(flag1==0):
    print("2",flush=True)
print("3",q,flush=True)
