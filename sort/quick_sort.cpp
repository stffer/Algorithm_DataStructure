#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
void quick_sort(int *b,int l,int r)
{
    if(l>=r)
        return;
    int key_value=b[l];
    int left = l,right = r;
    while(left<right)
    {
        while(b[right]>=key_value&&left<right)
            --right;
        b[left]=b[right];
        while(b[left]<=key_value&&left<right)
            ++left;
        b[right]=b[left];
    }
    b[left]=key_value;
    quick_sort(b,l,right-1);
    quick_sort(b,right+1,r);
}
int main()
{
    int a[30]={9,1,2,6,5,123,123,45,2,13,567,213,1,223,2,-12,1222,34,11};
    int len=19;
    quick_sort(a,0,18);
    for(int i=0;i<len;i++)
        printf("%d ",a[i]);
    printf("\n");
}
