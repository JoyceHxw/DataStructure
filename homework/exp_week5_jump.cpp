// 给定一个非负整数n，及长度为n的数组nums，你最初位于数组的第一个位置。
// 数组中的每个元素代表你在该位置可以跳跃的最大长度。
// 判断你是否能够到达最后一个下标。

#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int *steps= new int[n];
    for (int i=0; i<n; i++){
        cin>>steps[i];
    }
    // [3,2,1,0,4]
    // 最后一个无关
    int m=0;
    for(int i=0; i<n-1; i++){
        if(i<=m){
            m=max(m,i+steps[i]);
        }
    }
    // cout<<"m="<<m<<endl;
    if(m>=n-1){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
}