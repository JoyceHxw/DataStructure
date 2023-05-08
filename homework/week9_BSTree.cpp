#include <iostream>
using namespace std;
#include <stack>
#include <queue>

class BSTree
{
public:
    BSTree(int k){
        key=k;
        left=nullptr;
        right=nullptr;
    }

    int key;
    BSTree* left;
    BSTree* right;
};

stack<BSTree*>stk;
BSTree* search(BSTree* root, int key){
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

// 插入
BSTree* insert(BSTree* root, int key){
    BSTree* p=new BSTree(key);
    BSTree* s=search(root,key);
    if(s!=nullptr){ // 重复值
        return root;
    }
    else{
        // 空树
        if(stk.empty()){
            return p;
        }
        // 插入
        BSTree* parent= stk.top();
        if(parent->key>key){
            parent->left=p;
        }
        else{
            parent->right=p;
        }
        return root;
    }
}

// 删除
BSTree* remove(BSTree* root, int key){
    BSTree* s=search(root,key);
    if(s==nullptr){
        cout<<"未找到该节点！"<<endl;
        return root;
    }
    while(s->right!=nullptr || s->left!=nullptr ){
        if(s->left!=nullptr){
            BSTree* last=s->left;
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
            BSTree* next=s->right;
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
    }
    else{
        stk.top()->right=nullptr;
    }
    delete s;
    return root;
}

void show(BSTree* root){
    if(root==nullptr){
        return;
    }
    queue<BSTree*> q;
    q.push(root);
    int level=1;
    while(!q.empty()){
        cout<<"level "<<level<<": ";
        int size=q.size();
        int cnt=0;
        while(cnt<size){
            BSTree* node=q.front();
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
    int n;
    cin>>n;
    BSTree* root=nullptr;
    for(int i=1; i<=n; i++){
        root=insert(root,i);
    }
    show(root);
    int n1;
    cin>>n1;
    for(int i=1; i<=n1; i++){
        root=remove(root,n1-i+1);
    }
    show(root);
}