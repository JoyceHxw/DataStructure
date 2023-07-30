// 给你三个字符串 a ，b 和 c ， 你的任务是找到长度 最短 的字符串，且这三个字符串都是它的 子字符串 。
// 如果有多个这样的字符串，请你返回 字典序最小 的一个。
// 请你返回满足题目要求的字符串。
// 注意：
// 两个长度相同的字符串 a 和 b ，如果在第一个不相同的字符处，a 的字母在字母表中比 b 的字母 靠前 ，那么字符串 a 比字符串 b 字典序小 。
// 子字符串 是一个字符串中一段连续的字符序列。
#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    // 思路就是模拟枚举，难点在于理清枚举的步骤和找最长的相同前后缀
    // 开始想到了找最大前后缀，但是没想到完整的实现方法
    string minimumString(string a, string b, string c) {
        string s1 = join(join(a, b), c);
        string s2 = join(join(a, c), b);
        string s3 = join(join(b, a), c);
        string s4 = join(join(b, c), a);
        string s5 = join(join(c, a), b);
        string s6 = join(join(c, b), a);
        vector<string> v;
        v.push_back(s2);
        v.push_back(s3);
        v.push_back(s4);
        v.push_back(s5);
        v.push_back(s6);
        string ans=s1;
        for(int i=0; i<v.size(); i++){
            if(ans.length()>v[i].length()){
                ans=v[i];
            }
            else if(ans.length()==v[i].length() && ans>v[i]){
                ans=v[i];
            }
        }
        return ans;
    }
    // 将两个字符串合并
    string join(string a, string b){
        // 包含就不连接
        if (a.find(b)!=-1){
            return a;
        }
        int len=min(a.length(), b.length());
        string ans;
        while(len>0){
            if(isSame(a,b,len)){
                ans=a+b.substr(len,b.length()-len);
                return ans;
            }
            else{
                len--;
            }
        }
        ans=a+b;
        return ans;
    }
    // 验证长度为len的a的后缀和b的前缀是否相同
    // 设定长度为len比较巧妙
    bool isSame(string& a, string& b, int len){
        int i=a.length()-len;
        int j=0;
        while(i<a.length() && j>=0){
            if(a[i]==b[j]){
                i++;
                j++;
            }
            else{
                return false;
            }
        }
        return true;
    }
};