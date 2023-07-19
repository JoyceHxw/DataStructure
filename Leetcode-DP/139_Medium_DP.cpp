#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


// 现在可以较顺利地写出回溯了，但对于动态规划还是不太容易想到
class Solution {
public:
    // 回溯
    // bool wordBreak(string s, vector<string>& wordDict) {
    //     unordered_set<string> hash_s;
    //     for(int i=0; i<wordDict.size(); i++){
    //         hash_s.insert(wordDict[i]);
    //     }
    //     bool ans=false;
    //     recursion(s,hash_s,0,0,ans);
    //     return ans;
    // }
    // void recursion(string& s, unordered_set<string>& hash_s, int start, int end, bool& ans){
    //     if(start>=s.length()){
    //         ans=true;
    //         return;
    //     }
    //     if(end>=s.length()){
    //         return;
    //     }
    //     string temp=s.substr(start,end-start+1);
    //     cout<<temp<<endl;
    //     if(hash_s.find(temp)!=hash_s.end()){
    //         recursion(s,hash_s,end+1,end+1,ans);
    //     }
    //     recursion(s,hash_s,start,end+1,ans);
    // }

    //动态规划
    bool wordBreak(string s, vector<string>& wordDict) {
        // 前i个字符组成的字符串是否满足条件取决于这i个字符串的划分方式
        // 这i个字符串的划分方式取决于前i-1个字符串的划分方式
        unordered_set<string> hash_s;
        for(int i=0; i<wordDict.size(); i++){
            hash_s.insert(wordDict[i]);
        }
        vector<bool> dp(s.length()+1);
        dp[0]=true;
        // 字符串长度
        for(int i=1; i<=s.length(); i++){
            // 划分断点
            for(int j=0; j<i; j++){
                if(dp[j] && hash_s.find(s.substr(j,i-j))!=hash_s.end()){
                    dp[i]=true;
                }
            }
        }
        return dp[s.length()];
    }
};