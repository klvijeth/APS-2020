n=int(input())
l=[]
married=[]
for i in range(n):
	x=list(map(int,input().split(" ")))
	l.append(x)
for i in l:
	for j in i:
		if j in married:
			continue
		else:
			if(j!=-1):
				married.append(j)
				break
flag=0
for i in range(1,n+1):
	if i not in married:
		print(i)
		flag=1
if(flag==0):
	print(-1)
