def count_no_bits(n):
	count=0
	while(n!=0):
		n=n&(n-1)
		count+=1
	return count
tasks=int(input())
cost=[]
for i in range(tasks):
	l=list(map(int,input().split()))
	cost.append(l)
dp=[float('inf') for i in range(2**tasks)]
dp[0]=0
for mask in range(2**tasks):
	x=count_no_bits(mask)
	for j in range(tasks):
		if((mask&(1<<j))==0):
			dp[mask|(1<<j)]=min(dp[mask|(1<<j)],(dp[mask]+cost[x][j]))
print(dp[(2**tasks)-1])