// 已知某一只股票的每一日收盘价格，假设只可以进行一次先买后卖，求每股最大收益
#include <iostream>
using namespace std;

int main(){
    int num;
    cin>>num;
    int prices[num];
    for(int i=0; i<num; i++){
        int price;
        cin>>price;
        prices[i]=price;
    }
    int s=0;
    int min_s=9999999;
    int max_s=0;
    for(int i=0;i<num;i++){
        s=prices[i]-min_s;
        max_s=max(max_s,s);
        min_s=min(min_s,prices[i]);
    }
    cout<<max_s;
    // return max_s;
}