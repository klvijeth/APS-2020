bit=[0 for i in range(1001)]
def update(n,i,val):
    global bit
    while i <=n:
        bit[i]+=val
        i+=(i&-i)
        print(i&-i)
def query(n,i):
    s=0
    global bit
    while i>0:
        s+=bit[i]
        i+=(i&-i)
    return sum

n=int(input())
a=list(map(int,input().split()))
for i in range(len(a)):
    update(n,i+1,a[i])
print(bit[1:n+1])
