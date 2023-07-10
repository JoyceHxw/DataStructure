#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // 不能使用双指针，存在同时满足两种条件的情况，需要再判断
        // int p1=0;
        // int p2=0;
        // for(int i=0; i<s3.length(); i++){
        //     if(p1<s1.length() && s3[i]==s1[p1]){
        //         p1++;
        //     }
        //     if(p2<s2.length() && s3[i]==s2[p2]){
        //         p2++;
        //     }
        // }
        // if(p1==s1.length() && p2==s2.length() && p1+p2==s3.length()){
        //     return true;
        // }
        // return false;

        // 动态规划，状态转移方程是前i-1个是否是交错的，和当前第i个是否满足条件
        // 注意状态转移方程和滚动数组
        if(s1.length()+s2.length()!=s3.length()){
            return false;
        }
        // 前i个是否满足
        vector<bool> f(s2.length()+1,false);
        f[0]=true;
        // 分为两种情况：
        // s3当前第i+j个字符与s1的第i个字符相同，
        // s3当前第i+j个字符与s2的第j个字符相同
        // 两种满足一种即说明可以由s1和s2交错组成
        for(int i=0; i<=s1.length(); i++){
            for(int j=0; j<=s2.length(); j++){
                int k=i+j-1;
                // 第一种情况，s2的前j个字符能组成
                if(i>0){
                    // 利用滚动数组优化空间 f[i][j] |= (f[i - 1][j] && s1[i - 1] == s3[p]);
                    f[j]=(f[j] && s1[i-1]==s3[k]);
                }
                // 第二种情况，s1的前i个字符能组成
                if(j>0){
                    // 利用滚动数组优化空间 f[i][j] |= (f[i][j - 1] && s2[j - 1] == s3[p]);
                    f[j]=(f[j] || (f[j-1] && s2[j-1]==s3[k]));
                }
            }
        }
        return f[s2.length()];

    }
};