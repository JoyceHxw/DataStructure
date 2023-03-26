// 给定一个n*m的矩阵，请以顺、逆时针交替旋转的方式打印出每个元素。
#include <iostream>
using namespace std;

int main(){
    int n;
    int m;
    cin>>n>>m;

    int* matrix= new int[n*m];
    for (int i=0; i<n*m; i++){
        int a;
        cin>>a;
        matrix[i]=a;
    }
    
    int i=0;
    int j=0;
    int cnt=0;
    int k=0;
    while(cnt<n*m){
        // 顺时针
        while(j<m-k && j>=k && cnt<n*m){
            int num=matrix[i*m+j];
            if (cnt==n*m-1){
                cout<<num;
            }
            else{
                cout<<num<<" ";
            }
            cnt+=1;
            j++;
        }
        j--;
        i++;
        while(i<n-k && i>=k && cnt<n*m){
            int num=matrix[i*m+j];
            if (cnt==n*m-1){
                cout<<num;
            }
            else{
                cout<<num<<" ";
            }
            cnt+=1;
            i++;
        }
        i--;
        j--;
        while(j<m-k && j>=k && cnt<n*m){
            int num=matrix[i*m+j];
            if (cnt==n*m-1){
                cout<<num;
            }
            else{
                cout<<num<<" ";
            }
            cnt+=1;
            j--;
        }
        j++;
        i--;
        while(i<n-k && i>=k+1 && cnt<n*m){
            int num=matrix[i*m+j];
            if (cnt==n*m-1){
                cout<<num;
            }
            else{
                cout<<num<<" ";
            }
            cnt+=1;
            i--;
        }
        i++;
        j++;
        
        // 逆时针
        k++;
        while(i<n-k && i>=k && cnt<n*m){
            int num=matrix[i*m+j];
            if (cnt==n*m-1){
                cout<<num;
            }
            else{
                cout<<num<<" ";
            }
            cnt+=1;
            i++;
        }
        i--;
        j++;
        while(j<m-k && j>=k && cnt<n*m){
            int num=matrix[i*m+j];
            if (cnt==n*m-1){
                cout<<num;
            }
            else{
                cout<<num<<" ";
            }
            cnt+=1;
            j++;
        }
        j--;
        i--;
        while(i<n-k && i>=k && cnt<n*m){
            int num=matrix[i*m+j];
            if (cnt==n*m-1){
                cout<<num;
            }
            else{
                cout<<num<<" ";
            }
            cnt+=1;
            i--;
        }
        i++;
        j--;
        while(j<m-k && j>=k+1 && cnt<n*m){
            int num=matrix[i*m+j];
            if (cnt==n*m-1){
                cout<<num;
            }
            else{
                cout<<num<<" ";
            }
            cnt+=1;
            j--;
        }
        j++;
        i++;
    }

}