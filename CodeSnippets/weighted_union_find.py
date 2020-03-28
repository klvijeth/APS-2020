def root(arr,u):
    while(arr[u]!=u):
        u=arr[u]
    return u
def weighted_union(arr,size,u,v):
    rootu=root(arr,u)
    rootv=root(arr,v)
    if(size[rootu]<size[rootv]):
        arr[rootu]=arr[rootv]
        size[rootv]+=1
    else:
        arr[rootv]=arr[rootu]
        size[rootu]+=1
    return arr,size
def find(arr,u,v):
    if(root(u)==root(v)):
        return True
    return False
n=int(input())
arr=[i for i in range(n)]
size=[1 for i in range(n)]
arr,size=weighted_union(arr,size,0,1)
arr,size=weighted_union(arr,size,1,2)
arr,size=weighted_union(arr,size,2,3)
print(arr)