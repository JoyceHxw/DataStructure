#include <iostream>
using namespace std;
#include <vector>
#include <cmath>


//逆向思维！！！
class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        // //怎么分配修车数量使得时间最少
        // unordered_map<int,long long> m;
        // unordered_map<int,int> num;
        // int cnt=1;
        // //每次遍历找最小的时间
        // while(cnt<=cars){
        //     int min_index=0;
        //     long long min_time=INT_MAX;
        //     for(int i=0; i<ranks.size(); i++){
        //         if(min_time>(long long) ranks[i]*(num[i]+1)*(num[i]+1)){
        //             min_time=ranks[i]*(num[i]+1)*(num[i]+1);
        //             min_index=i;
        //         }
        //     }
        //     num[min_index]+=1;
        //     m[min_index]=num[min_index]*num[min_index]*ranks[min_index];
        //     cnt++;
        // }
        // long long ans=0;
        // auto iter=m.begin();
        // while(iter!=m.end()){
        //     ans=max(iter->second,ans);
        //     iter++;
        // }
        // return ans;

        //二分法枚举时间t
        //逆向思维
        long long left=1;
        long long right=(long long)ranks[0]*cars*cars;
        //函数检验是否在特定时间内能完成
        auto check=[&](long long m){
            long long cnt=0;
            for(auto x:ranks){
                cnt+=sqrt(m/x); //逆向求解能修的车的数量
            }
            return cnt>=cars;
        };
        //二分查找最小值
        while(left<right){
            long long mid=(left+right)>>1;
            if(check(mid)){
                right=mid;
            }
            else{
                left=mid+1;
            }
        }
        return left;

    }
};