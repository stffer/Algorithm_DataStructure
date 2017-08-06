/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
Note: The solution set must not contain duplicate triplets.
For example, given array S = [-1, 0, 1, 2, -1, -4],
A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> re;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); ++i){
            if(i&&nums[i]==nums[i-1]) continue;
            int l=i+1,r=nums.size()-1;
            while(l<r){
                int ans = nums[i]+nums[l]+nums[r];
                if(ans > 0){
                    r--;
                }
                else if(ans < 0){
                    l++;
                }
                else{
                    re.push_back(vector<int>{nums[i],nums[l],nums[r]});
                    while(l+1<r&&nums[l+1]==nums[l]) l++;
                    while(l<=r-1&&nums[r-1]==nums[r]) r--;
                    l++,r--;
                }
            }
        }
        return re;
    }
};
