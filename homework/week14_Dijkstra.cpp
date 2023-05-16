#include <iostream>
using namespace std;
#include <vector>
#define INF 999
#include <queue>
#include <stack>

void showPath(vector<int>& d,vector<int>& p, int start, int n){
    vector<int>flag(n+1,0); //是否已输出
    stack<int>path;
    int cnt=0;
    while(true){
        int min_d=INF;
        int e=start; //终点
        for(int i=1; i<n+1; i++){
            if(!flag[i] && i!=start && d[i]<min_d){
                min_d=d[i];
                e=i;
            }
        }
        if(min_d==INF){ // 没有最短路径了
            break;
        }
        flag[e]=1;
        path.push(e);
        while(p[e]!=start){
            path.push(p[e]);
            e=p[e];
        }
        cnt++;
        cout<<"No."<<cnt<<" : "<<start;
        while(!path.empty()){
            cout<<" -> "<<path.top();
            path.pop();
        }
        cout<<" , d = "<<min_d<<endl;
    }
    int cnt1=0;
    for(int i=1; i<n+1; i++){
        if(i!=start && flag[i]==0){
            cnt1++;
        }
    }
    if(cnt1>0){
        cnt++;
        cout<<"No."<<cnt<<" : No Path to";
        for(int i=1; i<n+1; i++){
            if(i!=start && flag[i]==0){
                cout<<" "<<i;
            }
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    // 初始化邻接矩阵
    vector<vector<int>> matrix(n+1,vector<int>(n+1));
    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            if(i==j){
                matrix[i][j]=0;
            }
            else{
                matrix[i][j]=INF;
            }
        }
    }
    for(int i=0; i<m; i++){
        int s,e,w;
        cin>>s>>e>>w;
        matrix[s][e]=w;
    }
    // 起点
    int start;
    cin>>start;
    // 距离数组，前驱点数组
    vector<int> d(n+1,INF);
    vector<int> p(n+1,0);
    // 是否已得到最短距离
    vector<int> flag(n+1,0);
    // 初始化
    for(int i=1; i<n+1; i++){
        p[i]=i;
    }
    flag[start]=1;
    d[start]=0;
    int k=start;
    bool isflag=true;
    while(isflag){ // 最短路径是否更新
        int min_d=INF;
        for(int i=1; i<n+1; i++){
            if(!flag[i] && d[i]>(d[k]+matrix[k][i])){
                d[i]=d[k]+matrix[k][i];
                p[i]=k;
            }
        }
        // 更新目前最短路径，以及下一个起点
        isflag=false;
        for(int i=1; i<n+1; i++){
            if(!flag[i] && min_d>d[i]){
                min_d=d[i];
                k=i;
                isflag=true;
            }
        }
        flag[k]=1;
    }
    // for(int i=1; i<n+1; i++){
    //     cout<<d[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=1; i<n+1; i++){
    //     cout<<p[i]<<" ";
    // }
    showPath(d,p,start,n);
}