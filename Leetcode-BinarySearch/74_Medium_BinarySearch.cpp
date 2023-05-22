#include <iostream>
using namespace std;
#include <vector>

// 我的解答：用pair存储行和列，写起来比较繁琐
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        // 二分查找
        int i=0;
        int j=0;
        pair<int,int>left(0,0);
        pair<int,int>right(m-1,n-1);
        pair<int,int>mid(m/2,n/2);
        while((left.first*n+left.second)<=(right.first*n+right.second)){
            if(matrix[mid.first][mid.second]>target){
                if(mid.second==0){
                    right.first=mid.first-1;
                    right.second=n-1;
                }
                else{
                    right.first=mid.first;
                    right.second=mid.second-1;
                }
            }
            else if(matrix[mid.first][mid.second]<target){
                if(mid.second==n-1){
                    left.first=mid.first+1;
                    left.second=0;
                }
                else{
                    left.first=mid.first;
                    left.second=mid.second+1;
                }
            }
            else{
                return true;
            }
            mid.first=(((right.first*n+right.second)-(left.first*n+left.second)+1)/2+(left.first*n+left.second))/n;
            mid.second=(((right.first*n+right.second)-(left.first*n+left.second)+1)/2+(left.first*n+left.second))%n;
        }
        return false;
    }
};

// 答案：用/和%即可
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int m = matrix.size(), n = matrix[0].size();
//         int low = 0, high = m * n - 1;
//         while (low <= high) {
//             int mid = (high - low) / 2 + low;
//             int x = matrix[mid / n][mid % n];
//             if (x < target) {
//                 low = mid + 1;
//             } else if (x > target) {
//                 high = mid - 1;
//             } else {
//                 return true;
//             }
//         }
//         return false;
//     }
// };
