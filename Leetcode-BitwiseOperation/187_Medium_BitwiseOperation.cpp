#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

// 位运算很巧妙
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        // 哈希表，比较简单
        // unordered_map<string,int> m;
        // vector<string> ans;
        // if(s.length()<10){
        //     return ans;
        // }
        // for(int i=0; i<s.length()-9; i++){
        //     string temp;
        //     int k=0;
        //     while(k<10){
        //         temp+=s[i+k];
        //         k++;
        //     }
        //     if(m.find(temp)==m.end()){
        //         m[temp]++;
        //     }
        //     else{
        //         if(m[temp]==1){
        //             ans.push_back(temp);
        //             m[temp]++;
        //         }
        //     }
        // }
        // return ans;

        // 优化：滑动窗口和位运算
        const int L = 10;
        // 用低两位代表四个字符，不重复
        unordered_map<char, int> bin = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
        vector<string> ans;
        int n = s.length();
        if (n <= L) {
            return ans;
        }
        int x = 0;
        for (int i = 0; i < L - 1; ++i) {
            // 右移两位再加上后两位
            x = (x << 2) | bin[s[i]];
        }
        unordered_map<int, int> cnt;
        for (int i = 0; i <= n - L; ++i) {
            // 新加进右边的两位，最左边的两位移出
            x = ((x << 2) | bin[s[i + L - 1]]) & ((1 << (L * 2)) - 1);
            if (++cnt[x] == 2) {
                ans.push_back(s.substr(i, L));
            }
        }
        return ans;

    }
};