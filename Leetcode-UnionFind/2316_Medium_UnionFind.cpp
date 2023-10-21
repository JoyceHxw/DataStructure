#include <iostream>
using namespace std;
#include <vector>
#include <numeric>


//思路上想到了并查集，能够实现
//但是这道题要注意，不是设置rank值来进行优化合并，而是设置连通分量中点的个数，这样方便后续计算不连通的点的数量

class UnionFind {
private:
    vector<int> parents;
    //连通分量点的个数
    vector<int> sizes;
public:
    UnionFind(int n) : parents(n), sizes(n, 1) {
        //每次递增1
        iota(parents.begin(), parents.end(), 0);
    }
    //路径压缩，把路径中的点的父节点都设为根节点
    int Find(int x) {
        if (parents[x] == x) {
            return x;
        }
        return parents[x] = Find(parents[x]);
    }
    void Union(int x, int y) {
        int rx = Find(x), ry = Find(y);
        if (rx != ry) {
            //将点加在少的一边，降低高度，提高查询速度
            if (sizes[rx] > sizes[ry]) {
                parents[ry] = rx;
                sizes[rx] += sizes[ry];
            } else {
                parents[rx] = ry;
                sizes[ry] += sizes[rx];
            }
        }
    }
    int GetSize(int x) {
        return sizes[x];
    }
};

class Solution {
public:
    long long countPairs(int n, vector<vector<int>> &edges) {
        UnionFind uf(n);
        for (const auto &edge : edges) {
            uf.Union(edge[0], edge[1]);
        }
        long long res = 0;
        for (int i = 0; i < n; i++) {
            res += n - uf.GetSize(uf.Find(i));
        }
        return res / 2;
    }
};
