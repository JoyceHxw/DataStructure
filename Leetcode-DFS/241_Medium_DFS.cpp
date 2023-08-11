#include <iostream>
using namespace std;
#include <vector>

// 这道题dfs有点绕，不要要遍历每个符号，还要组合符号左右所有的可能
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        // 先处理表达式
        vector<int> array;
        int num=0;
        int i=0;
        while(i<expression.length()){
            if(expression[i]>='0' && expression[i]<='9'){
                num=num*10+expression[i]-'0';
            }
            else{
                array.push_back(num);
                num=0;
                if(expression[i]=='+'){
                    array.push_back(-1);
                }
                else if(expression[i]=='-'){
                    array.push_back(-2);
                }
                else{
                    array.push_back(-3);
                }
            }
            i++;
        }
        array.push_back(num);

        // dp[l][r]表示数组从l到r的所有可能计算结果
        vector<vector<vector<int>>> dp(array.size(),vector<vector<int>>(array.size()));
        return dfs(dp,0,array.size()-1, array);
    }
    // 将运算表达式看作树状图，遍历以不同符号为根节点的树的答案
    // dfs递归，返回从l到r的子数组的所有可能计算结果
    vector<int> dfs(vector<vector<vector<int>>>& dp, int l, int r, const vector<int>& array){
        if(dp[l][r].empty()){
            // 单个数
            if(l==r){
                dp[l][r].push_back(array[l]);
            }
            else{
                // +2跳过运算符
                // 一个数字一个符号交替
                for(int i=l; i<r; i+=2){
                    // 以arrar[i+1]符号为根节点
                    // 左边结果
                    auto left=dfs(dp,l,i,array);
                    // 右边结果
                    auto right=dfs(dp,i+2,r,array);
                    // 组合
                    for(auto& lv: left){
                        for(auto& rv: right){
                            if(array[i+1]==-1){
                                dp[l][r].push_back(lv+rv);
                            }
                            else if(array[i+1]==-2){
                                dp[l][r].push_back(lv-rv);
                            }
                            else{
                                dp[l][r].push_back(lv*rv);
                            }
                        }
                    }
                }
            }
        }
        return dp[l][r];
    }
    
    
};