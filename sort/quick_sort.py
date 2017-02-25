a=[9,1,2,6,5,123,123,45,2,13,567,213,1,223,2,-12,1222,34,11];
#a[30]={2,1};
def quick_sort(l,r):
    if l>=r:return
    key_value = a[l]
    left,right=l,r
    while left<right:
        while left<right and a[right]>=key_value:
            right-=1
        a[left]=a[right]
        while left<right and a[left]<=key_value:
            left+=1
        a[right]=a[left]
    a[left]=key_value
    quick_sort(l,left-1)
    quick_sort(left+1,r)
quick_sort(0,len(a)-1)
print(a)
