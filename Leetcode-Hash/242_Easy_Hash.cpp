#include <iostream>
using namespace std;
#include <unordered_map>
#include <vector>

class Solution {
public:
    bool isAnagram(string s, string t) {
        // hash
        // 我的解答：构建两个hash表，多次循环比较
        // unordered_map<char,int> dict;
        // for(int i=0; i<s.length(); i++){
        //     dict[s[i]]+=1;
        // }
        // unordered_map<char,int> dict2;
        // for(int i=0; i<t.length(); i++){
        //     dict2[t[i]]+=1;
        // }
        // int i=0;
        // while(i<s.length() && i<t.length()){
        //     if(dict[s[i]]!=dict2[s[i]]){
        //         return false;
        //     }
        //     i++;
        // }
        // if(i==s.length() && i==t.length()){
        //     return true;
        // }
        // else{
        //     return false;
        // }

        // 答案：巧妙运用字母顺序表，减少循环次数
        if (s.length() != t.length()) {
            return false;
        }
        vector<int> table(26, 0);
        for (auto& ch: s) {
            table[ch - 'a']++;
        }
        for (auto& ch: t) {
            table[ch - 'a']--;
            if (table[ch - 'a'] < 0) {
                return false;
            }
        }
        return true;
        
    }
};