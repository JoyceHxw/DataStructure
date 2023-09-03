#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>


// 我的思路是先保存满足num[i]%modulo==k的下标，然后根据下标对应每个cnt找c组合数量，但是这种方法要考虑很多边界情况，我最终也没有成功通过
// 把满足条件的下标的值转换为1，否则为0，就可以巧妙地运用前缀和进行相减，得到cnt
// 找满足条件的左右边界的前缀和相减得到cnt，采用哈希表，基于模运算公式的变换
// 遇到区间的题本质上可以考虑滑窗或者前缀和
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        //前缀和+哈希表
        long long ans=0;
        unordered_map<int,int> cnt;
        cnt[0]=1;
        int s=0;
        // 以右边界进行遍历，找对应的左边界的数量
        for(int x:nums){
            s+= (x%modulo==k);
            ans+= cnt[(s-k+modulo)%modulo];//  避免减法出现负数
            cnt[s%modulo]++;
        }
        return ans;
    }
};