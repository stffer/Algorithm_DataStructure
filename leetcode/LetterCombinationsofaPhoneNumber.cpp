#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> ans;
    int len;
    string a[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void dfs(int pos,string tmp,string& digits){
        if(pos == len){
            ans.push_back(tmp);
            return;
        }
        int xy=digits[pos]-'0',alen=a[xy].size();
        for(int j=0;j<alen;++j){
            dfs(pos+1,tmp+a[xy][j],digits);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits=="")
            return ans;
        len=digits.size();
        dfs(0,"",digits);
        return ans;
    }
};
