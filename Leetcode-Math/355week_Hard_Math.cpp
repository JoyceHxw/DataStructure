// 给你一个下标从 0 开始、长度为 n 的数组 usageLimits 。
// 你的任务是使用从 0 到 n - 1 的数字创建若干组，并确保每个数字 i 在 所有组 中使用的次数总共不超过 usageLimits[i] 次。此外，还必须满足以下条件：
// 每个组必须由 不同 的数字组成，也就是说，单个组内不能存在重复的数字。
// 每个组（除了第一个）的长度必须 严格大于 前一个组。
// 在满足所有条件的情况下，以整数形式返回可以创建的最大组数。

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// 这道hard题，不容易相通思路
class Solution {
public:
    int maxIncreasingGroups(vector<int>& usageLimits) {
        //从个数最多的数开始选择，超出时间限制
        // int cnt=0;
        // while(true){
        //     sort(usageLimits.begin(),usageLimits.end());
        //     reverse(usageLimits.begin(),usageLimits.end());
        //     int i=0;
        //     vector<int> temp;
        //     while(i<usageLimits.size() && usageLimits[i]>0 && i<cnt+1){
        //         usageLimits[i]-=1;
        //         i++;
        //     }
        //     if(i==cnt+1){
        //         cnt+=1;
        //     }
        //     else{
        //         return cnt;
        //     }
        //     int j=0;
        //     while(j<usageLimits.size()){
        //         if(usageLimits[j]==0){
        //             usageLimits.erase(usageLimits.begin()+j);
        //         }
        //         else{
        //             j++;
        //         }
        //     }
        // }

        // usageLimits中的每个数只能使组数增加1，因为要求数组中的数不同
        // 要使得组数最大，就是从数组长度为1的组开始构造，则需要的数的个数为（首项+末项）*项数/2
        // 排序后，按序相加得到数字的个数，是因为可以把当前个数的数逐个添加在已经构造好的每个组的后面，再增加一个组存放这一个数，就使得组数+1了
        // 如果个数和小于（首项+末项）*项数/2，说明不能使组数增加
        // 继续加上下一个数的个数，则后面不够的组可以用这个新添加的数来补充
        sort(usageLimits.begin(),usageLimits.end());
        long long ans=0;
        long long s=0;
        for(int i=0; i<usageLimits.size(); i++){
            s+=usageLimits[i];
            // 超出范围
            if(s>=(ans+2)*(ans+1)/2){
                ans+=1;
            }
        }
        return ans;
    }
};