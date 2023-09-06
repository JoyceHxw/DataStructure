#include <iostream>
using namespace std;
#include <queue>
#include <unordered_set>


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// 我的思路比较直观：先找到最深的叶子节点，再判断他们的公共父节点，需要多次遍历
// 答案：根据左右子树的高度即可判断最深叶子节点位于左子树还是右子树，只遍历一次即可，比较巧妙
class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        // //求数的高度
        // int height=getHeight(root);
        // //找最深的叶节点，层序遍历
        // unordered_set<TreeNode*> s;
        // queue<TreeNode*> q;
        // q.push(root);
        // int high=0;
        // while(!q.empty()){
        //     int size=q.size();
        //     for(int i=0; i<size; i++){
        //         TreeNode* node=q.front();
        //         q.pop();
        //         if(high==height-1){
        //             s.insert(node);
        //             cout<<node->val<<endl;
        //         }
        //         if(node->left!=nullptr){
        //             q.push(node->left);
        //         }
        //         if(node->right!=nullptr){
        //             q.push(node->right);
        //         }
        //     }
        //     high++;
        // }
        // if(s.size()==1){
        //     return *s.begin();
        // }
        // //找父节点，左右子树是否都有最深叶节点
        // while(true){
        //     if(hasNode(root->left,s) && !hasNode(root->right,s)){
        //         root=root->left;
        //     }
        //     else if(!hasNode(root->left,s) && hasNode(root->right,s)){
        //         root=root->right;
        //     }
        //     else if(hasNode(root->left,s) && hasNode(root->right,s)){
        //         return root;
        //     }
        //     else{
        //         return nullptr;
        //     }
        // }
        // return nullptr;

        return f(root).first;
    }

    // int getHeight(TreeNode* node){
    //     if(node==nullptr){
    //         return 0;
    //     }
    //     return max(getHeight(node->left),getHeight(node->right))+1;
    // }

    // bool hasNode(TreeNode* node, unordered_set<TreeNode*>& s){
    //     if(node==nullptr){
    //         return false;
    //     }
    //     return s.find(node)!=s.end() || hasNode(node->left,s) || hasNode(node->right,s);
    // }

    pair<TreeNode*, int> f(TreeNode* root) {
        if (!root) {
            return {root, 0};
        }

        auto left = f(root->left);
        auto right = f(root->right);

        if (left.second > right.second) {
            return {left.first, left.second + 1};
        }
        if (left.second < right.second) {
            return {right.first, right.second + 1};
        }
        return {root, left.second + 1};

    }

};