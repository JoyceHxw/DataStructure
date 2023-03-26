// 给定一个常数项为0的二元一次多项式，求该多项式的幂。
// 设未知数为x,y，输入为x和y的整数系数a,b以及整数幂n，输出形如以下样式
// 求幂运算的结果，按照x的幂降序排列

#include <iostream>
#include <string>
using namespace std;

void output(long long * q, int n){
    for (int i=0; i<=n; i++){
        long long a=q[i+1];
        // 符号
        if (a==0){
            continue;
        }
        if (a==1){}
        else if(a==-1){
            cout<<"-";
        }
        else{
            cout<<a;
        }
        // xy
        if(i==n){}
        else if(i==n-1){
            cout<<"x";
        }
        else {
            cout<<"x^"<<n-i;
        }
        if(i==0){}
        else if(i==1){
            cout<<"y";
        }
        else{
            cout<<"y^"<<i;
        }
        if (i!=n and q[i+2]>0){
            cout<<"+";
        }
    }
}

int main(){
    // 系数
    int a;
    int b;
    // 次数
    int n;
    cin>>a>>b>>n;

    long long * queue= new long long[n+3];
    // 初始化，一次幂
    queue[0]=0;
    queue[1]=a;
    queue[2]=b;
    queue[3]=0;
    for (int i=2; i<=n; i++){
        queue[0]=0;
        long long last=queue[0];
        long long temp=queue[1];
        for(int j=1; j<i+3-1; j++){
            // 先乘再变
            queue[j]= last*b+ temp*a;
            last=temp;
            temp=queue[j+1];
        }
        queue[i+3-1]=0;
    }
    // for (int i=0; i<n+3; i++){
    //     cout<<queue[i]<<endl;
    // }
    output(queue,n);
}