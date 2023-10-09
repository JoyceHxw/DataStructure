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

    //交换的方式，节省空间
    // void backtrack(vector<vector<int>>& res, vector<int>& output, int first, int len){
    //     // 所有数都填完了
    //     if (first == len) {
    //         res.emplace_back(output);
    //         return;
    //     }
    //     for (int i = first; i < len; ++i) {
    //         // 动态维护数组
    //         swap(output[i], output[first]);
    //         // 继续递归填下一个数
    //         backtrack(res, output, first + 1, len);
    //         // 撤销操作
    //         swap(output[i], output[first]);
    //     }
    // }


};
