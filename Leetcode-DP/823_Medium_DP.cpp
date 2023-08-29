#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>


// 思路：开始利用递归和双指针，但是超时
// 然后考虑动态规划，基于排序，可以按从小到达的顺序计算以每个元素为根节点的二叉树数的数目，最后加总
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        long long ans=0;
        long long mod=1e9+7;
        // for(auto num: arr){
        //     ans=(ans+recursion(arr,num))%mod;
        // }
        // return ans%mod;

        // 动态规划
        int n=arr.size();
        vector<int> dp(n);
        for(int i=0;i<n; i++){
            int left=0;
            int right=i-1;
            dp[i]=1;
            while(left<=right){
                long long left_num=arr[left];
                long long right_num=arr[right];
                long long temp=left_num*right_num;
                if( temp ==arr[i]){
                    if(left!=right){
                        dp[i]=(dp[i]+(long long) dp[left]*dp[right]*2)%mod;
                    }
                    else{
                        dp[i]=(dp[i]+(long long) dp[left]*dp[right])%mod;
                    }
                    left++;
                    right--;
                }
                else if(temp<arr[i]){
                    left++;
                }
                else{
                    right--;
                }
            }
            ans=(ans+dp[i])%mod;
        }
        return ans;

    }
    // 递归
    long long recursion(vector<int>& arr, int target){
        long long ans=1;
        long long mod=10e9+7;
        int left=0;
        int right=arr.size()-1;
        while(left<=right){
            long long left_num=arr[left];
            long long right_num=arr[right];
            long long temp=left_num*right_num;
            if( temp ==target){
                if(left!=right){
                    ans=(ans+recursion(arr,arr[left])*recursion(arr,arr[right])*2)%mod;
                }
                else{
                    ans=(ans+recursion(arr,arr[left])*recursion(arr,arr[right]))%mod;
                }
                left++;
                right--;
            }
            else if(temp<target){
                left++;
            }
            else{
                right--;
            }
        }
        return ans;

    }
};