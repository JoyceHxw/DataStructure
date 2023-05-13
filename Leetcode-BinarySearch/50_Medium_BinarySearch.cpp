#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n==0 || x==1){
            double ans=1;
            return ans;
        }
        int n1=abs(n);
        long cnt=1;
        // double ans=x;
        // 二分法
        // while(cnt<n1){
        //     // 最后还是一次一次地乘，时间复杂度增加
        //     if(cnt*2>n1/2 && cnt*2>n1){
        //         ans*=x;
        //         cnt+=1;
        //     }
        //     else{
        //         ans=ans*ans;
        //         cnt*=2;
        //     }
        // }
        // 逆向
        double ans=1;
        while(n1>0){
            if(n1%2==1){
                // 从所有2的n次方的平方中选择需要的乘入
                ans*=x;
            }
            // 每个额外乘的 x 在之后都会被平方若干次
            // 统计所有2的n次方的平方
            x*=x;
            n1/=2;
        }
        if(n<0){
            return 1/ans;
        }
        else{
            return ans;
        }
    }
};