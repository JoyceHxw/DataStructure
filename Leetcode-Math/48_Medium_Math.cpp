#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 第一行旋转后变成倒数第一列
        // 第二行旋转后变成倒数第二列。。。
        // 原地旋转不好弄
        // int n=matrix.size();
        // for(int row=0; row<n; row++){
        //     for(int column=0; column<n; column++){
        //         matrix[column][n-row-1]=matrix[row][column];
        //     }
        // }
        
        // 水平翻转+主对角线翻转
        int n=matrix.size();
        for(int i=0; i<n/2; i++){
            for(int j=0; j<n; j++){
                int temp=matrix[i][j];
                matrix[i][j]=matrix[n-i-1][j];
                matrix[n-i-1][j]=temp;
            }
        }
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                int temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }
    }
};