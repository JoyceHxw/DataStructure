#include <iostream>
using namespace std;
#include <vector>


// 不适合把所有组合都列出再删除，因为最大元素个数是不同的
// 回溯模板
// def backward():
//     if (回朔点）：# 这条路走到底的条件。也是递归出口
//         保存该结果
//         return   
//     else:
//         for route in all_route_set :  逐步选择当前节点下的所有可能route
//             if 剪枝条件：
//                 剪枝前的操作
//                 return   #不继续往下走了，退回上层，换个路再走
//             else：#当前路径可能是条可行路径
//                 保存当前数据  #向下走之前要记住已经走过这个节点了。例如push当前节点
//                 self.backward() #递归发生，继续向下走一步了。
//                 回朔清理     # 该节点下的所有路径都走完了，清理堆栈，准备下一个递归。例如弹出当前节点

class Solution {
public:
    void dfs(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& combine, int idx) {
        if (idx == candidates.size()) {
            return;
        }
        if (target == 0) {
            ans.emplace_back(combine);
            return;
        }
        // 直接跳过
        dfs(candidates, target, ans, combine, idx + 1); //防止重复组合，只能找后面的元素
        // 选择当前数
        if (target - candidates[idx] >= 0) {
            combine.emplace_back(candidates[idx]);
            dfs(candidates, target - candidates[idx], ans, combine, idx);  //允许重复元素
            combine.pop_back();  //清空combine
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combine;
        dfs(candidates, target, ans, combine, 0);
        return ans;
    }
};

int main(){
    Solution s;
    vector<int>candidates={2,3,6,7};
    s.combinationSum(candidates,7);
}