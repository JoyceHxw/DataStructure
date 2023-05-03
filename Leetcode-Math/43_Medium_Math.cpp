#include <iostream>
using namespace std;

class Solution {
public:
    // 会溢出
    // string multiply(string num1, string num2) {
    //     int a=transfer(num1);
    //     int b=transfer(num2);
    //     cout<<a<<endl;
    //     cout<<b<<endl;
    //     long long c=a*b;
    //     cout<<c<<endl;
    //     return to_string(c);
    // }

    // int transfer(string num){
    //     int n=num.length();
    //     int ans=0;
    //     int cnt=n;
    //     for(int i=0; i<n; i++){
    //         ans+=(num[i]-48)*pow(10,cnt-1);
    //         cnt--;
    //     }
    //     return ans;
    // }

    // 竖式乘法
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0"){
            return "0";
        }
        int m=num1.length();
        int n=num2.length();
        string ans;
        int cnt=0;
        for(int i=n-1; i>=0; i--){
            // 先计算每一位的乘积
            string temp="";
            int next=0;
            for(int j=m-1; j>=0; j--){
                int a=(num2[i]-48)*(num1[j]-48)+next;
                char last=a%10+48;
                temp=last+temp;
                next=a/10;
            }
            if(next>0){
                temp=char(next+48)+temp;
            }
            // 计算乘积之和
            if(cnt==0){
                ans=temp;
            }
            else{
                // 添零
                for(int l=0; l<cnt; l++){
                    temp+='0';
                }
                int next1=0;
                string temp1="";
                int cnt1=1;
                for(int k=temp.length()-1; k>=0; k--){
                    int b;
                    if(cnt1<=ans.length()){
                        b=(ans[ans.length()-cnt1]-48+temp[k]-48)+next1;
                    }
                    else{
                        b=(temp[k]-48)+next1;
                    }
                    char last1=b%10+48;
                    next1=b/10;
                    temp1=last1+temp1;
                    cnt1++;
                }
                if(next1==0){
                    ans=temp1;
                }
                else{
                    ans='1'+temp1;
                }
                // cout<<ans<<endl;
            }
            cnt++;
        }
        return ans;
    }
};

int main(){
    Solution s;
    cout<<s.multiply("237","284");
}