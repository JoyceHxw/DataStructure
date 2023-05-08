#include <iostream>
using namespace std;
#include <stack>
#include <queue>
#include <vector>

class AVLTree
{
public:
    AVLTree(int k){
        key=k;
        bf=0;
        left=nullptr;
        right=nullptr;
        // parent=nullptr;
    }

    int key;
    int bf;
    AVLTree* left;
    AVLTree* right;
    // AVLTree* parent;
};

stack<AVLTree*>stk;
// 查找
AVLTree* search(AVLTree* root, int key){
    // 清空栈
    while(!stk.empty()){
        stk.pop();
    }
    while(root!=nullptr && root->key!=key){
        stk.push(root);
        if(root->key>key){
            root=root->left;
        }
        else if(root->key<key){
            root=root->right;
        }
    }
    if(root!=nullptr && key==root->key){
        stk.push(root);
    }
    return root;
}

// 左旋
// 参数是旋转子树的根节点，返回根节点
AVLTree* L_Rotate(AVLTree* p){
    AVLTree* temp=p->right;
    p->right=temp->left;
    temp->left=p;
    p=temp;
    return p;
}
// 右旋
// 参数是旋转子树的根节点，返回根节点
AVLTree* R_Rotate(AVLTree* p){
    AVLTree* temp=p->left;
    p->left=temp->right;
    temp->right=p;
    p=temp;
    return p;
}

// 插入
AVLTree* insert(AVLTree* root, int key){
    AVLTree* p=new AVLTree(key);
    AVLTree* s=search(root,key);
    if(s!=nullptr){ // 重复值
        return root;
    }
    else{
        // 空树
        if(stk.empty()){
            return p;
        }
        // 插入
        AVLTree* parent= stk.top();
        if(parent->key>key){
            parent->left=p;
            parent->bf+=1;
        }
        else{
            parent->right=p;
            parent->bf-=1;
        }
        // 维护从根节点到新增节点之间的节点的平衡因子
        // 如果有超过-1或1的节点，旋转平衡，然后跳出循环，不用再维护之前父节点的平衡因子
        AVLTree* n_p; //旋转后新的子树节点
        while(!stk.empty()){
            AVLTree* node=stk.top();
            stk.pop();
            n_p=node;
            if(node->bf<-1){
                // RR型，一次左旋转
                if(node->right->bf==-1){
                    node->bf=0;
                    node->right->bf=0;
                    n_p=L_Rotate(node);
                }
                // RL型，先子树右旋，然后整个左旋
                // 考虑88 70 61 96 120 90 65 分情况讨论
                else if(node->right->bf==1){
                    if(node->right->left!=nullptr){
                        if(node->right->left->bf==0){
                            node->bf=0;
                            node->right->bf=0;
                        }
                        else if(node->right->left->bf==-1){
                            node->bf=1;
                            node->right->bf=0;
                            node->right->left->bf=0;
                        }
                        else if(node->right->left->bf==1){
                            node->bf=0;
                            node->right->bf=-1;
                            node->right->left->bf=0;
                        }
                    }
                    else{
                        node->bf=0;
                        node->right->bf=0;
                    }
                    n_p=R_Rotate(node->right);
                    node->right=n_p;
                    n_p=L_Rotate(node);
                }
            }
            if(node->bf>1){
                // LL型，一次右旋转
                if(node->left->bf==1){
                    node->bf=0;
                    node->left->bf=0;
                    n_p=R_Rotate(node);
                }
                // LR型，先子树左旋，然后整个右旋
                // 考虑88 70 61 96 120 90 65 分情况讨论
                else if(node->left->bf==-1){
                    if(node->left->right!=nullptr){
                        if(node->left->right->bf==0){
                            node->bf=0;
                            node->left->bf=0;
                        }
                        else if(node->left->right->bf==-1){
                            node->bf=0;
                            node->left->bf=1;
                            node->left->right->bf=0;
                        }
                        else if(node->left->right->bf==1){
                            node->bf=-1;
                            node->left->bf=0;
                            node->left->right->bf=0;
                        }
                    }
                    else{
                        node->bf=0;
                        node->left->bf=0;
                    }
                    n_p=L_Rotate(node->left);
                    node->left=n_p;
                    n_p=R_Rotate(node);
                }
            }
            if(stk.empty()){
                root=n_p;
            }
            else if(node==stk.top()->left){
                stk.top()->left=n_p;
                // 更新父节点平衡因子
                if(n_p->bf!=0){
                    stk.top()->bf+=1;
                }
                else{
                    break;
                }
            }
            else if(node==stk.top()->right){
                stk.top()->right=n_p;
                // 更新父节点平衡因子
                if(n_p->bf!=0){
                    stk.top()->bf-=1;
                }
                else{
                    break; //高度没改变，之前的根节点的平衡因子也不用变，结束循环
                }
            }
            node=n_p;
        }
        return root;
    }
    
}

// 删除
AVLTree* remove(AVLTree* root, int key){
    AVLTree* s=search(root,key);
    if(s==nullptr){
        cout<<"未找到该节点"<<key<<endl;
        return root;
    }
    // 先区分是不是叶子节点
    // 把非叶子节点转化成叶子节点，先与后继交换，没有后继就与前驱节点交换
    while(s->right!=nullptr || s->left!=nullptr ){
        if(s->left!=nullptr){
            AVLTree* last=s->left;
            while(last->right!=nullptr){
                stk.push(last);
                s->key=last->key;
                last=last->right;
            }
            stk.push(last);
            s->key=last->key;
            key=last->key;
            s=last;
        }
        else{
            AVLTree* next=s->right;
            while(next->left!=nullptr){
                stk.push(next);
                s->key=next->key;
                next=next->left;
            }
            stk.push(next);
            s->key=next->key;
            key=next->key;
            s=next;
        }
    }
    stk.pop();
    if(stk.empty()){
        delete s;
        return nullptr;
    }
    if(stk.top()->left==s){
        stk.top()->left=nullptr;
        stk.top()->bf-=1;
    }
    else{
        stk.top()->right=nullptr;
        stk.top()->bf+=1;
    }
    delete s;
    // 回溯所有父节点平衡
    // 88 70 61 96 120 90 65 60 62 71 91 55 删除96
    // 88 70 61 96 120 90 65 60 62 68 71 91 100 125 55 67 69 72 122 66 删除96 70 61
    AVLTree* n_p;
    while(!stk.empty()){
        AVLTree* node=stk.top();
        stk.pop();
        n_p=node;
        if(node->bf<-1){
            // RR型，一次左旋转
            if(node->right->bf==-1){
                node->bf=0;
                node->right->bf=0;
                n_p=L_Rotate(node);
            }
            // R型
            else if(node->right->bf==0){
                node->bf=-1;
                node->right->bf=1;
                n_p=L_Rotate(node);
            }
            // RL型，先子树右旋，然后整个左旋
            // 考虑88 70 61 96 120 90 65 分情况讨论
            else if(node->right->bf==1){
                if(node->right->left!=nullptr){
                    if(node->right->left->bf==0){
                        node->bf=0;
                        node->right->bf=0;
                    }
                    else if(node->right->left->bf==-1){
                        node->bf=1;
                        node->right->bf=0;
                        node->right->left->bf=0;
                    }
                    else if(node->right->left->bf==1){
                        node->bf=0;
                        node->right->bf=-1;
                        node->right->left->bf=0;
                    }
                }
                else{
                    node->bf=0;
                    node->right->bf=0;
                }
                n_p=R_Rotate(node->right);
                node->right=n_p;
                n_p=L_Rotate(node);
            }
        }
        if(node->bf>1){
            // LL型，一次右旋转
            if(node->left->bf==1){
                node->bf=0;
                node->left->bf=0;
                n_p=R_Rotate(node);
            }
            else if(node->left->bf==0){
                node->bf=1;
                node->left->bf=-1;
                n_p=R_Rotate(node);
            }
            // LR型，先子树左旋，然后整个右旋
            // 考虑88 70 61 96 120 90 65 分情况讨论
            else if(node->left->bf==-1){
                if(node->left->right!=nullptr){
                    if(node->left->right->bf==0){
                        node->bf=0;
                        node->left->bf=0;
                    }
                    else if(node->left->right->bf==-1){
                        node->bf=0;
                        node->left->bf=1;
                        node->left->right->bf=0;
                    }
                    else if(node->left->right->bf==1){
                        node->bf=-1;
                        node->left->bf=0;
                        node->left->right->bf=0;
                    }
                }
                else{
                    node->bf=0;
                    node->left->bf=0;
                }
                n_p=L_Rotate(node->left);
                node->left=n_p;
                n_p=R_Rotate(node);
            }
        }
        if(stk.empty()){
            root=n_p;
        }
        else if(node==stk.top()->left){
            stk.top()->left=n_p;
            // 更新父节点平衡因子
            if(n_p->bf==0){
                stk.top()->bf-=1;
            }
            else{
                break; //跳出循环，不用再维护父节点平衡因子
            }
        }
        else if(node==stk.top()->right){
            stk.top()->right=n_p;
            // 更新父节点平衡因子
            if(n_p->bf==0){
                stk.top()->bf+=1;
            }
            else{
                break; //跳出循环，不用再维护父节点平衡因子
            }
        }
        node=n_p;
    }
    return root;
}

void show(AVLTree* root){
    if(root==nullptr){
        return;
    }
    queue<AVLTree*> q;
    q.push(root);
    int level=1;
    while(!q.empty()){
        cout<<"level "<<level<<": ";
        int size=q.size();
        int cnt=0;
        while(cnt<size){
            AVLTree* node=q.front();
            cout<<node->key<<" ";
            q.pop();
            if(node->left!=nullptr){
                q.push(node->left);
            }
            if(node->right!=nullptr){
                q.push(node->right);
            }
            cnt++;
        }
        level++;
        cout<<endl;
    }
}

int main(){
    // 构造AVL树
    int n;
    cin>>n;
    AVLTree* root=nullptr;
    // for(int i=0; i<n; i++){
    //     int a;
    //     cin>>a;
    //     root=insert(root,a);
    // }
    for(int i=1; i<=n; i++){
        root=insert(root,i);
    }
    show(root);

    // BFS层序遍历
    // queue<AVLTree*> q;
    // q.push(root);
    // vector<AVLTree*> v;
    // v.push_back(nullptr);
    // int cnt=0;
    // while(!q.empty()){
    //     AVLTree* node=q.front();
    //     if(cnt==0){
    //         cout<<node->key;
    //     }
    //     else{
    //         cout<<" "<<node->key;
    //     }
    //     cnt++;
    //     v.push_back(node);
    //     q.pop();
    //     if(node->left!=nullptr){
    //         q.push(node->left);
    //     }
    //     if(node->right!=nullptr){
    //         q.push(node->right);
    //     }
    // }

    // // 判断完全二叉树
    // cout<<endl;
    // bool isComplete=true;
    // for(int i=1; i<v.size(); i++){
    //     // cout<<v[i]->key<<" ";
    //     if((2*i<v.size() && v[i]->left!=v[2*i]) || (2*i+1<v.size() && v[i]->right!=v[2*i+1])){
    //         cout<<"No";
    //         isComplete=false;
    //         break;
    //     }
    // }
    // if(isComplete==true){
    //     cout<<"Yes";
    // }

    // cout<<endl;
    // 删除
    int n1;
    cin>>n1;
    for(int i=1; i<=n1; i++){
        // int num;
        // cin>>num;
        root=remove(root,n1-i+1);
    }
    show(root);
    // cin>>remove_num;
    // root=remove(root,remove_num);
    // if(root==nullptr){
    //     return 0;
    // }
    // q.push(root);
    // int cnt1=0;
    // while(!q.empty()){
    //     AVLTree* node=q.front();
    //     if(cnt1==0){
    //         cout<<node->key;
    //     }
    //     else{
    //         cout<<" "<<node->key;
    //     }
    //     cnt1++;
    //     q.pop();
    //     if(node->left!=nullptr){
    //         q.push(node->left);
    //     }
    //     if(node->right!=nullptr){
    //         q.push(node->right);
    //     }
    // }

}