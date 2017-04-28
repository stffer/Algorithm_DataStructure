#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int a[13]={1,2,3,4,5,6,7,8,9,10,11,12};
int n;
int len_sum=12;
int b[13];
bool vis[13];
void dfs(int pos,int len)
{
	if(len == n)
	{
		for(int i=0;i<len;i++){
			printf("%d ",b[i]);
		}
		printf("\n");
		return;
	}
	for(int i=0;i<len_sum;i++)
	{
		if(!vis[i]){
			vis[i]=1;
			b[++pos] = a[i];
			dfs(pos,len+1);
			--pos;
			vis[i]=0;
		}
	}
	return;
}
int main()
{
	//输入对数列中多少数进行组合
	std::cin>>n;
	dfs(-1,0);
}
