#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int numDecodings(string s) {
        // 首先想用回溯法搜索满足条件的解法，但复杂度是2的n次方
        // 使用动态规划，注意思考状态转移方程
        int n = s.size();
        vector<int> f(n + 1);
        f[0] = 1;
        // 前i个字符的解码方式数，取决于前i-1个字符和i-2个字符的解码方式数
        for (int i = 1; i <= n; ++i) {
            // 单个字符解码
            if (s[i - 1] != '0') { 
                f[i] += f[i - 1];
            }
            // 与前一个字符一起解码
            if (i > 1 && s[i - 2] != '0' && ((s[i - 2] - '0') * 10 + (s[i - 1] - '0') <= 26)) {
                f[i] += f[i - 2];
            }
        }
        return f[n];
    }
};