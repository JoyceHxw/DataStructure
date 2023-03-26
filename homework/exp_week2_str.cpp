#include <iostream>
using namespace std;

int main(){
    string s;
    cin>>s;
    int start=0;
    int end=0;
    int m=0;
    string str="";
    for (int i=0; i<s.length(); i++){
        bool isFlag=false;
        int k=0;
        for (int j=0; j<str.length(); j++){
            if (str[j]==s[i]){
                isFlag=true;
                k=j;
                break;
            }
        }
        if (isFlag==false){
            end=i+1;
        }
        else{
            start+=k+1;
            end=i+1;
        }
        str=s.substr(start,end-start);
        m=max(m,end-start);
        cout<<"start="<<start<<endl;
        cout<<"end="<<end<<endl;
        cout<<str<<endl;
    }
    cout<<m;
}