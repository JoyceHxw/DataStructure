// 合并两个水晶碎块需要的能量是两个水晶碎块的能量和。假设只可以两两合并，请求出一堆水晶碎块合并成一整块水晶需要的最小能量。

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>


long long haffman(vector<long>& v){
    // 贪心算法
    long long sum=0;
    while(v.size()>1){
        sort(v.begin(),v.end());
        long a=v[0]+v[1];
        sum+=a;
        vector<long> v1(v.begin()+2,v.end());
        v=v1;
        v.push_back(a);
        for(int i=0; i<v.size(); i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    return sum;
    
}

int main(){
    int n;
    cin>>n;
    vector<long> v;
    v.resize(n);
    for(int i=0; i<n; i++){
        long a;
        cin>>a;
        v[i]=a;
    }
    cout<<haffman(v);

}