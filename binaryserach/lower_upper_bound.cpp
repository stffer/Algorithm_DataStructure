#include <bits/stdc++.h>
using namespace std;
int serachlower(int *a,int l,int r,int value){
    while(l<r){
        int mid=(l+r)/2;
        if(a[mid]>=value){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    return r;
}
int serachupper(int *a,int l,int r,int value){
    while(l<r){
        int mid=(l+r)/2;
        if(a[mid]>value){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    return r;
}
int main(void)
{
    int a[10001];

    srand(time(NULL));
    for(int i=0;i<1000;i++){
        a[i]=random()%100000;
    }
    sort(a,a+1000);
    int flog=0;
    for(int i=0;i<1000;i++){
        int tmp=random()%1000000;
        int tmp1=serachlower(a,0,1000,tmp);
        int tmp2=lower_bound(a,a+1000,tmp)-a;
        int tmp3=serachupper(a,0,1000,tmp);
        int tmp4=upper_bound(a,a+1000,tmp)-a;
        if(tmp1!=tmp2||tmp3!=tmp4){
            flog=1;
            break;
        }
    }
    if(flog){
        printf("false\n");
    }
    else
        printf("true\n");
    return 0;
}
