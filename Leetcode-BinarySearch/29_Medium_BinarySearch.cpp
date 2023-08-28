#include <iostream>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        // int ans=0;
        // int dividend_neg=dividend;
        // if(dividend>0){
        //     dividend_neg=0-dividend;
        // }
        // int divisor_neg=divisor;
        // if(divisor>0){
        //     divisor_neg=0-divisor;
        // }
        // while(dividend_neg<=divisor_neg){
        //     dividend_neg-=divisor_neg;
        //     ans-=1;
        // }
        // if((dividend<0 && divisor>0) || (dividend>0 && divisor<0)){
        //     return ans;
        // }
        // if(ans<=-2147483648){
        //     return 2147483647;
        // }
        // return 0-ans;

        if(dividend == 0) return 0;
        if(divisor == 1) return dividend;
        if(divisor==-1){
            if(dividend>INT_MIN) return -dividend;
            return INT_MAX;
        }
        // 转换为负数，使用int
        int dividend_neg=dividend;
        if(dividend>0){
            dividend_neg=0-dividend;
        }
        int divisor_neg=divisor;
        if(divisor>0){
            divisor_neg=0-divisor;
        }
        int ans=div(dividend_neg,divisor_neg);
        cout<<dividend_neg<<" "<<divisor_neg;
        if((dividend<0 && divisor>0) || (dividend>0 && divisor<0)){
            return ans;
        }
        if(ans<=INT_MIN){
            return INT_MAX;
        }
        return 0-ans;
    }
    // 两数相除的结果
    int div(int a, int b){
        if(a>b){
            return 0;
        }
        int count=-1;
        int tb=b;
        while(tb>=a-tb){
            // 翻倍
            count+=count;
            tb+=tb;
        }
        // 递归剩下的数
        return count+div(a-tb,b);
    }
};