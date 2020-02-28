n=int(input())
k=int(input())
coef=[[0 for i in range(k+1)] for j in range(n+1)]
for i in range(0,n+1):
    for j in range(min(i,k)+1):
        if(j==0 or i==j):
            coef[i][j]=1
        else:
            coef[i][j]=coef[i-1][j-1]+coef[i-1][j]
print(coef[n][k])