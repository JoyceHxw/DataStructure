#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // 回溯/dfs
        vector<vector<int>> ans;
        vector<int> array;
        vector<bool> used(nums.size(),false);
        dfs(ans,array,used,nums);
        return ans;
    }
    // void dfs(vector<vector<int>>& ans, vector<int>& array, int i, vector<int>& nums){
    //     if(array.size()==nums.size()){
    //         ans.push_back(array);
    //         return;
    //     }
    //     for(int j=0; j<nums.size(); j++){ //存在元素和数组的重复
    //         array.push_back(nums[i]);
    //         dfs(ans,array,j,nums);
    //         array.pop_back();
    //     }
    // }
    void dfs(vector<vector<int>>& ans, vector<int>& array, vector<bool>used, vector<int>& nums){
        if(array.size()==nums.size()){
            ans.push_back(array);
            return;
        }
        for(int j=0; j<nums.size(); j++){ //存在元素和数组的重复
            if(used[j]==true){
                continue;
            }
            array.push_back(nums[j]);
            used[j]=true;
            dfs(ans,array,used, nums);
            array.pop_back();
            used[j]=false;
        }
    }
};