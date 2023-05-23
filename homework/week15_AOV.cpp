// 给出一个工程中N个阶段的时间消耗和依赖关系，试求出工程的最短时间消耗。

// 输入N 0<N<=20。
// 随后输入N行数据，每行包含从1起始的阶段编号S、时间消耗T、以及用分号隔开的所依赖的不同阶段编号【如果不依赖其他阶段则此项为空】

#include <iostream>
using namespace std;
#include <vector>
#include <stack>

int main(){
    int n;
    cin>>n;
    // 邻接矩阵
    vector<vector<int>>matrix(n+1,vector<int>(n+1));
    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            matrix[i][j]=0;
        }
    }
    cin.ignore();
    // 时间消耗
    vector<int>timewaste(n+1,0);
    // 入度
    vector<int>indegree(n+1,0);
    // 初始化
    for(int i=0; i<n; i++){
        string line;
        getline(cin,line);
        // cout<<line<<endl;
        int temp=0;
        int e=0;
        int t=0;
        int pre=0;
        for(int j=0; j<line.length(); j++){
            if(line[j]>=48 && line[j]<=57){
                if(temp==0){
                    temp=line[j]-48;
                }
                else{
                    temp=10*temp+line[j]-48;
                }
            }
            else if(line[j]==' ' || line[j]==';'){
                if(e==0){
                    e=temp;
                    temp=0;
                }
                else if(t==0){
                    t=temp;
                    timewaste[e]=t;
                    temp=0;
                }
                else{
                    pre=temp;
                    matrix[pre][e]=1;
                    temp=0;
                    indegree[e]++;
                }
            }
            if(j==line.length()-1 && temp!=0){
                t=temp;
                timewaste[e]=t;
                temp=0;
            }
        }
    }
    stack<int>stk;
    stack<int>sequence;
    vector<int>ee(n+1,0);
    for(int i=1; i<n+1; i++){
        if(indegree[i]==0){
            stk.push(i);
        }
    }
    int cnt=0;
    while(!stk.empty()){
        int e=stk.top();
        sequence.push(e);
        stk.pop();
        cnt++;
        // 遍历边，减少入度
        for(int j=1; j<n+1; j++){
            if(matrix[e][j]==1){
                ee[j]=max(ee[j],ee[e]+timewaste[e]);
                indegree[j]--;
                if(indegree[j]==0){
                    stk.push(j);
                }
            }
        }
    }
    if(cnt<n){
        cout<<"error";
        return 0;
    }
    vector<int>el(n+1,ee[n]);
    while(!sequence.empty()){
        int e=sequence.top();
        sequence.pop();
        for(int j=1;j<n+1;j++){
            if(matrix[e][j]==1){
                el[e]=min(el[e],el[j]-timewaste[e]);
            }
        }
    }
    int ans=0;
    for(int i=1; i<n+1; i++){
        if(ee[i]==el[i]){
            ans+=timewaste[i];
        }
    }
    cout<<ans;
    
}