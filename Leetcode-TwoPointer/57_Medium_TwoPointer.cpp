#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // 注意考虑无重叠的情况
        // int left = newInterval[0];
        // int right = newInterval[1];
        // bool placed = false;
        // vector<vector<int>> ans;
        // for (const auto& interval: intervals) {
        //     if (interval[0] > right) {
        //         // 在插入区间的右侧且无交集
        //         if (!placed) {
        //             ans.push_back({left, right});
        //             placed = true;                    
        //         }
        //         ans.push_back(interval);
        //     }
        //     else if (interval[1] < left) {
        //         // 在插入区间的左侧且无交集
        //         ans.push_back(interval);
        //     }
        //     else {
        //         // 与插入区间有交集，计算它们的并集
        //         left = min(left, interval[0]);
        //         right = max(right, interval[1]);
        //     }
        // }
        // if (!placed) {
        //     ans.push_back({left, right});
        // }
        // return ans;

        // 第二遍，虽然遍历了两次，但基本思路熟悉了
        if(intervals.size()==0){
            return {newInterval};
        }
        vector<vector<int>> ans;
        int start=newInterval[0];
        int end=newInterval[1];
        // 找重叠部分的端点
        for(auto comb: intervals ){
            if(comb[0]<=newInterval[0] && comb[1]>=newInterval[0]){
                start=comb[0];
            }
            if(comb[0]<=newInterval[1] && comb[1]>=newInterval[1]){
                end=comb[1];
            }
        }
        // 插入数据，已无重叠部分，只需考虑插入位置和原有组合是否插入
        bool isFlag=false;
        for(auto comb: intervals){
            if(comb[0]>end){
                if(!isFlag){
                    ans.push_back({start,end});
                    isFlag=true;
                }
                ans.push_back(comb);
            }
            else if(comb[0]>=start && comb[1]<=end){
                continue;
            }
            else if(comb[1]<start){
                ans.push_back(comb);
            }
        }
        if(!isFlag){
            ans.push_back({start,end});
        }
        return ans;
    }
};
