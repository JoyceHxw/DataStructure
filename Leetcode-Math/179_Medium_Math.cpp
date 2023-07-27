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

        // 自定义排序，
        // 想到了字符串排序，但想到用拼接来比较
        // lambda表达式
        vector<string> nums_string(nums.size());
        for(int i=0; i<nums.size(); i++){
            nums_string[i]=to_string(nums[i]);
        }
        sort(nums_string.begin(),nums_string.end(), [](const string& a, const string& b){
            return a+b>b+a;
        });
        if(nums_string[0]=="0") {
            return "0";
        }
        string ret;
        for (string &x : nums_string) {
            ret += x;
        }
        return ret;
    }
};
