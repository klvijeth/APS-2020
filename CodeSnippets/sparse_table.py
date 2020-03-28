import math as m

lookup=[[0 for i in range(1000)] for j in range(1000)]
def build_tree(arr):
    n=len(arr)
    global lookup
    j=1
    while(2**j<n):
        i=0
        while i < (2**j)-1:
            if(arr[lookup[i][j-1]]<arr[lookup[i+(2**j)-1][j-1]]):
                lookup[i][j]=lookup[i+(2**j)-1][j-1]
            else:
                lookup[i][j]=lookup[i][j-1]
            i+=1
        j+=1
def query(arr,L,R):
    j=m.log((R-L+1),2)
    if(arr[lookup[L][j]<arr[lookup[R-(2**j)-1][j]]):
        return arr[lookup[R-(2**j)-1][j]]
    else:
        return arr[lookup[L][j]]
n=int(input())
arr=list(map(int,input().split()))
for i in range(n):
    lookup[i][0]=i
build_tree(arr)
