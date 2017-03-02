#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
//辅助空间
int b[10000];
void merge(int *a,int l,int mid,int r)
{
	int left = l,right = r;
	int rl = mid+1; //右边第一个
	int len = 0;
	while(left<=mid && rl<=right)
	{
		while(left<=mid && a[left]<=a[rl])
			b[len++] = a[left++];
		while(rl<=right && a[rl]<=a[left])
			b[len++] = a[rl++];
	}
	while(left<=mid)
		b[len++] = a[left++];
	while(rl<=right)
		b[len++] = a[rl++];
	for(int i=l;i<=r;i++)
		a[i]=b[i-l];
}
void merge_sort(int *a,int l,int r)
{
	if(l<r)
	{
		int mid = (l+r)/2;
		merge_sort(a,l,mid);
		merge_sort(a,mid+1,r);
		merge(a,l,mid,r);
	}
}
int main()
{
	int a[30]={0,9,1,2,6,5,123,123,45,2,13,567,213,1,223,2,-12,1222,34,11};
	int len=19;
	merge_sort(a,1,len);
	for(int i=1;i<=len;i++)
		printf("%d ",a[i]);
	printf("\n");
}
