#include <iostream>
using namespace std;
#include <vector>

// 动态规划考虑不同状态
// 限制了股票买卖次数为2次
// 所以有四个状态转移方程
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // 注意buy的初始状态
        int buy1 = -prices[0], sell1 = 0;
        // 在转移时允许在同一天买入并且卖出，所以第二次交易的初始状态相同
        int buy2 = -prices[0], sell2 = 0;
        for (int i = 1; i < n; ++i) {
            buy1 = max(buy1, -prices[i]);
            sell1 = max(sell1, buy1 + prices[i]);
            buy2 = max(buy2, sell1 - prices[i]);
            sell2 = max(sell2, buy2 + prices[i]);
        }
        return sell2;
    }
};