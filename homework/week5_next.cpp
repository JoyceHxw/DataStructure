// 根据KMP算法的next数组值，推断模式字符串。
// 假设模式字符串中只存在0，1两种字符。给出首字符和next数组。请输出模式字符串。如果next数组不合法则输出ERROR

#include <iostream>
using namespace std;

void nextDeduce(bool first, bool last, int len, int *next){
    int i=1;
    int j=0;
    bool *str=new bool[len];
    str[0]=first;
    str[len-1]=last;
    while(i<len-1){
        if(next[i+1]==next[i]+1){
            str[i]=str[j];
            i++;
            j++;
        }
        else if(next[i+1]==0){
            j=0;
            str[i]=(!str[j]);
            i++;
        }
        else{
            int temp=j;
            j=next[i+1]-1;
            // 回溯超过已有字符长度
            if(j>=i){
                cout<<"ERROR"<<endl;
                return;
            }
            str[i]=str[j];
            // 非最大相同后缀长度
            if(str[i]==str[temp]){
                cout<<"ERROR"<<endl;
                return;
            }
            i++;
            j++;
        }

        cout<<"i="<<i<<endl;
        cout<<"j="<<j<<endl;
    }
    for (int k=0; k<len; k++){
        cout<<str[k];
    }
}

int main(){
    bool first;
    bool last;
    int len;
    cin>>first>>last>>len;
    int *next= new int[len];
    for (int i=0; i<len; i++){
        cin>>next[i];
    }
    nextDeduce(first,last,len,next);
}