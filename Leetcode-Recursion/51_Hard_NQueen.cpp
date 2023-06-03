#include <iostream>
using namespace std;
#include <vector>


// 独立完成的N皇后问题！
// 思路从开始的保留每一格是否visit的思路，逐渐转变为增加保留每一列是否visit的思路，到增加两条对角线是否visit的思路
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        string dot="";
        for(int i=0; i<n; i++){
            dot+='.';
        }
        vector<vector<string>> ans;
        vector<string> board(n,dot);
        vector<int> visit_col(n,0);
        vector<int> visit_main(n+n-1,0);  // 从左上角到右下角
        vector<int> visit_vice(n+n-1,0);  // 从右上角到左下角
        recursion(ans,board,visit_col,visit_main, visit_vice,0,n);
        return ans;
    }
    void recursion(vector<vector<string>>& ans, vector<string>& board, vector<int>& visit_col,vector<int>& visit_main, vector<int>& visit_vice, int row, int n){
        // 全部放下
        if(row==n){
            ans.push_back(board);
            return;
        }

        // 试探一行的每一格
        for(int i=0; i<n; i++){
            if(visit_col[i]==0 && visit_main[row-i+n-1]==0 && visit_vice[row+i]==0){
                board[row][i]='Q';
                // 同一列
                visit_col[i]=1;
                // 同一斜线，注意是两条斜线
                visit_main[row-i+n-1]=1;
                visit_vice[row+i]=1;
                recursion(ans,board,visit_col,visit_main,visit_vice,row+1,n);
                // 退回，注意只退回当前行的后面行，
                // 有些格子可能即是以前行所在的列或斜线，也是当前行所在斜线
                // 所以增加一个保存列是否参加的参数，增加主对角线和副对角线是否参加的参数
                board[row][i]='.';
                // 同一列
                visit_col[i]=0;
                // 同一斜线
                visit_main[row-i+n-1]=0;
                visit_vice[row+i]=0;
            }
        }
        return;
    }
};

int main(){
    Solution s;
    s.solveNQueens(6);
}