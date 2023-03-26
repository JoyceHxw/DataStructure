// 已知顺序存储的线性表，依次存放两个分别大小有序线性表，（a1...an)(b1....bm)，
// 即ai>=ai-1,bj>=bj-1(1<i<=n,1<j<=m)尝试设计算法合并成为一个非降序线性表。
// 要求辅助存储空间复杂度为O(1)。试分析算法的时间复杂度。
// 输入：有序线性表长度n,m,n+m个分别有序的整数。
// 输出：非降序序列。
#include <iostream>
using namespace std;

int main() {
    int n;
    int m;
    cin>>n;
    cin>>m;
    int arr[n+m];
    for(int i=0; i<n+m; i++) {
        int number;
        cin>>number;
        arr[i]=number;
    }
    for (int i=0;i<n+m-1; i++) {
        for (int j=0; j<n+m-1-i; j++) {
            if(arr[j]>arr[j+1]) {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    for (int i=0;i<n+m;i++) {
        if(i!=n+m-1) {
            cout<<arr[i]<<" ";
        }
        else {
            cout<<arr[i];
        }
    }
}