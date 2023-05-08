#include <iostream>
using namespace std;
#define RED 'R'
#define BLACK 'B'
#include <stack>
#include <queue>
#include <algorithm>

class RBTree
{
public:
    // 默认新节点颜色为红色
    RBTree(int k){
        key=k;
        color=RED;
        left=nullptr;
        right=nullptr;
        parent=nullptr;
    }

    RBTree(){
        color=RED;
        left=nullptr;
        right=nullptr;
        parent=nullptr;
    }

    int key;
    char color;
    RBTree* left;
    RBTree* right;
    RBTree* parent;
};

stack<RBTree*>stk;
RBTree* search(RBTree* root, int key){
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
RBTree* L_Rotate(RBTree* p){
    RBTree* temp=p->right;
    p->right=temp->left;
    temp->left=p;
    p->parent=temp;
    if(p->right!=nullptr){
        p->right->parent=p;
    }
    p=temp;
    return p;
}
// 右旋
RBTree* R_Rotate(RBTree* p){
    RBTree* temp=p->left;
    p->left=temp->right;
    temp->right=p;
    p->parent=temp;
    if(p->left!=nullptr){
        p->left->parent=p;
    }
    p=temp;
    return p;
}


// 插入
RBTree* insert(RBTree* root, int key){
    RBTree* s=search(root,key);
    RBTree* p=new RBTree(key);
    if(s!=nullptr){
        // cout<<key<<"元素重复!"<<endl;
        return root; 
    }
    else{
        if(root==nullptr){ // 空树
            p->color=BLACK; // 根节点颜色为黑色
            return p;
        }
        else{
            // 插入到元素
            RBTree* p_p=stk.top();
            if(p->key>p_p->key){
                p_p->right=p;
            }
            else{
                p_p->left=p;
            }
            p->parent=p_p;

            // 调整红黑树
            RBTree* g_p;
            while(true){
                g_p=p_p->parent;
                if(p_p->color==RED){
                    // 查看父节点的兄弟节点的颜色
                    // 区分父节点是祖父节点的左/右节点
                    if(p_p==g_p->left){  // L型
                        if(g_p->right!=nullptr && g_p->right->color==RED){ // XYr 染色
                            g_p->left->color=BLACK;
                            g_p->right->color=BLACK;
                            // 是否回溯
                            if(g_p->parent!=nullptr){
                                g_p->color=RED;  //不是根节点
                                p=g_p;
                                p_p=g_p->parent;
                            }
                            else{
                                return root;
                            }
                        }
                        else{ // XYb 旋转
                            // 区分单旋还是双旋
                            RBTree* n_p;
                            RBTree* g_p_p=g_p->parent;
                            if(p==p_p->left){ // 右旋
                                n_p=R_Rotate(g_p);
                                p_p->color=BLACK;
                                g_p->color=RED;
                            }
                            else{  // 先左旋，再右旋
                                n_p=L_Rotate(p_p);
                                g_p->left=n_p;
                                n_p->parent=g_p;
                                n_p=R_Rotate(g_p);
                                p->color=BLACK;
                                g_p->color=RED;
                            }
                            // 修改子树的根节点 已经改过父节点了
                            if(g_p_p!=nullptr){
                                // 区分左右
                                if(g_p_p->left==g_p){
                                    g_p_p->left=n_p;
                                }
                                else{
                                    g_p_p->right=n_p;
                                }
                                n_p->parent=g_p_p;
                            }
                            else{
                                n_p->parent=nullptr;
                                root=n_p;
                            }
                            return root;
                        }
                    }
                    else{ // R型
                        if(g_p->left!=nullptr && g_p->left->color==RED){ // XYr 染色
                            g_p->left->color=BLACK;
                            g_p->right->color=BLACK;
                            // 是否回溯
                            if(g_p->parent!=nullptr){
                                g_p->color=RED;  //不是根节点
                                p=g_p;
                                p_p=g_p->parent;
                            }
                            else{
                                return root;
                            }
                        }
                        else{ // XYb 旋转
                            // 区分单旋还是双旋
                            RBTree* n_p;
                            RBTree* g_p_p=g_p->parent;
                            if(p==p_p->right){ // 左旋
                                n_p=L_Rotate(g_p);
                                p_p->color=BLACK;
                                g_p->color=RED;
                            }
                            else{  // 先右旋，再左旋
                                n_p=R_Rotate(p_p);
                                g_p->right=n_p;
                                n_p->parent=g_p;
                                n_p=L_Rotate(g_p);
                                p->color=BLACK;
                                g_p->color=RED;
                            }
                            // 修改子树的根节点
                            if(g_p_p!=nullptr){
                                // 区分左右
                                if(g_p_p->left==g_p){
                                    g_p_p->left=n_p;
                                }
                                else{
                                    g_p_p->right=n_p;
                                }
                                n_p->parent=g_p_p;
                            }
                            else{
                                n_p->parent=nullptr;
                                root=n_p;
                            }
                            return root;
                        }
                    }
                }
                else{
                    return root;
                }
            }
        }
    }
}

// 删除节点delete
void delete_p(RBTree* p,RBTree* p_p){
    // 删除节点
    if(p==p_p->left){
        p_p->left=nullptr;
    }
    else{
        p_p->right=nullptr;
    }
    delete p;
}

// 删除
RBTree* remove(RBTree* root, int key){
    RBTree* s=search(root,key);
    if(s==nullptr){
        cout<<"没有该元素"<<key<<endl;
        return root;
    }
    else{
        // 先区分是不是叶子节点
        // 把非叶子节点转化成叶子节点，先与后继交换，没有后继就与前驱节点交换
        // 删除带有双子结点时，找直接后继。
        // 不是叶子节点就继续交换
        while(s->right!=nullptr || s->left!=nullptr ){
            if(s->right!=nullptr){
                RBTree* next=s->right;
                while(next->left!=nullptr){
                    next=next->left;
                }
                s->key=next->key;
                key=next->key;
                s=next;
            }
            else{
                RBTree* last=s->left;
                while(last->right!=nullptr){
                    last=last->right;
                }
                s->key=last->key;
                key=last->key;
                s=last;
            }
        }
        RBTree* p_s=s->parent;
        
        // 调整红黑树
        if(s->color==RED){
            // 删除节点
            delete_p(s,p_s);
            return root;
        }
        else{
            RBTree* p=s; // 被删除节点
            RBTree* p_p;
            RBTree* b_p; //兄弟节点
            RBTree* g_p;
            RBTree* n_p;
            while(true){ //对于兄弟节点为黑，且兄弟节点的孩子节点全为黑，且父节点为黑的情况
                p_p=p->parent;
                if(p_p!=nullptr){
                    g_p=p_p->parent;
                }
                else{
                    cout<<"Null";
                    return nullptr;
                }
                if(p==p_p->left){ // 被删除节点在左边
                    while(true){ // 对于兄弟节点为红色的情况
                        b_p=p_p->right;
                        g_p=p_p->parent;
                        // 区分兄弟节点是否是黑色
                        if(b_p==nullptr || b_p->color==BLACK){ 
                            // 区分兄弟节点的孩子节点的黑色节点的个数
                            if(b_p==nullptr){
                                if(p_p->color==RED){
                                    p_p->color=BLACK;
                                    // 删除节点
                                    delete_p(s,p_s);
                                    return root;
                                }
                                else{
                                    if(g_p==nullptr){
                                        // 删除节点
                                        delete_p(s,p_s);
                                        return root;
                                    }
                                    // 向上回溯
                                    else{
                                        p=p_p;
                                        p_p=g_p;
                                        break;
                                    }
                                }
                            }
                            else if((b_p->left==nullptr || b_p->left->color==BLACK) && (b_p->right==nullptr || b_p->right->color==BLACK)){ // 全为黑色
                                if(p_p->color==BLACK){
                                    b_p->color=RED;
                                    // 根节点不用回溯
                                    if(g_p==nullptr){
                                        // 删除节点
                                        delete_p(s,p_s);
                                        return root;
                                    }
                                    // 向上回溯，相当于B树合并，父节点元素不够
                                    else{
                                        p=p_p;
                                        p_p=g_p;
                                        break;
                                    }
                                    
                                }
                                else{// 相当于B树合并，父节点元素充足
                                    b_p->color=RED;
                                    p_p->color=BLACK;
                                    // 删除节点
                                    delete_p(s,p_s);
                                    return root;
                                }
                            }
                            else{ //非全黑色
                                while(true){  // 对于兄弟节点的右孩子节点不为红色的情况
                                    // 区分兄弟节点的右孩子是否为红色，相当于B树是否可以从兄弟节点借
                                    if(b_p->right!=nullptr && b_p->right->color==RED){ //左旋
                                        b_p->color=p_p->color; // 根节点颜色不变
                                        p_p->color=BLACK;
                                        b_p->right->color=BLACK;
                                        n_p=L_Rotate(p_p);
                                        // 修改子树的根节点
                                        if(g_p!=nullptr){
                                            // 区分左右
                                            if(g_p->left==p_p){
                                                g_p->left=n_p;
                                            }
                                            else{
                                                g_p->right=n_p;
                                            }
                                            n_p->parent=g_p;
                                        }
                                        else{
                                            n_p->parent=nullptr;
                                            root=n_p;
                                        }
                                        // 删除节点
                                        delete_p(s,p_s);
                                        return root;

                                    }
                                    else{ //对兄弟节点进行右旋，转换成上面的情况，相当于两次旋转
                                        b_p->color=RED;
                                        b_p->left->color=BLACK;
                                        n_p=R_Rotate(b_p);
                                        // 修改子树根节点
                                        p_p->right=n_p;
                                        n_p->parent=p_p;
                                        // 循环
                                        // 更新兄弟节点
                                        b_p=n_p;
                                    }
                                }
                            }
                        }
                        else{//旋转，转换成兄弟节点为黑色的情况
                            p_p->color=RED;
                            b_p->color=BLACK;
                            n_p=L_Rotate(p_p);
                            // 修改子树的根节点
                            if(g_p!=nullptr){
                                // 区分左右
                                if(g_p->left==p_p){
                                    g_p->left=n_p;
                                }
                                else{
                                    g_p->right=n_p;
                                }
                                n_p->parent=g_p;
                            }
                            else{
                                n_p->parent=nullptr;
                                root=n_p;
                            }
                            // 循环
                            // 更新兄弟节点
                        }
                    }
                }
                else{ //被删除节点在右边
                    while(true){ // 对于兄弟节点为红色的情况
                        b_p=p_p->left;
                        g_p=p_p->parent;
                        // 区分兄弟节点是否是黑色
                        if(b_p==nullptr || b_p->color==BLACK){ 
                            // 区分兄弟节点的孩子节点的黑色节点的个数
                            if(b_p==nullptr){
                                if(p_p->color==RED){
                                    p_p->color=BLACK;
                                    // 删除节点
                                    delete_p(s,p_s);
                                    return root;
                                }
                                else{
                                    // 根节点不用回溯
                                    if(g_p==nullptr){
                                        // 删除节点
                                        delete_p(s,p_s);
                                        return root;
                                    }
                                    // 向上回溯，相当于B树合并，父节点元素不够
                                    else{
                                        p=p_p;
                                        p_p=g_p;
                                        break;
                                    }
                                }
                            }
                            else if((b_p->left==nullptr || b_p->left->color==BLACK) && (b_p->right==nullptr || b_p->right->color==BLACK)){ // 全为黑色
                                if(p_p->color==BLACK){
                                    b_p->color=RED;
                                    // 根节点不用回溯
                                    if(g_p==nullptr){
                                        // 删除节点
                                        delete_p(s,p_s);
                                        return root;
                                    }
                                    // 向上回溯，相当于B树合并，父节点元素不够
                                    else{
                                        p=p_p;
                                        p_p=g_p;
                                        break;
                                    }
                                    // 向上回溯，相当于B树合并，父节点元素不够
                                }
                                else{// 相当于B树合并，父节点元素充足
                                    b_p->color=RED;
                                    p_p->color=BLACK;
                                    // 删除节点
                                    delete_p(s,p_s);
                                    return root;
                                }
                            }
                            else{ //非全黑色
                                while(true){  // 对于兄弟节点的左孩子节点不为红色的情况
                                    // 区分兄弟节点的左孩子是否为红色，相当于B树是否可以从兄弟节点借
                                    if(b_p->left!=nullptr && b_p->left->color==RED){ //左旋
                                        b_p->color=p_p->color; // 根节点颜色不变
                                        p_p->color=BLACK;
                                        b_p->left->color=BLACK;
                                        n_p=R_Rotate(p_p);
                                        // 修改子树的根节点
                                        if(g_p!=nullptr){
                                            // 区分左右
                                            if(g_p->left==p_p){
                                                g_p->left=n_p;
                                            }
                                            else{
                                                g_p->right=n_p;
                                            }
                                            n_p->parent=g_p;
                                        }
                                        else{
                                            n_p->parent=nullptr;
                                            root=n_p;
                                        }
                                        // 删除节点
                                        delete_p(s,p_s);
                                        return root;

                                    }
                                    else{ //对兄弟节点进行左旋，转换成上面的情况，相当于两次旋转
                                        b_p->color=RED;
                                        b_p->right->color=BLACK;
                                        n_p=L_Rotate(b_p);
                                        // 修改子树根节点
                                        p_p->left=n_p;
                                        n_p->parent=p_p;
                                        // 循环
                                        // 更新兄弟节点
                                        b_p=n_p;
                                    }
                                }
                            }
                        }
                        else{//旋转，转换成兄弟节点为黑色的情况
                            p_p->color=RED;
                            b_p->color=BLACK;
                            n_p=R_Rotate(p_p);
                            // 修改子树的根节点
                            if(g_p!=nullptr){
                                // 区分左右
                                if(g_p->left==p_p){
                                    g_p->left=n_p;
                                }
                                else{
                                    g_p->right=n_p;
                                }
                                n_p->parent=g_p;
                            }
                            else{
                                n_p->parent=nullptr;
                                root=n_p;
                            }
                            // 循环
                            // 更新兄弟节点
                        }
                    }
                }
            }

        }

        
    }
}

// 层序遍历
void show(RBTree* root){
    if(root==nullptr){
        return;
    }
    queue<RBTree*> q;
    q.push(root);
    int level=1;
    while(!q.empty()){
        cout<<"level "<<level<<": ";
        int size=q.size();
        int cnt=0;
        while(cnt<size){
            RBTree* node=q.front();
            cout<<node->key<<'('<<node->color<<')'<<" ";
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

// 前序遍历
void preshow(RBTree* root){
    if(root==nullptr){
        return;
    }
    cout<<root->key<<"("<<root->color<<")"<<" ";
    preshow(root->left);
    preshow(root->right);
}


int main(){
    // 12 -10 9 -5 -15 11 7 19 4 15 18 5 14 13 10 16 6 -3 8 17 0 2 删除8，5
    // 插入 
    int n;
    cin>>n;
    RBTree* root=nullptr;
    vector<int>v;
    for(int i=0; i<n; i++){
        v.push_back(i+1);
    }
    random_shuffle(v.begin(),v.end());
    for(int i=0; i<n; i++){
        root=insert(root,v[i]);
    }
    // 最大值/最小值
    // int max_key=-2147483648;       //INT_MIN;
    // int min_key=2147483647;       //INT_MAX;
    // for(int i=0; i<n; i++){
    //     int a;
    //     cin>>a;
    //     max_key=max(max_key,a);
    //     min_key=min(min_key,a);
    //     root=insert(root,a);
    // }
    show(root);
    // preshow(root);
    // cout<<endl;
    // cout<<min_key<<" "<<max_key<<endl;

    // 删除
    // int n2;
    // cin>>n2;
    random_shuffle(v.begin(),v.end());
    // for(int i=0; i<n2; i++){
    //     int a;
    //     cin>>a;
    //     root=remove(root,a);
    // }
    for(int i=0; i<n; i++){
        cout<<i<<"  "<<v[i]<<endl;
        root=remove(root,v[i]);
    }
    show(root);
    // preshow(root);
}