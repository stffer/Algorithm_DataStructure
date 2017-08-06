#include <bits/stdc++.h>
using namespace std;
class int_128{
public:
    int_128(){
        base0=0;
        base1=0;
    }
    unsigned long long get0(){
        return base0;
    } 
    long long get1(){
        return base1;
    } 

    friend ostream& operator <<(ostream& output,int_128& tmp){
        unsigned long long tmp0=tmp.get0(); 
        long long tmp1=tmp.get1(); 
        if(tmp1==0)
            output<<tmp0;
        else
            output<<tmp1<<tmp0;
        return output;
    }
    friend istream& operator >>(istream& input,int_128& tmp){
        return input;  
    }
    int_128& operator+(int_128& tmp) const{
        return tmp;
    }
    int_128& operator-(int_128& tmp) const{
        return tmp;
    }
    int_128& operator*(int_128& tmp) const{
        return tmp;
    }
    int_128& operator/(int_128& tmp) const{
        return tmp;
    }
private:
    unsigned long long base0;
    long long base1;
};
int main(void)
{
    int_128 a,b;
    cout<<a+b<<endl;
    return 0;
}
