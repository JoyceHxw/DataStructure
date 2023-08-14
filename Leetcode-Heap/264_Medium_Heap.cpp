#include <iostream>
using namespace std;
#include <vector>
#include <unordered_set>
#include <queue>

class Solution {
public:
    int nthUglyNumber(int n) {
        // 暴力
        // int k=0;
        // int t=1;
        // while(k<n){
        //     bool isflag=true;
        //     int i=t;
        //     while(i!=1){
        //         if(i%2==0){
        //             i/=2;
        //             continue;
        //         }
        //         if(i%3==0){
        //             i/=3;
        //             continue;
        //         }
        //         if(i%5==0){
        //             i/=5;
        //             continue;
        //         }
        //         isflag=false;
        //         break;
        //     }
        //     if(isflag){
        //         k+=1;
        //     }
        //     t+=1;
        // }
        // return --t;
        
        // 下一个最小丑数，必然在前面的丑数*2/3/5中
        // 最小堆，维护当前最小值
        vector<int> factors={2,3,5};
        unordered_set<long> seen;
        priority_queue<long, vector<long>,greater<long>> heap;
        seen.insert(1); //避免重复
        heap.push(1);
        int ugly=0;
        for(int i=0; i<n; i++){
            long curr=heap.top();
            heap.pop();
            ugly=(int)curr;
            for(int factor: factors){
                long next=curr*factor;
                if(!seen.count(next)){
                    seen.insert(next);
                    heap.push(next);
                }
            }
        }
        return ugly;
    }
};