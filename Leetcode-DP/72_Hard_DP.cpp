#include <iostream>
using namespace std;
#include <vector>

// 经典的编辑距离问题，可以用于匹配推荐算法
class Solution {
public:
    int minDistance(string word1, string word2) {
        //动态规划，基于以匹配的字符串增加或删除
        //对两个字符串的三种操作中，一个字符串的增加操作等价于对另一个字符串的删减操作，替换操作是等价的，所以可以简化情况
        int n=word1.length();
        int m=word2.length();
        // 有一个字符串为空串
        if (n * m == 0) return n + m;
        // DP 数组，表示word1前i个子串到word2前j个子串的编辑距离
        vector<vector<int>> D(n + 1, vector<int>(m + 1));
        // 初始化
        // 长度为i的子串到空串的编辑距离为i
        for(int i=0; i<n+1; i++){
            D[i][0]=i;
        }
        for(int j=0; j<m+1; j++){
            D[0][j]=j;
        }
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                int left=D[i-1][j]+1; //A添加一个字符
                int down=D[i][j-1]+1; //B添加一个字符
                int left_down=D[i-1][j-1];
                //A和B的最后一个字符是否相等，是否要修改
                if(word1[i-1]!=word2[j-1]){  
                    left_down+=1;
                }
                D[i][j]=min(left,min(down,left_down));
            }
        }
        return D[n][m];
    }
};