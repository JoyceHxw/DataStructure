// 给你一个整数数组 coins 表示不同面额的硬币，另给你一个整数 k 。
// 你有无限量的每种面额的硬币。但是，你 不能 组合使用不同面额的硬币。
// 返回使用这些硬币能制造的 第 kth 小 金额。

#include <iostream>
using namespace std;
#include <numeric> 
#include <vector>


//开始的想法是找规律，序列是循环的，找到第一个循环数组就可以得到第k个值，但是超时
//第k个数--》就需要想到二分法
//学习遍历集合的方法，学习容斥原理的实现
class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        // 找这些数的最小公倍数
        // int max_coin=coins[0];
        // for(int coin: coins){
        //     max_coin=max(coin,max_coin);
        // }
        // int min_mul=max_coin;
        // while(true){
        //     bool is_flag=true;
        //     for(int coin: coins){
        //         if(min_mul%coin!=0){
        //             is_flag=false;
        //             break;
        //         }
        //     }
        //     if(is_flag){
        //         break;
        //     }
        //     else{
        //         min_mul+=max_coin;
        //     }
        // }
        // // int min_mul=1;
        // // for(int coin: coins){
        // //     min_mul=lcm(min_mul,coin);
        // // }
        // //然后找一个循环的长度
        // set<int> s;
        // for(int coin: coins){
        //     int t=coin;
        //     while(coin<min_mul){
        //         s.insert(coin);
        //         coin+=t;
        //     }
        // }
        // s.insert(min_mul);
        // int length=s.size();
        // int cnt=k/length;
        // int remain=k%length;
        // long long ans;
        // if(remain==0){
        //     ans=*s.rbegin();
        //     return ans+min_mul*(cnt-1);
        // }
        // else{
        //     int i=1;
        //     auto it = s.begin();
        //     while(i<remain){
        //         i++;
        //         it++;
        //     }
        //     ans=*it;
        //     return ans+min_mul*cnt;
        // }

        //题目转换为2分法，有k种方法组合出不超过m的金额
        int n=coins.size();
        long long left=k-1, right=(long long) coins[0] * k;
        while(left<=right){
            long long mid=(left+right)/2;
            if(check(mid,n,k,coins)){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return left;
    }

    //检查m是否超过k种组合
    bool check(long long m, int n, int k, vector<int>& coins){
        //组合个数
        long long cnt=0;
        //枚举非空子集，找每个集合的公倍数
        //比如coins=[4,6], 子集有{4}->4，{6}->6，{4，6}->12
        //集合中每个元素去或不去有两种可能，一共有2^n中可能，当作二进制来看，所以1<<n
        for(int i=1; i<(1<<n); i++){
            long long lcm_res=1;
            int t=-1;
            for(int j=0; j<n; j++){
                //coins中第j个元素是否包含在集合中
                //检查从右往左第j位是否为1
                if(i>>j&1){
                    //容斥原理，加减交替（元素个数，单数加，双数减），如cnt=m/4+m/6-m/12
                    //统计1的个数，即集合的元素个数
                    t=-t;
                    //求最小公倍数
                    lcm_res=(lcm_res*coins[j])/gcd(lcm_res,coins[j]);
                    if(lcm_res>m){
                        break;
                    }
                }
            }
            //集合i对cnt的贡献
            cnt+=t*(m/lcm_res);
        }
        return cnt>=k;
    }
};