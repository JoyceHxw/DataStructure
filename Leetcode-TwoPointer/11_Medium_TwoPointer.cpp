#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int maxArea(vector<int>& height) {
        // 暴力，超出时间限制
        // int max_volumn=0;
        // for(int i=0; i<height.size(); i++){
        //     for(int j=i+1; j<height.size(); j++){
        //         max_volumn=max(max_volumn,(j-i)*min(height[i],height[j]));
        //     }
        // }
        // return max_volumn;

        // 双指针
        int left=0;
        int right=height.size()-1;
        int max_volumn=0;
        while(left<right){
            max_volumn=max(max_volumn,(right-left)*min(height[left],height[right]));
            // 移动短板才有可能使体积变大
            if(height[left]>height[right]){
                right--;
            }
            else{
                left++;
            }
        }
        return max_volumn;
    }
};