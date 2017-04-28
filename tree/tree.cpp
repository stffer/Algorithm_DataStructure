/*
 * 已知一颗二叉树的前序和中序遍历
 * 求层次遍历
 * stdin
 * 5
 * 1 2 4 5 3
 * 4 2 5 1 3
 * stdout
 * 1 2 3 4 5
 */
#include <cstdio>
#include <iostream>
#include <map>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
int a[10008];
int b[10008];
vector<int> Tree[10008];
int maxcen=-1;
int n;
int num;
void dfs(int l,int r,int cen)
{
    if(num>n)
        return;
    if(l==r){
        maxcen = max(maxcen,cen);
        Tree[cen].push_back(a[num]);
        num++;
        return;
    }
    for(int j=l;j<=r;j++)
    {
        if(a[num]==b[j])
        {
            Tree[cen].push_back(a[num]);
            num++;
            dfs(l,j-1,cen+1);
            dfs(j+1,r,cen+1);
        }

    }
}
int main()
{
    num=1;
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    dfs(1,n,1);
    for(int i=1;i<=maxcen;i++){
        int uuu = Tree[i].size();    
        //cout<<uuu<<endl;
        for(int j=0;j<uuu;j++)
        {
            printf("%d ",Tree[i][j]);
        }    
    }
}
