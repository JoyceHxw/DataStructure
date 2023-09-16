#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        // //word所有字符串长度相同

        //我的解法：找出满足条件的单词位置，然后拼凑试验是否满足，但不好代码实现
        // int n=s.length();
        // int m=words[0].length();
        // unordered_map<string,int> words_m;
        // for(auto& word: words){
        //     words_m[word]++;
        // }
        // //单词位置
        // vector<int> words_pos;
        // int i=0;
        // int j=0;
        // while(i<=n-m){
        //     string temp=s.substr(i,m);
        //     if(words_m[temp]>0){
        //         // cout<<i<<endl;
        //         words_pos.push_back(i);
        //     }
        //     i++;
        // }
        // int len=words.size();
        // i=0;
        // vector<int> ans;
        // while(i<words_pos.size()){
        //     unordered_map<string,int> m_temp;
        //     m_temp[s.substr(words_pos[i],m)]++;
        //     j=i+1;
        //     if(j<words_pos.size() && words_pos[j]-words_pos[i]>m){
        //         i++;
        //         continue;
        //     }
        //     //"ababababab"出错
        //     while(j<words_pos.size() && j-i<len && words_pos[j]-words_pos[j-1]==m){
        //         // cout<<"i="<<i<<endl;
        //         // cout<<"j="<<j<<endl;
        //         string temp=s.substr(words_pos[j],m);
        //         // cout<<temp<<endl;
        //         if(words_m[temp]>0 && m_temp[temp]<words_m[temp]){
        //             j++;
        //             m_temp[temp]++;
        //         }
        //         else{
        //             break;
        //         }
        //     }
        //     if(j-i==len){
        //         // cout<<words_pos[i]<<endl;
        //         ans.push_back(words_pos[i]);
        //     }
        //     i++;
        // }
        // return ans;


        //题解更直观，遍历所有划分单词的情况，然后采用滑动窗口得到所有解
        vector<int> res;
        int m = words.size(), n = words[0].size(), ls = s.size();
        for (int i = 0; i < n && i + m * n <= ls; ++i) {
            unordered_map<string, int> differ;
            for (int j = 0; j < m; ++j) {
                //记录长度为m*n的子串，逐个划分得到单词出现频率
                ++differ[s.substr(i + j * n, n)];
            }
            for (string &word: words) {
                //如果为0，表示子字符串的word单词频率与words中的相同，剔除不再考虑
                //如果words中的单词没出现过，也记录下来
                if (--differ[word] == 0) {
                    differ.erase(word);
                }
            }
            //滑动窗口
            //探测右边增加单词，左边去掉单词是否满足
            for (int start = i; start < ls - m * n + 1; start += n) {
                if (start != i) {
                    //右侧加入
                    string word = s.substr(start + (m - 1) * n, n);
                    if (++differ[word] == 0) {
                        differ.erase(word);
                    }
                    //左侧退出
                    word = s.substr(start - n, n);
                    if (--differ[word] == 0) {
                        differ.erase(word);
                    }
                }
                if (differ.empty()) {
                    res.emplace_back(start);
                }
            }
        }
        return res;
    }
};