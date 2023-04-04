// 给出一棵二叉树的先序遍历和中序遍历序列，计算该二叉树的高度。其中，二叉树的先序和中序遍历序列为不包含重复英文字母（区别大小写）的字符串。

#include <iostream>
using namespace std;
#include <stack>

class TreeNode
{
public:
    TreeNode(char v){
        val=v;
        left=nullptr;
        right=nullptr;
    }

    char val;
    TreeNode* left;
    TreeNode* right;
};

int i=0;
TreeNode* buildTree(string str_pre, string str_in, int n){
    if(n==0){
        return nullptr;
    }
    TreeNode* root=new TreeNode(str_pre[i]);
    int k=str_in.find(str_pre[i]);
    i++;
    root->left=buildTree(str_pre, str_in.substr(0,k), k);
    root->right=buildTree(str_pre, str_in.substr(k+1,n-k-1), n-k-1);
    return root;
}

int getHeight(TreeNode* root){
    if(root==nullptr){
        return 0;
    }
    // cout<<root->val<<endl;
    return max(getHeight(root->left),getHeight(root->right))+1;
}

int main(){
    int n;
    string str_pre;
    string str_in;
    cin>>n;
    cin>>str_pre>>str_in;
    TreeNode* root=buildTree(str_pre,str_in,n);
    stack<TreeNode*>stk;
    // while(root!=nullptr || !stk.empty()){
    //     while(root!=nullptr){
    //         cout<<root->val;
    //         stk.push(root);
    //         root=root->left;
    //     }
    //     root=stk.top();
    //     stk.pop();
    //     root=root->right;
    // }
    cout<<getHeight(root);

}