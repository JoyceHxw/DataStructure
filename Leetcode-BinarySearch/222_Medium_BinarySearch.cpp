#include <iostream>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//根据完全二叉树的特点想到遍历右节点和遍历左节点得到高度来验证是否是满二叉树，从而直接计算得到节点数，然后递归
class Solution {
public:
    int countNodes(TreeNode* root) {
        // 判断左右子树是不是满二叉树，即左右高度相同
        if(root==nullptr){
            return 0;
        }
        int l_depth=0;
        int r_depth=0;
        TreeNode* node=root;
        while (node->left){
            l_depth++;
            node=node->left;
        }
        node=root;
        while(node->right){
            r_depth++;
            node=node->right;
        }
        if(l_depth==r_depth){
            return pow(2,l_depth+1)-1;
        }
        else{
            return countNodes(root->left)+countNodes(root->right)+1;
        }
    }
};