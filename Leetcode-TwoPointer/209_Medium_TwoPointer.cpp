#include <iostream>
using namespace std;
#include <vector>


// 典型的双指针/滑动窗口题，经过上周周赛，自己顺利地做出来了
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // 双指针
        int right=0;
        int s=0;
        int cnt=nums.size();
        bool isflag=false;
        for(int i=0; i<nums.size(); i++){
            while(s<target && right<nums.size()){
                s+=nums[right];
                right++;
            }
            if(s>=target){
                isflag=true;
                cnt=min(cnt,right-i);
            }
            s-=nums[i];
        }
        if(isflag){
            return cnt;
        }
        else{
            return 0;
        }
    }
};