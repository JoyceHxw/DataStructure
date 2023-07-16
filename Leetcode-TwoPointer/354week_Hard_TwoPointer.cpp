// 给你一个字符串 word 和一个字符串数组 forbidden 。
// 如果一个字符串不包含 forbidden 中的任何字符串，我们称这个字符串是 合法 的。
// 请你返回字符串 word 的一个 最长合法子字符串 的长度。
// 子字符串 指的是一个字符串中一段连续的字符，它可以为空。

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_set>

// 分析子字符串和包含之间的关系，找到切入点
// 查找时考虑哈希表
class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        // 哈希表减少时间
        unordered_set<string> fb{forbidden.begin(), forbidden.end()};
        // 左端点和右端点确定一个子字符串
        // 当该子字符串在forbidden中时，以该子串为延申的字符串就都不行，所以left右移
        // 整个过程是left右移
        int ans=0;
        int left=0;
        for(int right=0; right<word.length(); right++){
            // 决定left是否右移
            // 从短到长遍历子字符串
            int i=right;
            // forbidden的字符串长度不超过10
            while(i>=max(left,right-9)){
                string s=word.substr(i,right-i+1);
                if(fb.find(s)!=fb.end()){
                    left=i+1;
                    break;
                }
                i--;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};