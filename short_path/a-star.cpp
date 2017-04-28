#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<string.h>
#include<string>
#include<ctime>
#include<queue>
#include<list>
#include<map>
#include<set>
#define INF 999999999
#define MAXN 10000000
using namespace std;

/*
 * 由0-8的某种排列转换为下图，
 * 1 2 3
 * 4 5 6
 * 7 8 0
 * 最少几步?
*/
int dirc[10][20]= {{1,3,-1},{0,2,4,-1},{1,5,-1},{0,4,6,-1},
                    {1,3,5,7,-1},{2,4,8,-1},{3,7,-1},{4,6,8,-1},{5,7,-1}};
string uuu,res = "123456780";
map<string,int> mp;
struct node
{
    int step,pos,value;
    string x;
    node(int _s,int _pos,int value,string _x):step(_s),pos(_pos),value(value),x(_x){}
    friend bool operator< (const node &tmp1,const node &tmp2){
        if(tmp2.value == tmp1.value)
            return tmp1.step > tmp2.step;
        return tmp1.value > tmp2.value;
    }
};
int H(string uuu){
    int ans=0;
    int cnt=0;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            if(uuu[cnt]!='0'){
                int tmp = uuu[cnt]-'0';
                int x = (tmp-1)/3+1;
                int y = (tmp-1)%3+1;
                ans+=abs(x-i)+abs(y-j);
            }
            cnt++;    
        }
    }
    return ans;
}
int bfs(int pos,string x)
{
    if(mp[x])
        return 0;
    priority_queue<node> Q;
    Q.push(node(0,pos,0+H(x),x));
    while(!Q.empty())
    {
        node tmp=Q.top();
        Q.pop();
        for(int i=0; dirc[tmp.pos][i]!=-1; i++)
        {
            uuu=tmp.x;
            swap(uuu[tmp.pos],uuu[dirc[tmp.pos][i]]);
            if(!mp[uuu])
            {
                mp[uuu]=1;
                if(uuu==res)
                    return tmp.step+1;
                Q.push(node(tmp.step+1,dirc[tmp.pos][i],tmp.step+1+H(uuu),uuu));
            }
        }
    }
    return -1;
}
int main()
{

    int t,pos;
    cin>>t;
    while(t--)
    {
        mp.clear();
        string str;
        int chu[10];
        for(int i=0; i<9; i++)
        {
            scanf("%d",&chu[i]);
            str+=chu[i]+'0';
            if(chu[i]==0)
                pos=i;
        }
        mp[str] = 1;        
        int ans=bfs(pos,str);
        if(ans==-1)
        {
            printf("No Solution!\n");
        }
        else
            printf("%d\n",ans);
    }
}
