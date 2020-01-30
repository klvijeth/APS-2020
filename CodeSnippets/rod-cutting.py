n=int(input())
l=[0]*(n+1)
for i in range(2,n+1):
	for j in range(1,(i//2)+1):
		l[i]=max(l[i],j*(i-j),j*l[i-j])
print(l[n])
