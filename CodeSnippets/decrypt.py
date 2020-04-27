t = list(map(int,input().split(' ')))
u = len(t)
v = []
for i in range(u):
    count = 0
    s = 0
    while t[i] !=0:
        k = (t[i]%10)(7*count)
        count+=1
        s = s+k
        t[i] = t[i]//10
    v.append(chr(s))

k = "".join(v)
print(k)
