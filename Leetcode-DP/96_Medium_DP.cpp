#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    // int numTrees(int n) {
    //     return getnum(1,n);   
    // }
    // 采用95题递归的方法超出实践限制
    // int getnum(int start, int end){
    //     if(start>end){
    //         return 1;
    //     }
    //     int num=0;
    //     for(int i=start; i<=end; i++){
    //         int leftnum=getnum(start,i-1);
    //         int rightnum=getnum(i+1,end);
    //         num+=leftnum*rightnum;
    //     }
    //     return num;
    // }

    // 同样的思路，改成递推，动态规划
    // 双层循环
    int numTrees(int n) {
        vector<int> f(n+1,0);
        f[0]=1;
        f[1]=1;
        // i个数（与具体数是什么无关，与个数有关）
        for(int i=2; i<=n; i++){
            // 以j为根节点，左边j-1个数组成左子树，右边i-j个数组成右子树
            for(int j=1; j<=i; j++){
                f[i]+=f[j-1]*f[i-j];
            }
        }
        return f[n];
    }
};