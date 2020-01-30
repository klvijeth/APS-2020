s1=input()
s2=input()
r=[[0 for i in range(len(s2)+1)] for j in range(len(s1)+1)]
for i in range(1,len(s1)+1):
	for j in range(1,len(s2)+1):
		if(s1[i-1]==s2[j-1]):
			r[i][j]=(r[i-1][j-1]+1)
		else:
			r[i][j]=max(r[i-1][j],r[i][j-1])
print(r[len(s1)][len(s2)])
