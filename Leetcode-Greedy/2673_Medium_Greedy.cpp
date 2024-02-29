// 给你一个整数 n 表示一棵 满二叉树 里面节点的数目，节点编号从 1 到 n 。根节点编号为 1 ，树中每个非叶子节点 i 都有两个孩子，分别是左孩子 2 * i 和右孩子 2 * i + 1 。
// 树中每个节点都有一个值，用下标从 0 开始、长度为 n 的整数数组 cost 表示，其中 cost[i] 是第 i + 1 个节点的值。每次操作，你可以将树中 任意 节点的值 增加 1 。你可以执行操作 任意 次。
// 你的目标是让根到每一个 叶子结点 的路径值相等。请你返回 最少 需要执行增加操作多少次。

#include <iostream>
using namespace std;
#include <vector>

//自底向上，考虑互为兄弟节点的一对叶节点，其他节点不是该对叶节点的父节点就是无关的节点（解题关键，不容易想到）
//使该对叶节点的值相等，然后加在父节点上，再把父节点当作叶节点继续向上计算
class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        //倒序遍历数组
        int ans=0;
        for(int i=n-1; i>=1; i-=2){
            //使兄弟叶节点值相等
            ans+=abs(cost[i]-cost[i-1]);
            //加到父节点上
            cost[i/2-1]+=max(cost[i],cost[i-1]);
        }
        return ans;
    }
};

