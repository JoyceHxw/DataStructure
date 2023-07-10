#include <iostream>
using namespace std;
#include <vector>
#include <set>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// 我的解法：模拟思维，先用回溯法求出所有排列顺序，再按顺序插入，再去重，较复杂和冗长
// class Solution {
// public:
//     vector<TreeNode*> generateTrees(int n) {
//         vector<TreeNode*> ans;
//         vector<vector<int>> sequence;
//         vector<bool> visit(n+1,false);
//         vector<int> combination;
//         recursion(sequence,visit,combination,n);
//         set<vector<int>> s;
//         for(int i=0; i<sequence.size(); i++){
//             TreeNode* root=new TreeNode(0);
//             TreeNode* parent=root;
//             for(int j=0; j<sequence[i].size(); j++){
//                 TreeNode* node=new TreeNode(sequence[i][j]);
//                 parent=search(root,sequence[i][j]);
//                 if(parent->val>sequence[i][j]){
//                     parent->left=node;
//                 }
//                 else if(parent->val<sequence[i][j]){
//                     parent->right=node;
//                 }
//             }
//             // 去重
//             vector<int> v;
//             preorder(root->right,v);
//             if(s.find(v)==s.end()){
//                 s.insert(v);
//                 ans.push_back(root->right);
//             }
//         }
//         return ans;

//     }
//     // 遍历二叉树
//     void preorder(TreeNode* node, vector<int>& v){
//         if(node==nullptr){
//             return;
//         }
//         v.push_back(node->val);
//         preorder(node->left,v);
//         preorder(node->right,v);
//     }
//     // 查找二叉搜索树
//     TreeNode* search(TreeNode* root, int target){
//         TreeNode* parent;
//         while(root!=nullptr){
//             if(root->val<target){
//                 parent=root;
//                 root=root->right;
//             }
//             else if(root->val>target){
//                 parent=root;
//                 root=root->left;
//             }
//             else{
//                 return root;
//             }
//         }
//         return parent;
//     }
//     // 不同的二叉搜索树对应不同的插入顺序
//     // 确定所有排序组合，最后生成二叉搜索树
//     // 使用布尔数组去除重复元素
//     void recursion(vector<vector<int>>& sequence, vector<bool>& visit, vector<int>& combination, int n){
//         if(combination.size()==n){
//             sequence.push_back(combination);
//         }
//         for(int i=1; i<=n; i++){
//             if(visit[i]==false){
//                 combination.push_back(i);
//                 visit[i]=true;
//                 recursion(sequence,visit,combination,n);
//                 combination.pop_back();
//                 visit[i]=false;
//             }
//         }
//     }
// };


// 答案：充分利用二叉搜索树的性质（左边小于，右边大于），递归求解二叉树，从子节点不断拼接成根节点
// 注意此类回溯有返回值的写法
class Solution {
public:
    vector<TreeNode*> generateTrees(int start, int end) {
        if (start > end) {
            return { nullptr };
        }
        vector<TreeNode*> allTrees;
        // 枚举可行根节点，当前i为根节点
        for (int i = start; i <= end; i++) {
            // 获得所有可行的左子树集合
            vector<TreeNode*> leftTrees = generateTrees(start, i - 1);

            // 获得所有可行的右子树集合
            vector<TreeNode*> rightTrees = generateTrees(i + 1, end);

            // 从左子树集合中选出一棵左子树，从右子树集合中选出一棵右子树，拼接到根节点上
            for (auto& left : leftTrees) {
                for (auto& right : rightTrees) {
                    TreeNode* currTree = new TreeNode(i);
                    currTree->left = left;
                    currTree->right = right;
                    allTrees.emplace_back(currTree);
                }
            }
        }
        return allTrees;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (!n) {
            return {};
        }
        return generateTrees(1, n);
    }
};
