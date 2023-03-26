// 布尔矩阵是指由0和1组成的矩阵，一个布尔矩阵有奇偶均势特性，当且仅当矩阵的每行、每列得总和为偶数，即包含偶数个1，该矩阵就具有奇偶均势特性。

#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int* matrix=new int[n*n];
    for (int i=0; i<n*n; i++){
        int a;
        cin>>a;
        matrix[i]=a;
    }
    int* s_row=new int[n];
    int* s_col=new int[n];
    for (int i=0; i<n; i++){
        int s_r=0;
        int s_c=0;
        for (int j=0; j<n; j++){
            s_r+=matrix[i*n+j];  // 每一行求和
            s_c+=matrix[j*n+i];  // 每一列求和
        }
        s_row[i]=s_r;
        s_col[i]=s_c;
    }
    // 判断是不是都是偶数
    bool isBool=true;
    int cnt_r=0;
    int cnt_c=0;
    int pos_r;
    int pos_c;
    for (int i=0; i<n; i++){
        if(s_row[i]%2!=0){
            isBool=false;
            cnt_r+=1;  //统计奇数个数
            pos_r=i;
        }
        if(s_col[i]%2!=0){
            isBool=false;
            cnt_c+=1;  //统计奇数个数
            pos_c=i;
        }   
    }
    if(isBool==true){
        cout<<"OK";
    }
    else if(cnt_r<=1 && cnt_c<=1){
        int r=pos_r+1;
        int c=pos_c+1;
        cout<<"Change bit ("<<r<<","<<c<<")";
    }
    else{
        cout<<"Corrupt"<<endl;
    }
    
}