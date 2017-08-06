#include <bits/stdc++.h>
using namespace std;
int nth(int *a,int l,int r,int val){
    int l1=l,r1=r,key=a[l];
    while(l1<r1){
        while(l1<r1&&a[r1]>=key){
            r1--;
        }
        a[l1]=a[r1];
        while(l1<r1&&a[l1]<=key){
            l1++;
        }
        a[r1]=a[l1];
    }
    a[l1]=key; 
    if(l1==val){
        return key;
    }
    else if(l1<val){
        return nth(a,l1+1,r,val);
    }
    else{
        return nth(a,l,l1-1,val);
    }
}
int main(void)
{
    int a[12]={7,6,5,7,4,5,32,2,4,7,99,88};
    for(int i=0;i<12;++i){
        int ans=nth(a,0,11,i);
        cout<<ans<<" ";
    }
    cout<<endl;
    sort(a,a+12);
    for(int i=0;i<12;++i){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
