// 给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，其中 answer[i] 是指对于第 i 天，下一个更高温度出现在几天后。如果气温在这之后都不会升高，请在该位置用 0 来代替。

#include <iostream>
using namespace std;
#include <vector>
#include <stack>

//想到遍历保存最大值，找波峰波谷，但是都不对
//熟悉单调栈这类题型
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // int n=temperatures.size();
        // vector<int> ans(n);
        // for(int i=0; i<n; i++){
        //     int k=0;
        //     while(i+k<n && temperatures[i+k]<=temperatures[i]){
        //         k++;
        //     }
        //     if(i+k>=n){
        //         k=0;
        //     }
        //     ans[i]=k;
        // }
        // return ans;

        //单调栈
        int n=temperatures.size();
        vector<int> ans(n);
        stack<int> stk;
        for(int i=0; i<n; i++){
            while(!stk.empty() && temperatures[stk.top()]<temperatures[i]){
                ans[stk.top()]=i-stk.top();
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }
};