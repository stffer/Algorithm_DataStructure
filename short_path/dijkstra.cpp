#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int MAXEDGE = 100000;
const int MAXPOINT = 10000;
/* 静态邻接表 */
struct Edge
{
	int next;
	int to;
	int value;
}edge[MAXEDGE];
int head[MAXPOINT],cnt;

void init()
{
	cnt=0;
	memset(head,-1,sizeof(head));
}
void add_edge(int x,int y,int v)
{
	edge[cnt].to = y;
	edge[cnt].value = v;
	edge[cnt].next = head[x];
	head[x] = cnt++;
}

int pre[MAXPOINT];
int short_path[MAXPOINT];
bool vis[MAXPOINT];
struct Mine
{
	int p,value;
	Mine(int p,int value)
	{
		this->p=p;
		this->value=value;
	}
	bool operator < (const Mine &a) const{
		return this->value > a.value;
	}

};
int display(int x)
{
	if(pre[x] == -1)
		return x;
	cout<<display(pre[x])<<"*";
	return x;
}
void dijkstra(int s)
{
	memset(short_path,0x3f,sizeof(short_path));
	memset(vis,0,sizeof(vis));
	memset(pre,-1,sizeof(pre));
	priority_queue<Mine> que;
	que.push(Mine(s,0));
	short_path[s] = 0;
	while(!que.empty())
	{
		int old = que.top().p;
		que.pop();
		if(vis[old]) 
			continue;
		vis[old] =1;
		for(int i=head[old];~i;i=edge[i].next)
		{
			Edge next_to = edge[i];
			if(!vis[next_to.to]&&short_path[next_to.to] >
									short_path[old]+next_to.value)
			{
				short_path[next_to.to] = short_path[old]+next_to.value;
				pre[next_to.to] = old;
				que.push(Mine(next_to.to,short_path[next_to.to]));
			}
		}
	}	
}

int main()
{
	int n,m;
	while(cin>>n>>m)
	{//n个点m条有向边
		if(n==0&&m==0)
			break;
		int f,t,w;
		init();
		for(int i=0;i<m;i++)
		{
			cin>>f>>t>>w;
			add_edge(f,t,w);
		}
		dijkstra(1);
		cout<<short_path[n]<<endl;	
		int end = display(n);
		cout<<end<<endl;
	}
}
