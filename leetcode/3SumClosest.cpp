/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
    For example, given array S = {-1 2 1 -4}, and target = 1.
    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans=nums[0]+nums[1]+nums[2];
        for(int i=0;i<nums.size();++i){
            int l=i+1,r=nums.size()-1;
            while(l<r){
                int tmp=nums[i]+nums[l]+nums[r];
                if(tmp<target){
                    ++l;
                }
                else if(tmp>target){
                    --r;
                }
                else{
                    return tmp;
                }
                if(abs(ans-target)>abs(tmp-target)){
                    ans=tmp;
                }
            }
        }
        return ans;
    }
};
