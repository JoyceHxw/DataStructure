#include <iostream>
using namespace std;
#include <unordered_map>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//打家劫舍3
//没有找到正确的状态转移方程

class Solution {
public:
    int rob(TreeNode* root) {
        //层序遍历，以每一层来考虑，从父节点到子节点的思路，看左右子节点之和是否大于根节点
        //但这种方法没有考虑到整个子树的情况，是短视的

        // int last1=root->val;
        // int last2=0;
        // queue<TreeNode*> q;
        // q.push(root);
        // while(!q.empty()){
        //     int size=q.size();
        //     int temp=last1;
        //     int a=0;
        //     for(int i=0; i<size; i++){
        //         TreeNode* node=q.front();
        //         cout<<node->val<<endl;
        //         q.pop();
        //         int num=node->val;
        //         int l=0;
        //         int r=0;
        //         if(node->left!=nullptr){
        //             q.push(node->left);
        //             l=node->left->val;
        //         }
        //         if(node->right!=nullptr){
        //             q.push(node->right);
        //             r=node->right->val;
        //         }
        //         if(l+r>num){
        //             last1=last1+l+r-num;
        //         }
        //         a+=l+r;
        //     }
        //     last1=max(last1,last2+a);
        //     last2=temp;
        //     // cout<<"last1"<<last1<<endl;
        //     // cout<<"last2"<<last2<<endl;
        // }
        // return max(last1,last2);

        unordered_map<TreeNode*,int> f;
        unordered_map<TreeNode*,int> g;
        dfs(root,f,g);
        return max(f[root],g[root]);
    }

    //深度遍历，从子节点到父节点的思路
    //f，g分别表示是否选择该节点的子树的最大和
    void dfs(TreeNode* node, unordered_map<TreeNode*,int>& f,unordered_map<TreeNode*,int>& g){
        if(!node){
            return;
        }
        dfs(node->left,f,g);
        dfs(node->right,f,g);
        f[node]=node->val+g[node->left]+g[node->right];
        g[node]=max(f[node->left],g[node->left])+max(f[node->right],g[node->right]);

    }
};