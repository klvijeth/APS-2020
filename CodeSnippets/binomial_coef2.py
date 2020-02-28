def bin_coef(n,k):
    if(k==0 or n==k):
        return 1
    return bin_coef(n-1,k-1)+bin_coef(n-1,k)
n=int(input())
k=int(input())
print(bin_coef(n,k))
