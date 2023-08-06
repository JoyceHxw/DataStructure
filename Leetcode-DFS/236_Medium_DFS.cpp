#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //     // 遍历两次，记录路径
    //     vector<TreeNode*> path1;
    //     vector<TreeNode*> path2;
    //     vector<TreeNode*> ans1;
    //     vector<TreeNode*> ans2;
    //     recursion(root,p,path1,ans1);
    //     recursion(root,q,path2,ans2);
    //     TreeNode* last=root;
    //     for(int i=0; i<ans1.size(); i++){
    //         cout<<ans1[i]->val<<" ";
    //     }
    //     cout<<endl;
    //     for(int i=0; i<ans2.size(); i++){
    //         cout<<ans2[i]->val<<" ";
    //     }
    //     for(int i=0; i<min(ans1.size(),ans2.size()); i++){
    //         if(ans1[i]!=ans2[i]){
    //             break;
    //         }
    //         last=ans1[i];
    //     }
    //     return last;

    // }
    // void recursion(TreeNode* node, TreeNode* p, vector<TreeNode*>& path,vector<TreeNode*>& ans){
    //     if(node==nullptr){
    //         return;
    //     }
    //     path.push_back(node);
    //     if(node==p){
    //         ans=path;
    //         return;
    //     }
    //     recursion(node->left,p,path,ans);
    //     recursion(node->right,p,path,ans);
    //     path.pop_back();
    // }

    // 难点在于找到递归条件
    // 是否满足q,p同时在两个子树中，或根节点为p或q，只有一个子树有
    TreeNode* ans;
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return false;
        bool lson = dfs(root->left, p, q);
        bool rson = dfs(root->right, p, q);
        if ((lson && rson) || ((root->val == p->val || root->val == q->val) && (lson || rson))) {
            ans = root;
        } 
        return lson || rson || (root->val == p->val || root->val == q->val);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }
};