#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 二分查找
        // int m=matrix.size();
        // int n=matrix[0].size();
        // // 每一行进行二分查找，超时
        // // 优化：定位开头和结尾是否包含target
        // for(int i=0; i<m; i++){
        //     if(matrix[i][0]<=target && matrix[i][n-1]>=target){
        //         int left=0;
        //         int right=n-1;
        //         while(left<=right){
        //             int mid=(left+right)/2;
        //             if(matrix[i][mid]<target){
        //                 left=left+1;
        //             }
        //             else if(matrix[i][mid]>target){
        //                 right=right-1;
        //             }
        //             else{
        //                 return true;
        //             }
        //         }
        //     }
        //     else{
        //         continue;
        //     }
        // }
        // return false;

        // Z字形查找：充分利用矩阵每行每列升序排列的特点，以右上角为起点
        int m=matrix.size();
        int n=matrix[0].size();
        int x=0; 
        int y=n-1;
        while(x<m && y>=0){
            if(matrix[x][y]<target){
                x+=1;
            }
            else if(matrix[x][y]>target){
                y-=1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};