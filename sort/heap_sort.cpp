#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
void adjust_heap(int *a,int i,int len)
{
	int lson = i*2;
	int rson = i*2+1;
	int tmp = i;
	if(lson<=len&&a[tmp]<a[lson])
		tmp = lson;
	if(rson<=len&&a[tmp]<a[rson])
		tmp = rson;
	if(tmp != i)
	{
		swap(a[i],a[tmp]);
		adjust_heap(a,tmp,len);
	}
}
void make_heap(int *a,int len)
{
	for(int i=len/2;i>=1;i--)
		adjust_heap(a,i,len);
}
void heap_sort(int *a,int len)
{
	make_heap(a,len);
	for(int i=len;i>=1;i--)
	{
		swap(a[1],a[i]);
		adjust_heap(a,1,i-1);
	}	
}
int main()
{
	//下标从1开始排序
	int a[30]={0,9,1,2,6,5,123,123,45,2,13,567,213,1,223,2,-12,1222,34,11};
	int len=19;
	heap_sort(a,len);
	for(int i=1;i<=len;i++)
		printf("%d ",a[i]);
	printf("\n");
}
