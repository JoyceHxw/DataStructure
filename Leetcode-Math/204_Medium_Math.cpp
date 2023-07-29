#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> v(n+1,1);
        // 模拟，超时
        if(n<=2){
            return 0; 
        }
        int cnt=0;
        for(int i=2; i<n; i++){
            // 起始为2，3，是质数，然后筛除其倍数的合数，就不用遍历了
            if(v[i]){
                cnt++;
                // 优化，倍数一定为合数
                // 从i*i开始筛除，因为小于i的倍数的i一定已经被其他小于i的质数筛除了
                if((long long)i*i<n){
                    for(int j=i*i; j<n; j+=i){
                        v[j]=0;
                    }
                }
            }
        }
        return cnt;
    }
};