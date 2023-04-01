#include <iostream>
using namespace std;
#include <unordered_map>
#include <stack>

class Solution {
public:
    bool isValid(string s) {
        // 栈
        // unordered_map<char,char>dict;
        // dict['(']=')';
        // dict['[']=']';
        // dict['{']='}';
        // int i=0;
        // char* stack=new char[s.length()];
        // int j=0;
        // while(i<s.length()){
        //     if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
        //         stack[j]=s[i];
        //         j++;
        //     }
        //     else{
        //         if(j==0){
        //             return false;
        //         }
        //         else{
        //             if(s[i]==dict[stack[j-1]]){
        //                 j--;
        //             }
        //             else{
        //                 return false;
        //             }
        //         }
        //     }
        //     i++;
        // }
        // if(j==0){
        //     return true;
        // }
        // else{
        //     return false;
        // }

        // 注意hash表赋值方法
        // 注意stack类使用方法
        int n = s.size();
        if (n % 2 == 1) {
            return false;
        }

        unordered_map<char, char> pairs = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        stack<char> stk;
        for (char ch: s) {
            if (pairs.count(ch)) {
                if (stk.empty() || stk.top() != pairs[ch]) {
                    return false;
                }
                stk.pop();
            }
            else {
                stk.push(ch);
            }
        }
        return stk.empty();

    }
};