// 给你一个长度为 n 下标从 0 开始的整数数组 maxHeights 。
// 你的任务是在坐标轴上建 n 座塔。第 i 座塔的下标为 i ，高度为 heights[i] 。
// 如果以下条件满足，我们称这些塔是 美丽 的：
// 1 <= heights[i] <= maxHeights[i]
// heights 是一个 山状 数组。
// 如果存在下标 i 满足以下条件，那么我们称数组 heights 是一个 山状 数组：
// 对于所有 0 < j <= i ，都有 heights[j - 1] <= heights[j]
// 对于所有 i <= k < n - 1 ，都有 heights[k + 1] <= heights[k]
// 请你返回满足 美丽塔 要求的方案中，高度和的最大值 。

#include <iostream>
using namespace std;
#include <vector>
#include <stack>


//学习单调栈求和的思路
class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        //我的题解
        //找山峰位置
        //优化，找波峰
        // int j=0;
        // while(j<n-1){
        //     while(j<n-1 && maxHeights[j]<=maxHeights[j+1]){
        //         j++;
        //     }
        //     index.push_back(j);
        //     while(j<n-1 && maxHeights[j]>=maxHeights[j+1]){
        //         j++;
        //     }
        // }
        // index.push_back(j);
        // for(int i=0; i<index.size(); i++){
        //     int pos=index[i];
        //     if((long long)maxHeights[pos]*n<ans){
        //         break;
        //     }
        //     long long ans_possible=maxHeights[pos];
        //     int a=pos-1;
        //     int last=maxHeights[pos];
        //     while(a>=0){
        //         if(maxHeights[a]>=last){
        //             ans_possible+=last;
        //         }
        //         else{
        //             ans_possible+=maxHeights[a];
        //             last=maxHeights[a];
        //         }
        //         a--;
        //     }
        //     int b=pos+1;
        //     int prev=maxHeights[pos];
        //     while(b<n){
        //         if(maxHeights[b]>=prev){
        //             ans_possible+=prev;
        //         }
        //         else{
        //             ans_possible+=maxHeights[b];
        //             prev=maxHeights[b];
        //         }
        //         b++;
        //     }
        //     ans=max(ans,ans_possible);
        // }
        // return ans;

        // 答案：单调栈，求左右两边递增的序列和
        int n=maxHeights.size();
        // 右起递增
        vector<long long> suf_sum(n+1,0);
        stack<int> stk;
        stk.push(n); //保留递增元素的起始下标
        long long sum=0;
        for(int i=n-1; i>=0; i--){
            int x=maxHeights[i];
            //弹出栈中大于当前值的元素
            while(stk.size()>1 && x<=maxHeights[stk.top()]){
                int j=stk.top();
                stk.pop();
                sum-=(long long) maxHeights[j]*(stk.top()-j); //撤销之前加入的元素和
            }
            sum+=(long long) x*(stk.top()-i);
            suf_sum[i]=sum;
            stk.push(i);
        }
        // 左起递增
        long long ans=sum;
        stk=stack<int>();
        stk.push(-1);
        long long pre_sum=0;
        for(int i=0; i<n; i++){
            int x=maxHeights[i];
            while(stk.size()>1 && x<=maxHeights[stk.top()]){
                int j=stk.top();
                stk.pop();
                pre_sum-=(long long) maxHeights[j]*(j-stk.top()); 
            }
            pre_sum+=(long long) x*(i-stk.top());
            ans=max(ans,pre_sum+suf_sum[i+1]);
            stk.push(i);
        }
        return ans;
    }
};