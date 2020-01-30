arr=[[0 for i in range(6)] for j in range(6)]
v=[1,3,5,8,9]
w=[1,2,3,4,5]
for i in range(6):
	for j in range(1,6):
		if(i==0):
			arr[i][j]=0
		elif(w[i-1]<=j and j!=0):
			#print(v[i-1],w[i-1])
			arr[i][j]=max(arr[i-1][j],v[i-1]+arr[i-1][j-w[i-1]])
		else:
			arr[i][j]=arr[i-1][j]
print(w)
print(v)
print(arr)	
