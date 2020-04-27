t=int(input())
for q in range(t):
    vv=list(map(int,input().split()))
    col=vv[1]
    row=vv[0]
    if(row==1 and col==1):
        print(1)
        print("1")
    elif(row==1 and col==2):
        print(1)
        print("1 1")
    elif(col==1 and row==2):
        print(1)
        print("1")
        print("1")
    else:
        mm=[[0 for oo in range(col)] for qq in range(row)]
        if(row==1):
            ee=0
            print(2)
            for qq in range(col):
               if((qq+1)%2==0):
                   ee+=1
               if(qq%2==0):
                   if(ee%2==0):
                       mm[0][qq]=1
                       if((qq+1)<col):
                           mm[0][qq+1]=2
                   else:
                       mm[0][qq]=2
                       if((qq+1)<col):
                           mm[0][qq+1]=1
        elif(col==1):
            ee=0
            print(2)
            for qq in range(row):
               if((qq+1)%2==0):
                   ee+=1
               if(qq%2==0):
                   if(ee%2==0):
                       mm[qq][0]=1
                       if((qq+1)<row):
                           mm[qq+1][0]=2
                   else:
                       mm[qq][0]=2
                       if((qq+1)<row):
                           mm[qq+1][0]=1
        elif(col==2):
            ee=0
            if(row!=2):
                print(3)
            else:
                print(2)
            for qq in range(row):
                if((qq+1)%3==0):
                    ee+=1  
                if(qq%3==0):
                   if(ee%2==0):
                       mm[qq][0]=1
                       mm[qq][1]=2
                       if((qq+1)<row):
                           mm[qq+1][0]=1
                           mm[qq+1][1]=2
                       if((qq+2)<row):
                           mm[qq+2][0]=3
                           mm[qq+2][1]=3    
                   else:
                       mm[qq][0]=2
                       mm[qq][1]=1
                       if((qq+1)<row):
                           mm[qq+1][0]=2
                           mm[qq+1][1]=1
                       if((qq+2)<row):
                           mm[qq+2][0]=3
                           mm[qq+2][1]=3
        elif(row==2):
            ee=0
            if(col!=2):
                print(3)
            else:
                print(2)
            for qq in range(col):
                if((qq+1)%3==0):
                    ee+=1  
                if(qq%3==0):
                   if(ee%2==0):
                       mm[0][qq]=1
                       mm[1][qq]=2
                       if((qq+1)<col):
                           mm[0][qq+1]=1
                           mm[1][qq+1]=2
                       if((qq+2)<col):
                           mm[0][qq+2]=3
                           mm[1][qq+2]=3    
                   else:
                       mm[0][qq]=2
                       mm[1][qq]=1
                       if((qq+1)<col):
                           mm[0][qq+1]=2
                           mm[1][qq+1]=1
                       if((qq+2)<col):
                           mm[0][qq+2]=3
                           mm[1][qq+2]=3
        else:
            print(4)
            ee=0
            for qq in range(col):
                    w=1
                    for pu in range(row):
                        if((ee%2)==0):
                            if(pu%4==0):
                                if(pu<row):
                                    mm[pu][qq]=1
                                if((pu+1)<row):
                                    mm[pu+1][qq]=2
                                if((pu+2)<row):
                                    mm[pu+2][qq]=3
                                if((pu+3)<row):
                                    mm[pu+3][qq]=4
                        else:
                            if(pu<=1):
                                mm[0][qq]=3
                                mm[1][qq]=4
                            else:
                                if((pu-2)%4==0):
                                    if(pu<row):
                                        mm[pu][qq]=1
                                    if((pu+1)<row):
                                        mm[pu+1][qq]=2
                                    if((pu+2)<row):
                                        mm[pu+2][qq]=3
                                    if((pu+3)<row):
                                        mm[pu+3][qq]=4
                    if(((qq+1)%2)==0):
                        ee+=1
        for v in range(row):
            temp=' '.join(str(oo) for oo in mm[v])
            print(temp)