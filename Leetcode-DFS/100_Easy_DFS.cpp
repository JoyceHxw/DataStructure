#include <iostream>
using namespace std;
#include <vector>

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // 我的解答：栈和前序遍历
        // 按相同顺序遍历两棵树
        // stack<TreeNode*>stk1;
        // stack<TreeNode*>stk2;
        // while((p!=nullptr && q!=nullptr) || (!stk1.empty() && !stk2.empty()) ){
        //     while(p!=nullptr && q!=nullptr){
        //         stk1.push(p);
        //         stk2.push(q);
        //         p=p->left;
        //         q=q->left;
        //     }
        //     if(p!=q){
        //         return false;
        //     }
        //     p=stk1.top();
        //     q=stk2.top();
        //     cout<<p->val<<endl;
        //     cout<<q->val<<endl;
        //     stk1.pop();
        //     stk2.pop();
        //     if(p->val!=q->val){
        //         return false;
        //     }
        //     p=p->right;
        //     q=q->right;  
        // }
        // if(p==nullptr && q==nullptr){
        //     return true;
        // }
        // else{
        //     return false;
        // }

        // 答案：递归
        if (p == nullptr && q == nullptr) {
            return true;
        } else if (p == nullptr || q == nullptr) {
            return false;
        } else if (p->val != q->val) {
            return false;
        } else {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }

    }
};