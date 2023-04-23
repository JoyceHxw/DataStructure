#include <iostream>
using namespace std;
#include <vector>
#include <stack>

// 我的解法：暴力
// class Solution {
// public:
//     vector<string> generateParenthesis(int n) {
//         // 先列出所有可能，再删除
//         vector<string>all;
//         all.push_back("(");
//         all.push_back(")");
//         vector<char>paren;
//         paren.push_back('(');
//         paren.push_back(')');
//         for(int i=1; i<n*2;i++){
//             vector<string>temp;
//             for(int j=0; j<all.size(); j++){
//                 for(int k=0; k<2; k++){
//                     string a= all[j]+paren[k];
//                     temp.push_back(a);
//                 }
//             }
//             all=temp;
//         }
//         vector<string>ans;
//         for(int i=0; i<all.size(); i++){
//             stack<char>stk;
//             // cout<<all[i]<<endl;
//             bool isValid=true;
//             for(int j=0; j<2*n; j++){
//                 // cout<<all[i][j]<<endl;
//                 if (all[i][j]=='('){
//                     stk.push(all[i][j]);
//                 }
//                 else{
//                     if(stk.empty()){
//                         isValid=false;
//                         break;
//                     }
//                     else{
//                         stk.pop();
//                     }
//                 }
//             }
//             if (stk.empty() && isValid==true){
//                 ans.push_back(all[i]);
//             }
//         }
//         return ans;
//     }
// };

// 答案: 回溯(DFS)
class Solution {
    void backtrack(vector<string>& ans, string& cur, int open, int close, int n) {
        if (cur.size() == n * 2) {
            ans.push_back(cur);
            return;
        }
        if (open < n) {
            cur.push_back('(');
            backtrack(ans, cur, open + 1, close, n);
            cur.pop_back();
        }
        if (close < open) {
            cur.push_back(')');
            backtrack(ans, cur, open, close + 1, n);
            cur.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        backtrack(result, current, 0, 0, n);
        return result;
    }
};
