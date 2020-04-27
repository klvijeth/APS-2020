n=int(input())
male=[]
female=[]
pro={}
mar={}
mar1={}
def func(qq):
	global male
	global female
	global pro
	global mar
	global mar1
	global n
	flag=0
	count=0
	while(flag==0):
		x=male[qq]
		m=min(x)
		ind=x.index(m)
		x[ind]=2*n
		male[qq][ind]=2*n
		if(ind not in mar):
			pro[ind]=1
			mar[ind]=female[ind][qq]
			mar1[ind]=qq
			flag1=1
			return
		else:
			pro[ind]+=1
			if(female[ind][count]<mar[ind]):
				mar[ind]=female[ind][count]
				xx=mar1[ind]
				mar1[ind]=qq
				func(xx)
				return
for i in range(n):
	l=list(map(int,input().split()))
	male.append(l)
for i in range(n):
	l=list(map(int,input().split()))
	female.append(l)
count=0
for i in male:
	flag=0
	while(flag==0):
		func(count)
	count+=1
q=int(input())
for i in range(q):
	x=int(input())-1
	if(x in pro):
		print(pro[x])
	else:
		print(0)
