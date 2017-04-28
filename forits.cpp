#include <cstring>
#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <bitset>
#include <queue>
#include <map>
#include <time.h>
using namespace std;
void cmp(pair<int,int> x){
    cout<<x.first<<" "<<x.second<<endl;
}
int main(void)
{
    srand(time(NULL));
    vector<pair<int,int> > aa;
    for(int i=0;i<10;i++)
        aa.push_back(make_pair(rand(),rand()));
    sort(aa.begin(),aa.end(),[](pair<int,int>tmp1,pair<int,int>tmp2){return tmp1.first<tmp2.first;});
    for(int i=0;i<10;i++)
        cmp(aa[i]);
    for (auto i : aa) {
        cmp(i);
    }
    for_each(aa.begin(),aa.end(),cmp);
    return 0;
}
