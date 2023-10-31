#include <iostream>
using namespace std;
#include <vector>

//想到了应该是选择子序列，但是没有想到动态规划
class Solution {
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        //动态规划
        //选择元素添加为k
        //表示右边距离大于k的元素的距离
        long long f0=0;
        long long f1=0;
        long long f2=0;
        for(int num: nums){
            //状态转移方程：选或不选，不选则保留间隔多一个的值，间隔2个的时候必须选，不然就超过3个了
            //选：右边的值大于k，在上一轮f0的基础之上增加操作
            long long temp=f0+max(k-num,0);
            f0=min(temp,f1);
            f1=min(temp,f2);
            f2=temp;
            // cout<<f0<<" "<<f1<<" "<<f2<<endl;
        }
        return f0;
    }
};