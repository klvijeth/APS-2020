n=int(input())
coins=list(map(int,input().split()))
coins=sorted(coins)
seq=[]
for i in range(n+1):
	seq.append([])
l=[0 for i in range(n+1)]
l[0]=1
for i in coins:
	for j in range(i,n+1):
		l[j]+=l[j-i]
for i in coins:
	for j in range(i,n+1):
		if(l[j-i]!=0):
			if((j-i)==0):
				seq[j].append([i])
			else:
				for h in seq[j-i]:
					x=[]
					for qq in h:
						x.append(qq)
					x.append(i)
					seq[j].append(x)
print(seq[n])
for i in seq:
	print(i)
