#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // int level=nums.size()/2;
        // vector<pair<int,int>>v;
        // for(int i=0; i<nums.size(); i++){
        //     bool isExist=false;
        //     for(int j=0; j<v.size(); j++){
        //         if(nums[i]==v[j].first){
        //             isExist=true;
        //             v[j].second+=1;
        //             break;
        //         }
        //     }
        //     if(isExist==false){
        //         pair<int,int>p(nums[i],1);
        //         v.push_back(p);
        //     }
        // }
        // for(int i=0; i<v.size(); i++){
        //     if(v[i].second>level){
        //         return v[i].first;
        //     }
        // }
        // return 0;

        // 注意hash表用什么容器
        // unordered_map是一个关联容器，内部采用的是hash表结构，拥有快速检索的功能。
        // 关联性：通过key去检索value，而不是通过绝对地址（和顺序容器不同）
        // 无序性：使用hash表存储，内部无序
        // Map : 每个值对应一个键值
        // 键唯一性：不存在两个元素的键一样
        // 动态内存管理：使用内存管理模型来动态管理所需要的内存空间
        unordered_map<int, int> counts;
        int majority = 0, cnt = 0;
        for (int num: nums) {  // for循环简写，相当于python的 for n in nums:
            ++counts[num];
            if (counts[num] > cnt) {
                majority = num;
                cnt = counts[num];
            }
        }
        return majority; //出现数量最多的

    }
};