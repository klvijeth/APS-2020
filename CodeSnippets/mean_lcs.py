s1=input()
s2=input()
r=[[0 for i in range(len(s2)+1)] for j in range(len(s1)+1)]
max1=0
sc=""
strng=""
for k in range(len(s1)):
    max1=k
    sc=""
    for i in range(k,len(s1)):
        for j in range(max1+1,len(s2)):
            if(s1[i]==s2[j]):
                max1=j
                sc+=s1[i]
                break
    if(len(strng)<len(sc)):
        strng=sc
    print(sc)
print(strng)
