#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> set;
        vector<bool> used(nums.size(),false);
        sort(nums.begin(), nums.end());
        recursion(nums,set,ans,0,used);
        return ans;
    }
    void recursion(vector<int>& nums, vector<int>& set, vector<vector<int>>& ans, int k, vector<bool>& used){
        // 复习回溯，结合78题
        // 如何去重，利用排序和used
        ans.push_back(set);
        for(int i=k; i<nums.size(); i++){
            if(i>0 && nums[i]==nums[i-1] && used[i-1]==false){
                continue;
            }
            set.push_back(nums[i]);
            used[i]=true;
            recursion(nums,set,ans,i+1,used);
            used[i]=false;
            set.pop_back();
        }
    }
};