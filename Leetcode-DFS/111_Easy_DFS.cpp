#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        // int min_depth=MAX
        if(root==nullptr){
            return 0;
        }
        // 注意考虑左右子树不存在的情况
        if(root->left==nullptr && root->right!=nullptr){
            return minDepth(root->right)+1;
        }
        if(root->right==nullptr && root->left!=nullptr){
            return minDepth(root->left)+1;
        }
        return min(minDepth(root->left),minDepth(root->right))+1;
    }
};