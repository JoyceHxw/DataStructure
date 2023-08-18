#include <iostream>
using namespace std;
#include <unordered_map>
#include <vector>

class Solution {
public:
    string longestPalindrome(string s) {
        // 我的解法：优化的暴力解法，可以通过测试用例
        // unordered_map<int,pair<int,int>> dict;
        // int cnt=1;
        // // 回文串起始位置
        // for(int i=0; i<s.length(); i++){
        //     // 回文串终止位置
        //     // 从后往前验证，如果有就直接退出循环
        //     for(int j=s.length()-1; j>i; j--){
        //         // 验证回文串
        //         bool isFlag=true;
        //         for(int k=0; k<(j-i+1)/2; k++){
        //             if(s[i+k]!=s[j-k]){
        //                 isFlag=false;
        //                 break;
        //             }
        //         }
        //         if(isFlag==true){
        //             pair<int,int> p(i,j);
        //             dict[j-i+1]=p;
        //             cnt=max(cnt,j-i+1);
        //             break;
        //         }
        //     }
        // }
        // return s.substr(dict[cnt].first,cnt);


        // 答案：动态规划
        // int n = s.size();
        // if (n < 2) {
        //     return s;
        // }

        // int maxLen = 1;
        // int begin = 0;
        // // dp[i][j] 表示 s[i..j] 是否是回文串
        // vector<vector<int>> dp(n, vector<int>(n));
        // // 初始化：所有长度为 1 的子串都是回文串
        // for (int i = 0; i < n; i++) {
        //     dp[i][i] = true;
        // }
        // // 递推开始
        // // 先枚举子串长度
        // for (int L = 2; L <= n; L++) {
        //     // 枚举左边界，左边界的上限设置可以宽松一些
        //     for (int i = 0; i < n; i++) {
        //         // 由 L 和 i 可以确定右边界，即 j - i + 1 = L 得
        //         int j = L + i - 1;
        //         // 如果右边界越界，就可以退出当前循环
        //         if (j >= n) {
        //             break;
        //         }

        //         if (s[i] != s[j]) {
        //             dp[i][j] = false;
        //         } 
        //         else {
        //             if (j - i < 3) {
        //                 dp[i][j] = true;
        //             } 
        //             else {
        //                 dp[i][j] = dp[i + 1][j - 1];
        //             }
        //         }

        //         // 只要 dp[i][L] == true 成立，就表示子串 s[i..L] 是回文，此时记录回文长度和起始位置
        //         if (dp[i][j] && j - i + 1 > maxLen) {
        //             maxLen = j - i + 1;
        //             begin = i;
        //         }
        //     }
        // }
        // return s.substr(begin, maxLen);

        // 第二遍
        // 枚举中心
        // 比枚举数组验证好在，避免了相同中心点不同长度的数组
        int max_len=0;
        int start;
        for(int i=0; i<s.length(); i++){
            // 奇数
            int left1=i-1;
            int right1=i+1;
            while(left1>=0 && right1<s.length()){
                if(s[left1]!=s[right1]){
                    break;
                }
                else{
                    left1--;
                    right1++;
                }
            }
            if(right1-left1-1>max_len){
                max_len=right1-left1-1;
                start=left1+1;
            }
            // 偶数
            int left2=i;
            int right2=i+1;
            while(left2>=0 && right2<s.length()){
                if(s[left2]!=s[right2]){
                    break;
                }
                else{
                    left2--;
                    right2++;
                }
            }
            if(right2-left2-1>max_len){
                max_len=right2-left2-1;
                start=left2+1;
            }
        }
        return s.substr(start,max_len);

    }
};
