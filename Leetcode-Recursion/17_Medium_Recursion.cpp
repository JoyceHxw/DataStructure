#include <iostream>
using namespace std;
#include <vector>
#include <map>

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // 我的解法
        map<char,string>d;
        d['2']="abc";
        d['3']="def";
        d['4']="ghi";
        d['5']="jkl";
        d['6']="mno";
        d['7']="pqrs";
        d['8']="tuv";
        d['9']="wxyz";
        vector<string>v;
        if(digits==""){
            return v;
        }
        v.resize(1);
        int cnt=0;
        while(cnt<digits.length()){
            vector<string>v_copy;
            for(int i=0; i<v.size(); i++){
                for(int j=0; j<d[digits[cnt]].length(); j++){
                    string s=v[i];
                    char x=d[digits[cnt]][j];
                    s+=x;
                    // cout<<s<<endl;
                    v_copy.push_back(s);
                }
            }
            // for(int k=0; k<v_copy.size(); k++){
            //     cout<<v_copy[k]<<endl;
            // }
            // cout<<c<<endl;
            v=v_copy;
            cnt++;
        }
        return v;
    }
};

// 答案：调用递归
// class Solution {
// public:
//     vector<string> letterCombinations(string digits) {
//         vector<string> combinations;
//         if (digits.empty()) {
//             return combinations;
//         }
//         unordered_map<char, string> phoneMap{
//             {'2', "abc"},
//             {'3', "def"},
//             {'4', "ghi"},
//             {'5', "jkl"},
//             {'6', "mno"},
//             {'7', "pqrs"},
//             {'8', "tuv"},
//             {'9', "wxyz"}
//         };
//         string combination;
//         backtrack(combinations, phoneMap, digits, 0, combination);
//         return combinations;
//     }

//     void backtrack(vector<string>& combinations, const unordered_map<char, string>& phoneMap, const string& digits, int index, string& combination) {
//         if (index == digits.length()) {
//             combinations.push_back(combination);
//         } else {
//             char digit = digits[index];
//             const string& letters = phoneMap.at(digit);
//             for (const char& letter: letters) {
//                 combination.push_back(letter);
//                 backtrack(combinations, phoneMap, digits, index + 1, combination);
//                 combination.pop_back();
//             }
//         }
//     }
// };
