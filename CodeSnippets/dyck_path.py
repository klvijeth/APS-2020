import math
from itertools import permutations
def isdyck(x):
	l=[]
	for i in x:
		if(i=="x"):
			l.append(x)
		else:
			if(len(l)==0):
				return False
			l.pop()
	return True
n=int(input())
s=""
for i in range(n):
	s+='xy'
l=permutations(s)
l=set(l)
for i in l:
	if(isdyck(i)):
		print(i)
