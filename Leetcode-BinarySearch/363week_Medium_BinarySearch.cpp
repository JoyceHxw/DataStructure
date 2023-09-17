// 假设你是一家合金制造公司的老板，你的公司使用多种金属来制造合金。现在共有 n 种不同类型的金属可以使用，并且你可以使用 k 台机器来制造合金。每台机器都需要特定数量的每种金属来创建合金。
// 对于第 i 台机器而言，创建合金需要 composition[i][j] 份 j 类型金属。最初，你拥有 stock[i] 份 i 类型金属，而每购入一份 i 类型金属需要花费 cost[i] 的金钱。
// 给你整数 n、k、budget，下标从 1 开始的二维数组 composition，两个下标从 1 开始的数组 stock 和 cost，请你在预算不超过 budget 金钱的前提下，最大化 公司制造合金的数量。
// 所有合金都需要由同一台机器制造。
// 返回公司可以制造的最大合金数。


#include <iostream>
using namespace std;
#include <vector>


// 逆向验证的思路是想到了，但是没细化实现代码
// 注意二分查找开闭区间写法的边界取值

class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        //逆向思维，造num个是否满足
        //二分搜索
        int ans=0;
        long long max_num=budget+stock[0];
        for(auto& com: composition){
            int left=0;
            int right=max_num+1;
            //左闭右开的区间写法，结果取left
            while(left+1<right){
                int mid=(left+right)/2;
                if(canMake(com,stock,cost,mid,budget)){
                    left=mid;
                }
                else{
                    right=mid;
                }
            }
            ans=max(ans,left);
            //闭区间写法，结果取right
            // while(left<=right){
            //     int mid=(left+right)/2;
            //     if(canMake(com,stock,cost,mid,budget)){
            //         left=mid+1;
            //     }
            //     else{
            //         right=mid-1;
            //     }
            // }
            // ans=max(ans,right);
        }
        return ans;
        
    }
    bool canMake(vector<int>& com, vector<int>& stock, vector<int>& cost, long long num, int budget){
        long long money=0;
        int n=com.size();
        for(int i=0; i<n; i++){
            if(stock[i]<com[i]*num){
                money+=  (com[i]*num-stock[i])*cost[i];
                if(money>budget){
                    return false;
                }
            }
        }
        return true;
    }
};