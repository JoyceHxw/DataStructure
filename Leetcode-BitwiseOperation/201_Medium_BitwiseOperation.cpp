#include <iostream>
using namespace std;

// 对于位运算的数字还是不太敏感，想不到位运算特征
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        // 暴力
        // int ans=left;
        // if(left==right){
        //     return ans;
        // }
        // for(long i=left+1;i<=right; i++){
        //     // cout<<ans<<" "<<i<<endl;
        //     ans&=i;
        // }
        // return ans;

        // 位移找公共前缀（数字是连续的，最后与的结果为公共前缀和零补充剩余位）
        int shift = 0;
        // 找到公共前缀
        // 先右移再左移
        while (left < right) {
            left >>= 1;
            right >>= 1;
            ++shift;
        }
        return left << shift;

    }
};