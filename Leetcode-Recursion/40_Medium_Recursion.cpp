#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    void dfs(vector<vector<int>>& ans, vector<int>& candidates, vector<int>& combination, int target, int pos){
        if(target<0){
            return;
        }
        if(target==0){
            ans.push_back(combination);
            return;
        }
        for(int i=pos; i<candidates.size(); i++){
            // candidates数组中存在重复的元素，需要排除
            // 已经排序过了
            if (i > pos && candidates[i] == candidates[i - 1])
                continue;
            combination.push_back(candidates[i]);
            dfs(ans,candidates,combination,target-candidates[i],i+1);
            combination.pop_back(); 
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combination;
        sort(candidates.begin(),candidates.end());
        dfs(ans,candidates,combination,target,0);
        return ans;
    }
};