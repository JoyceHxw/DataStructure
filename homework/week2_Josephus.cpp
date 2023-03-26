// 一个刚出锅的山芋，在围成一圈的n（以编号1，2，3...n分别表示 ）个孩子间传递。
// 大家一起数数，从编号为1的孩子开始报数，每数一次，当前拿着山芋的孩子就把山芋交给紧邻其右的孩子。
// 一旦数到事先约定的某个数k ， 那个人就出列，他的下一个人又从1开始报数，数到数k的那个人就出列。
// 如此反复，最后剩下的那个孩子就是幸运者。

// 试实现算法josephus（int n, int k），输出孩子们出列的次序

#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cin>>n;
    int circle[n]={0};
    int k;
    cin>>k;
    int cnt=0, i=0, m=0;  //cnt次数，i值，m报数
    while(cnt!=n) {
        i++;
        if(i>n){
            i=1;
        }
        if (circle[i-1]==0){
            m++;
            if(m==k){
                circle[i-1]=1;
                cnt++;
                if (cnt<n){
                    cout<<i<<"->";
                }
                else {
                    cout<<i;
                }
                m=0;
            }
        }
    }
}