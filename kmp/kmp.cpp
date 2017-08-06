#include <cstdio>
#include <cstring>
#include <iostream>
int* kmp_pre(char* x,int len,int* next){
    int i,j;
    j=next[0]=-1;
    i=0;
    while(i<len){
       while(j!=-1&&x[i]!=x[j]) j=next[j]; 
       next[++i]=++j;
    } 
    return next;
}
int next[1000000];
int kmp_count(char* str1,int l1,char* str2,int l2){
    int i,j;
    int ans=0;
    kmp_pre(str2,l2,next);
    i=j=0;
    while(i<l1){
        while(j!=-1&&str1[i]!=str2[j])
            j=next[j];
        i++,j++;
        if(j>=l2){
            ans++;
            j=next[j];
        }
    }
    return ans;
}
int main(void)
{
    char a[]={'a','b','a','b','c','d','e','b','b','c','e','\0'}; 
    //char b[]={'a','b','c','a','b','b','\0'};
    char b[]={'a','a','a','a','a','b','\0'};
    kmp_pre(a,strlen(a),next);
    for(int i=0;i<strlen(a);++i){
        std::cout<<next[i]<<" ";
    }
    std::cout<<std::endl;
    return 0;
}
