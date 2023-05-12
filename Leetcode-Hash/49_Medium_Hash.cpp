#include <iostream>
using namespace std;
#include <unordered_map>
#include <vector>
#include <algorithm>

// 注意排序判断是否由相同字母构成
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>m;
        for(int i=0; i<strs.size(); i++){
            string s=strs[i];
            sort(s.begin(),s.end());
            m[s].push_back(strs[i]);
        }
        for(unordered_map<string,vector<string>>:: iterator it=m.begin(); it!=m.end(); it++){
            ans.push_back(it->second);
        }
        return ans;
    }
};