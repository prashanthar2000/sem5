#n=int(input())
n = 4
#arr=[int(i) for i in input().split()]
arr = [1, 767, 565, 6 ]
def merge_halve(arr,temp,leftStart,rightEnd):
    leftEnd=(leftStart+rightEnd)//2
    rightStart=leftEnd+1
    left=leftStart
    right=rightStart
    index=left
    while(left<=leftEnd and right<=rightEnd):
        if(arr[left]<=arr[right]):
            temp[index]=arr[left]
            left+=1
        else:
            temp[index]=arr[right]
            right+=1
        index+=1
    while(left<=leftEnd):
        temp[index]=arr[left]
        index+=1
        left+=1
    while(right<=rightEnd):
        temp[index]=arr[right]
        right+=1
        index+=1
    for i in range(leftStart,rightEnd-leftStart+1):
        arr[i]=temp[i]
def merge(arr,temp,left,right):
    if(left<right):
        mid=(left+right)//2
        merge(arr,temp,left,mid)
        merge(arr,temp,mid+1,right)
        merge_halve(arr,temp,left,right)
def sort(arr,n):
    temp=[0 for i in range(n)]
    merge(arr,temp,0,n-1)
sort(arr,n)
print(arr)
