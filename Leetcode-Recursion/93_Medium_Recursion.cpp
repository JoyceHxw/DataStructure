#include <iostream>
using namespace std;
#include <vector>


// 自己没有写出来，剪枝条件较复杂，还需要考虑字符串加点
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        vector<int> numbers(4);
        recursion(ans,numbers,s,0,0);
        return ans;
    }
    void recursion(vector<string>& ans, vector<int>& numbers, string& s, int k, int cnt){
        // 先确定点的位置（记录整数值），如果全部满足条件最后再加点，并加进结果集
        if(cnt==4){
            if(k==s.length()){
                string address="";
                for(int i=0; i<4; i++){
                    address+=to_string(numbers[i]);
                    if(i!=3){
                        address+=".";
                    }
                }
                ans.push_back(address);
            }
            return;
        }
        // 已到达最后
        if(k==s.length()){
            return;
        }
        // 单独0（前面的地址整数已确定）
        if(s[k]=='0'){
            numbers[cnt]=0;
            recursion(ans,numbers,s,k+1,cnt+1);
        }
        // 递归打四个点
        int temp=0;
        for(int i=k; i<s.length(); i++){
            temp=10*temp+s[i]-48;
            // 检查是否满足条件
            if(temp>0 && temp<=255){
                // 打点，记录地址数字
                numbers[cnt]=temp;  // 注意不能用pushback，因为当不符合条件时需要更改该位置的值
                recursion(ans,numbers,s,i+1,cnt+1);
            }
            else{
                // 不满足条件，跳出循环，回溯上一个点
                break;
            }
        }
    }
};