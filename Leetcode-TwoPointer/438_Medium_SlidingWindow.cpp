// 给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
// 异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。

#include <iostream>
using namespace std;
#include <unordered_set>
#include <vector>

//想了两种方法，都超时了
//对滑动窗口问题还不熟练
class Solution {
public:
    unordered_set<string> set;
    vector<int> findAnagrams(string s, string p) {
        //长度固定，遍历所有可能起始点
        //先找到所有的异位组合
        // string temp="";
        // vector<int> vis(p.size());
        // dfs(p,temp,vis);
        // vector<int> ans;
        // for(int i=0; i<s.size()-p.size()+1; i++){
        //     string t="";
        //     for(int k=0; k<p.size(); k++){
        //         t+=s[i+k];
        //     }
        //     if(set.find(t)!=set.end()){
        //         ans.push_back(i);
        //     }
        // }
        // return ans;

        //用计数的方式统计，还是超时
        // vector<int> ans;
        // unordered_map<char,int> map;
        // unordered_map<char,int> map2;
        // int n=s.size();
        // int m=p.size();
        // for(int i=0; i<m; i++){
        //     map[p[i]]++;
        //     map2[p[i]]++;
        // }
        // for(int i=0; i<n-m+1; i++){
        //     int k=0;
        //     for(; k<m; k++){
        //         if(map[s[i+k]]>0){
        //             map[s[i+k]]--;
        //         }
        //         else{
        //             break;
        //         }
        //     }
        //     if(k==m){
        //         ans.push_back(i);
        //     }
        //     //还原
        //     map=map2;

        // }
        // return ans;

        //滑动窗口
        //检查26个字母的个数是不是一样
        int n=s.size(), m=p.size();
        vector<int> ans;
        if(n<m){
            return ans;
        }
        vector<int> s_count(26,0);
        vector<int> p_count(26,0);
        for(int i=0; i<m; i++){
            s_count[s[i]-'a']++;
            p_count[p[i]-'a']++;
        }
        if(s_count==p_count){
            ans.push_back(0);
        }
        //长度位m的滑动窗口，减一个字母，加一个字母
        for(int i=0; i<n-m; i++){
            s_count[s[i]-'a']--;
            s_count[s[i+m]-'a']++;
            if(s_count==p_count){
                ans.push_back(i+1);
            }
        }
        return ans;
    }

    //超时
    void dfs(string p, string ans, vector<int> vis){
        if(ans.size()==p.size()){
            set.insert(ans);
        }
        for(int i=0; i<p.size(); i++){
            if(vis[i]==0){
                vis[i]=1;
                dfs(p,ans+p[i],vis);
                vis[i]=0;
            }
        }
    }
};