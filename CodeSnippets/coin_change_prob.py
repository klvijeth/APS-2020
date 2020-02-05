n=int(input())
coins=list(map(int,input().split()))
l=[0 for i in range(n+1)]
l[0]=1
for i in coins:
	for j in range(i,n+1):
		l[j]+=l[j-i]
print(l[n]) 
