#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>


// 对差分数组还不是很熟悉，参考362week那道题
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        // vector<int> ans;
        // for(int person: people){
        //     int num=0;
        //     for(auto& flower: flowers){
        //         if(person>=flower[0] && person<=flower[1]){
        //             num++;
        //         }
        //     }
        //     ans.push_back(num);
        // }
        // return ans;

        //差分数组
        map<int,int> cnt;
        for(auto& flower:flowers){
            // 第一个数+1，对最后一个后面的数-1
            cnt[flower[0]]++;
            cnt[flower[1]+1]--; 
        }
        int m=people.size();
        vector<int> indices(m);
        // iota算法用于填充一个区间，以递增的方式给每个元素赋予一个
        iota(indices.begin(),indices.end(),0);
        // 按到达时间对坐标进行排序
        sort(indices.begin(),indices.end(),[&](int a, int b){
            return people[a]<people[b];
        });

        vector<int> ans(m);
        int curr=0;
        auto it=cnt.begin();
        for(int x: indices){
            while(it!=cnt.end() && it->first<=people[x]){
                //前缀和，就是该坐标点的花的数量
                curr+=it->second;
                it++;
            }
            ans[x]=curr;
        }
        return ans;
        
    }
};