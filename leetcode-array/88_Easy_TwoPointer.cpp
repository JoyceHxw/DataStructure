#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // 我的解法: 正向插入,元素后移
        // int i=0;
        // int j=0;
        // if(n==0){
        //     return;
        // }
        // while(i<m+n && j<n){
        //     if(nums2[j]>nums1[i]){
        //         i++;
        //     }
        //     else{
        //         for(int k=m+n-1; k>=i+1; k--){
        //             nums1[k]=nums1[k-1];
        //         }
        //         nums1[i]=nums2[j];
        //         j++;
        //     }
        //     cout<<"i="<<i<<endl;
        //     cout<<"j="<<j<<endl;
        // }
        // while(j<n){
        //     nums1[m+j]=nums2[j];
        //     j++;
        // }

        // 答案: 逆向双指针(有序数组,考虑双指针)
        int p1 = m - 1, p2 = n - 1;
        int tail = m + n - 1;
        int cur;
        while (p1 >= 0 || p2 >= 0) {
            if (p1 == -1) {
                cur = nums2[p2--];
            } 
            else if (p2 == -1) {
                cur = nums1[p1--];
            } 
            else if (nums1[p1] > nums2[p2]) {
                cur = nums1[p1--];
            } 
            else {
                cur = nums2[p2--];
            }
            nums1[tail--] = cur;
        }
    }
};

int main(){
    Solution s;
    vector<int>m_nums1;
    vector<int>m_nums2;
    m_nums1.push_back(-1);
    m_nums1.push_back(0);
    m_nums1.push_back(0);
    m_nums1.push_back(3);
    m_nums1.push_back(3);
    m_nums1.push_back(3);
    m_nums1.push_back(0);
    m_nums1.push_back(0);
    m_nums1.push_back(0);
    m_nums2.push_back(1);
    m_nums2.push_back(2);
    m_nums2.push_back(2);
    for(int i=0; i<9; i++){
        cout<<m_nums1[i]<<endl;
    }
    s.merge(m_nums1,6,m_nums2,3);
    for(int i=0; i<9; i++){
        cout<<m_nums1[i]<<endl;
    }
}