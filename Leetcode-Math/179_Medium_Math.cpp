#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // 有相同前缀时错误
        // vector<string> nums_string(nums.size());
        // for(int i=0; i<nums.size(); i++){
        //     nums_string[i]=to_string(nums[i]);
        // }
        // sort(nums_string.begin(),nums_string.end());
        // string ans;
        // for(int i=nums_string.size()-1; i>=0; i--){
        //     ans+=nums_string[i];
        // }
        // return ans;

        // 自定义排序，但自己没想出排序方法
        // lambda表达式
        sort(nums.begin(), nums.end(), [](const int &x, const int &y) {
            // 计算x y 和 y x 的拼接结果
            long sx = 10, sy = 10;
            // y在前，x在后
            while (sx <= x) {
                sx *= 10;
            }
            // x在前，y在后
            while (sy <= y) {
                sy *= 10;
            }
            return sy * x + y > sx * y + x;
        });
        if (nums[0] == 0) {
            return "0";
        }
        string ret;
        for (int &x : nums) {
            ret += to_string(x);
        }
        return ret;
    }
};