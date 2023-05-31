#include <iostream>
using namespace std;
#include <vector>


// 目前对于递归操作的步骤已经较熟悉了，但还需要注意其中的细节，如剪枝的条件，状态是否回退，没考虑到的情况
class Solution {
public:
    bool ans=false;
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> visit(board.size(), vector<int>(board[0].size()));
        // 起点
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j]==word[0]){
                    dfs(board,visit,word,i,j,0);
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<char>>& board,vector<vector<int>>& visit, string word, int a, int b, int i){
        if(a<0 || a>=board.size() || b<0 || b>=board[0].size() || visit[a][b]==1){
            return;
        }
        if(board[a][b]!=word[i]){
            return;
        }
        if(board[a][b]==word[i] && i==word.length()-1){
            ans=true;
            visit[a][b]=1;
            return;
        }
        visit[a][b]=1;
        dfs(board,visit,word,a+1,b,i+1);
        dfs(board,visit,word,a,b+1,i+1);
        dfs(board,visit,word,a-1,b,i+1);
        dfs(board,visit,word,a,b-1,i+1);
        visit[a][b]=0;
        return;
    }
};

int main(){
    Solution s;
    vector<vector<char>> board={{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    cout<<s.exist(board, "SEE");
}