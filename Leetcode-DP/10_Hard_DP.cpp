// 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
// '.' 匹配任意单个字符
// '*' 匹配零个或多个前面的那一个元素
// 所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。


#include <iostream>
using namespace std;
#include <vector>

// 直观想法是双指针，但发现存在各种情况，很难完全考虑并写清楚
// 动态规划，思考状态dp和转移方程
class Solution {
public:
    bool isMatch(string s, string p) {
        // 注意*可以匹配0个前面的字符
        // 动态规划，需要考虑*匹配0/1/2/3...个字符，需要保存之前的状态
        // 检查两个字符是否匹配，参数i和j表示第几个
        auto matches = [&](int i, int j) {
            if (i == 0) { //f[0][j]=0, 1<j<p.length()
                return false;
            }
            if (p[j - 1] == '.') {
                return true;
            }
            return s[i - 1] == p[j - 1];
        };
        // f[i][j]表示s的前i个字符与p的前j个字符的匹配情况
        vector<vector<int>> f(s.length()+1,vector<int>(p.length()+1));
        f[0][0]=1;
        // 采用嵌套循环的方式，从小到大遍历所有可能，保存状态
        for(int i=0; i<=s.length(); i++){
            for(int j=1; j<=p.length(); j++){ 
                if(p[j-1]=='*'){
                    f[i][j]|=f[i][j-2]; // 匹配0个字符
                    if(matches(i,j-1)){ // 匹配多个字符
                        f[i][j]|=f[i-1][j]; // 前面能匹配上，多加一个相同字符也不影响，转换为子问题，难点
                    }
                }
                else{
                    if(matches(i,j)){
                        f[i][j]|=f[i-1][j-1];
                    }
                }
            }
        }
        return f[s.length()][p.length()];
    }
};