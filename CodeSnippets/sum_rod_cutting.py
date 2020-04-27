n=int(input())
pr=list(map(int,input().split()))
l=[0]*(n+1)
for i in range(2,n+1):
	for j in range(1,(i//2)+1):
		l[i]=max(l[i],pr[j-1]+pr[i-j-1],pr[j-1]+l[i-j],pr[i-1])
if(n==1):
	print(pr[0])
else:
	print(l[n])
