#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    // 自己写的递归，超出时间限制
    // int jump(vector<int>& nums) {
    //     vector<int> ans;
    //     step(ans,0,nums[0],0,nums);
    //     int res=nums.size();
    //     for(int i=0; i<ans.size(); i++){
    //         cout<<ans[i]<<endl;
    //         if(res>ans[i]){
    //             res=ans[i];
    //         }
    //     }
    //     return res;
    // }
    // void step(vector<int>& ans,int start, int steps, int cnt, vector<int>& nums){
    //     if(start>=nums.size()-1){
    //         ans.push_back(cnt);
    //         return; // 结束，添加一条路径的答案
    //     }
    //     else if(steps==0){
    //         return; //剪枝
    //     }
    //     else{
    //         int j=1;
    //         while(j<=steps && start+j<nums.size()){
    //             cnt+=1;
    //             step(ans,start+j,nums[start+j],cnt,nums);
    //             cnt-=1;
    //             j++;
    //         }
    //     }
    // }
    
    // 优化，动态规划/贪心算法
    // 这一步的下一步能达到最远
    int jump(vector<int>& nums) {
        int cnt=0;
        int i=0;
        while(i<nums.size()-1){
            int next_pos=i+1;
            int next_step=0;
            for(int j=1;j<=nums[i];j++){
                if((i+j)<nums.size() && next_pos+next_step<i+j+nums[i+j]){
                    next_step=nums[i+j];
                    next_pos=i+j;
                }
                if(i+j>=nums.size()-1){
                    next_pos=i+j;
                }
            }
            i=next_pos;
            cnt+=1;
        }
        return cnt;
    }
};