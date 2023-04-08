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
        int n = s.size();
        if (n < 2) {
            return s;
        }

        int maxLen = 1;
        int begin = 0;
        // dp[i][j] 表示 s[i..j] 是否是回文串
        vector<vector<int>> dp(n, vector<int>(n));
        // 初始化：所有长度为 1 的子串都是回文串
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        // 递推开始
        // 先枚举子串长度
        for (int L = 2; L <= n; L++) {
            // 枚举左边界，左边界的上限设置可以宽松一些
            for (int i = 0; i < n; i++) {
                // 由 L 和 i 可以确定右边界，即 j - i + 1 = L 得
                int j = L + i - 1;
                // 如果右边界越界，就可以退出当前循环
                if (j >= n) {
                    break;
                }

                if (s[i] != s[j]) {
                    dp[i][j] = false;
                } 
                else {
                    if (j - i < 3) {
                        dp[i][j] = true;
                    } 
                    else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                // 只要 dp[i][L] == true 成立，就表示子串 s[i..L] 是回文，此时记录回文长度和起始位置
                if (dp[i][j] && j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxLen);

    }
};