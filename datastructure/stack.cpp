#include <queue>
#include <vector>
#include <iostream>
template<typename T> 
class stack{
public:
    int size(){
        return _vector.size();
    }
    T top(){
        return _vector.back();
    }
    void pop(){
        _vector.pop_back();
    }
    void push(T&& tmp){
        _vector.push_back(tmp);
    }
    void push(T& tmp){
        _vector.push_back(tmp);
    }
    bool empty() const{
        return _vector.begin() == _vector.end();
    }
private:
    std::vector<T> _vector;    
};
int main(void)
{
    stack<int> s;
    for(int i=0;i<100;i++){
        int x=i;
        s.push(x);
    }
    for(int i=0;i<200;i++){
        if(!s.empty()){
            std::cout<<s.top()<<std::endl;
            s.pop();
        }
    }
    return 0;
}
