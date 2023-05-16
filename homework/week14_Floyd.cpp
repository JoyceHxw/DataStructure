#include <iostream>
using namespace std;
#include <vector>
#define INF 999

int main(){
    int n,m;
    cin>>n>>m;
    // 初始化邻接矩阵
    // 顶点编号从0开始
    vector<vector<int>> matrix(n,vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
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
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]>matrix[i][k]+matrix[k][j]){
                    matrix[i][j]=matrix[i][k]+matrix[k][j];
                }
            }
        }
    }
    // 输出矩阵
    for(int i=0; i<n; i++){
        if(matrix[i][0]==INF){
            cout<<-1;
        }
        else{
            cout<<matrix[i][0];
        }
        for(int j=1; j<n; j++){
            if(matrix[i][j]==INF){
                cout<<" "<<-1;
            }
            else{
                cout<<" "<<matrix[i][j];
            }
        }
        if(i<n-1){
            cout<<endl;
        }
    }
}