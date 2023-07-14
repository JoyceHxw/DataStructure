#include <iostream>
using namespace std;
#include <vector>
#include <unordered_set>

// 首先想到排序，但排序的时间复杂度都大于O(n)
// 从暴力开始思考，然后想到哈希表，然后优化
// 注意思路优化
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // 暴力：对于每一个数，枚举是否连续
        // 哈希表存储
        // 时间复杂度为O(n^2)
        // unordered_set<int> s;
        // int n=nums.size();
        // int ans=0;
        // for(int i=0; i<n; i++){
        //     s.insert(nums[i]);
        // }
        // for(int i=0; i<n; i++){
        //     int num=nums[i];
        //     int cnt=1;
        //     while(true){
        //         int t=num+cnt;
        //         if(s.find(t)!=s.end()){
        //             cnt+=1;
        //         }
        //         else{
        //             break;
        //         }
        //     }
        //     ans=max(ans,cnt);
        // }
        // return ans;

        // 优化，对于其中连续的数，如果存在前一个数，就可以跳过，时间复杂度为O(n)
        unordered_set<int> s;
        int n=nums.size();
        int ans=0;
        for(int i=0; i<n; i++){
            s.insert(nums[i]);
        }
        for(int i=0; i<n; i++){
            int num=nums[i];
            if(s.find(num-1)!=s.end()){
                continue;
            }
            else{
                int cnt=1;
                while(true){
                    int t=num+cnt;
                    if(s.find(t)!=s.end()){
                        cnt++;
                    }
                    else{
                        break;
                    }
                }
                ans=max(ans,cnt);
            }
        }
        return ans;

    }
};