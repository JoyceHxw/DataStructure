#include <iostream>
using namespace std;
#include <vector>


// 已经可以较熟练地写出最基础的回溯（dfs）了！居然一遍过
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>combination;
        recursion(nums,combination,0);
        return ans;
    }
    void recursion(vector<int>& nums, vector<int>& combination, int i){
        if(combination.size()==nums.size()){
            ans.push_back(combination);
            return;
        }
        // 考虑什么情况下改变ans
        ans.push_back(combination);
        // 集合没有排序，所以可以j+1
        for(int j=i; j<nums.size(); j++){
            combination.push_back(nums[j]);
            recursion(nums,combination,j+1);
            combination.pop_back();
        }
        return;
    }
};