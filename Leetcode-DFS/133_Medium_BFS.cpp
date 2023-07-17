#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <queue>


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


// 自己写对，整体思路是BFS，但其中细节需要注意
// 是图不是树，所以遍历过程需要记录是否visit
// 不只是遍历，还需要建立与邻接节点的关系
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr){
            return nullptr;
        }
        // BFS遍历+记录已经拷贝过的点
        unordered_map<int,Node*> m;
        queue<Node*>q; //父节点
        queue<Node*>c; //子节点
        Node* ans=new Node(0,vector<Node*>(1));
        q.push(ans);
        c.push(node);
        while(!q.empty()){
            Node* parent=q.front();
            q.pop();
            Node* p;
            for(int i=0; i<parent->neighbors.size(); i++){
                Node* cur=c.front();
                c.pop();
                if(m[cur->val]==nullptr){
                    p=new Node(cur->val,vector<Node*>(cur->neighbors.size()));
                    m[cur->val]=p;
                    q.push(p);
                    for(int j=0; j<cur->neighbors.size(); j++){
                        c.push(cur->neighbors[j]);
                    }
                }
                else{
                    p=m[cur->val];
                }
                parent->neighbors[i]=p;
            }
            parent=p;
        }
        return ans->neighbors[0];
    }
};

// 答案更加简洁：键为Node*形式可以直接找到对应的Node*
// class Solution {
// public:
//     Node* cloneGraph(Node* node) {
//         if (node == nullptr) {
//             return node;
//         }

//         unordered_map<Node*, Node*> visited;

//         // 将题目给定的节点添加到队列
//         queue<Node*> Q;
//         Q.push(node);
//         // 克隆第一个节点并存储到哈希表中
//         visited[node] = new Node(node->val);

//         // 广度优先搜索
//         while (!Q.empty()) {
//             // 取出队列的头节点
//             auto n = Q.front();
//             Q.pop();
//             // 遍历该节点的邻居
//             for (auto& neighbor: n->neighbors) {
//                 if (visited.find(neighbor) == visited.end()) {
//                     // 如果没有被访问过，就克隆并存储在哈希表中
//                     visited[neighbor] = new Node(neighbor->val);
//                     // 将邻居节点加入队列中
//                     Q.push(neighbor);
//                 }
//                 // 更新当前节点的邻居列表
//                 visited[n]->neighbors.emplace_back(visited[neighbor]);
//             }
//         }

//         return visited[node];
//     }
// };
