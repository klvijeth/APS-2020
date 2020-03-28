def heapify(arr):
    n=len(arr)
    for i in range(n//2,1,-1):
        k=i
        v=arr[k]
        heap=False
        while not heap:
            j=2*k
            if(j<n):
                if(arr[j]>arr[j+1]):
                    j+=1
            if(v<=arr[j]):
                heap=True
            else:
                arr[k]=arr[j]
                k=j
        arr[k]=v


