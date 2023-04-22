#include <iostream>
using namespace std;
#define RANK 4
#include <stack>
#include <queue>

class BTree
{
public:
    int size;
    int keys[RANK-1];
    BTree* refs[RANK];

    BTree(){
        size=0; //初始化
        for(int i=0; i<RANK; i++){
            refs[i]=nullptr;
        }
        for(int i=0; i<RANK-1; i++){
            keys[i]=-1;
        }
    }
    BTree(int key){
        // 初始化
        for(int i=0; i<RANK; i++){
            refs[i]=nullptr;
        }
        for(int i=0; i<RANK-1; i++){
            keys[i]=-1;
        }
        keys[0]=key;
        size=1;
    }
};

struct Position
{
    BTree* node;
    int pos;
};


stack<BTree*>stk;
// 返回所在节点及节点中的位置
Position search(BTree* root, int key){
    Position Pos={nullptr, -1};
    // 清空栈
    while(!stk.empty()){
        stk.pop();
    }
    while(root!=nullptr){
        stk.push(root);
        bool isFound=false;
        // 节点内索引值
        for(int i=0; i<root->size; i++){
            if(root->keys[i]==key){
                isFound=true;
                Pos.node=root;
                Pos.pos=i;
                return Pos;
            }
            if(root->keys[i]>key){
                root=root->refs[i];  // 指向索引相同下标的节点
                isFound=true;
                break;
            }
        }
        if(isFound==false){
            root=root->refs[root->size];
        }
    }
    return Pos;
}

// 插入
BTree* insert(BTree* root, int key){
    BTree* s=search(root,key).node;
    BTree* p=new BTree(key);
    // 重复值
    if(s!=nullptr){
        cout<<key<<"元素重复!"<<endl;
        return root; 
    }
    else{
        // 空树
        if(root==nullptr){
            return p;
        }
        else{
            BTree* n_sub=nullptr;
            while(!stk.empty()){
                BTree* node=stk.top();
                stk.pop();
                // 元素数量小于m-1，直接加在元素中
                if(node->size<RANK-1){
                    int i=0;
                    while(i<node->size && node->keys[i]<key){
                        i++;
                    }
                    // 向后移动元素，把新元素添加进去
                    // 对应索引也要后移，注意索引比元素多一个
                    int j=node->size;
                    while(j>i){
                        node->keys[j]=node->keys[j-1];
                        node->refs[j+1]=node->refs[j];
                        j--;
                    }
                    node->refs[i+1]=node->refs[i];
                    node->keys[i]=key;
                    node->refs[i]=n_sub;
                    node->size++;
                    
                    //插入结束，退出循环 
                    return root;
                }

                // 超过阶数，从中间分裂
                // 注意更新该节点和父节点的索引refs和元素数量size
                else{
                    int k=(RANK-1)/2;  // 当m是奇数是，取的是中间靠后的一个数，这对于m=3且从在左边插入来说是有问题的，因为右边部分是空的
                    int n_key;
                    // 左边为新节点，方便更新父节点索引
                    BTree* n_p=new BTree;
                    if (key>node->keys[k]){  // 插入到右边，把中位数提到父节点中
                        // 先处理左边，创建新节点,复制元素
                        n_key=node->keys[k];
                        int j=0;
                        int index=0;
                        while(j<k){
                            n_p->keys[index]=node->keys[j];
                            n_p->refs[index]=node->refs[j];
                            j++;
                            index++;
                            n_p->size++;
                        }
                        n_p->refs[index]=node->refs[j];

                        // 再处理右边部分，缩小原节点
                        int i=k+1;
                        int len=node->size;
                        int index2=0;
                        // 先元素左移
                        while(i<len){
                            node->keys[index2]=node->keys[i];
                            node->refs[index2]=node->refs[i];
                            i++;
                            index2++;
                        }
                        node->size=index2; //逻辑上删除右边的元素
                        node->refs[index2]=node->refs[i]; //最后一个索引
                        // 再插入新元素
                        int l=0;
                        while(l<node->size && node->keys[l]<key){
                            l++;
                        }
                        int x=node->size;
                        while(x>l){
                            node->keys[x]=node->keys[x-1];
                            node->refs[x+1]=node->refs[x];
                            x--;
                        }
                        node->refs[x+1]=node->refs[x];
                        node->keys[l]=key;
                        node->refs[l]=n_sub;
                        node->size++;
                    }
                    else{ // 插入到左边，把中位数提到父节点中
                        // 先处理左边部分，创建新节点
                        if (RANK==3){
                            k-=1; //以防出现m=3时，右边为空的情况
                            if (node->keys[k]<key){ // 第一个指针索引为原来的，第二个索引为新的
                                int temp=node->keys[k];
                                node->keys[k]=key;
                                key=temp;

                                n_key=node->keys[k];

                                n_p->keys[0]=key;
                                n_p->refs[0]=node->refs[0];
                                n_p->size++;
                                n_p->refs[1]=n_sub;

                                // 再处理右边部分，缩小原节点
                                int i=k+1;
                                int len=node->size;
                                int index2=0;
                                while(i<len){
                                    // 元素左移
                                    node->keys[index2]=node->keys[i];
                                    node->refs[index2]=node->refs[i];
                                    i++;
                                    index2++;
                                }
                                node->size=index2;
                                node->refs[index2]=node->refs[i];
                            }
                            else{
                                n_key=node->keys[k];
                                int j=0;
                                int index=0;
                                while(j<k && key>node->keys[j]){
                                    n_p->keys[index]=node->keys[j];
                                    n_p->refs[index]=node->refs[j];
                                    j++;
                                    index++;
                                    n_p->size++;
                                }
                                n_p->keys[index]=key;
                                n_p->refs[index]=n_sub;
                                index++;
                                n_p->size++;
                                while(j<k){
                                    n_p->keys[index]=node->keys[j];
                                    n_p->refs[index]=node->refs[j];
                                    j++;
                                    index++;
                                    n_p->size++;
                                }
                                n_p->refs[index]=node->refs[j];

                                // 再处理右边部分，缩小原节点
                                int i=k+1;
                                int len=node->size;
                                int index2=0;
                                while(i<len){
                                    // 元素左移
                                    node->keys[index2]=node->keys[i];
                                    node->refs[index2]=node->refs[i];
                                    i++;
                                    index2++;
                                }
                                node->size=index2;
                                node->refs[index2]=node->refs[i];
                            }
                        }
                        else{
                            n_key=node->keys[k];
                            int j=0;
                            int index=0;
                            while(j<k && key>node->keys[j]){
                                n_p->keys[index]=node->keys[j];
                                n_p->refs[index]=node->refs[j];
                                j++;
                                index++;
                                n_p->size++;
                            }
                            n_p->keys[index]=key;
                            n_p->refs[index]=n_sub; 
                            index++;
                            n_p->size++;
                            while(j<k){
                                n_p->keys[index]=node->keys[j];
                                n_p->refs[index]=node->refs[j];
                                j++;
                                index++;
                                n_p->size++;
                            }
                            n_p->refs[index]=node->refs[j];

                            // 再处理右边部分，缩小原节点
                            int i=k+1;
                            int len=node->size;
                            int index2=0;
                            while(i<len){
                                // 元素左移
                                node->keys[index2]=node->keys[i];
                                node->refs[index2]=node->refs[i];
                                i++;
                                index2++;
                            }
                            node->size=index2;
                            node->refs[index2]=node->refs[i];

                        }
                    }
                    
                    // 循环把中间元素加到父节点中
                    // 改变索引
                    key=n_key;
                    n_sub=n_p;
                }
            }
            // 新增头节点
            BTree* n_root=new BTree(key);
            if(key>root->keys[root->size-1]){
                n_root->refs[0]=root;
                n_root->refs[1]=n_sub;
            }
            else{
                n_root->refs[0]=n_sub;
                n_root->refs[1]=root;
            }
            return n_root;
        }
    }
}

// 删除
BTree* remove(BTree* root, int key){
    Position Pos=search(root,key);
    BTree* s=Pos.node;
    int pos=Pos.pos;
    if(s==nullptr){
        cout<<"没有该元素"<<key<<endl;
        return root;
    }
    else{
        // 先区分是不是叶子节点
        // 把非叶子节点转化成叶子节点，从前驱节点借
        while(s->refs[0]!=nullptr){
            // 从前驱借
            BTree* son=s->refs[pos];
            key=son->keys[son->size-1];
            Pos=search(root,key);
            s->keys[pos]=son->keys[son->size-1];
            s=Pos.node;
            pos=Pos.pos;
        }
        while(!stk.empty()){
            BTree* node=stk.top();
            stk.pop();
            bool isLeft=false;
            // 大于最小元素数量+1，或为根节点，直接减去
            if(node->size>=(RANK-1)/2+1 || stk.empty()){
                // 注意移动索引，都是保留左节点
                int p=pos;
                while(p<node->size-1){
                    node->keys[p]=node->keys[p+1];
                    node->refs[p+1]=node->refs[p+2];
                    p++;
                }
                node->size--;
                // 是否删去根节点
                if (root->size==0){
                    return root->refs[0];
                }
                else{
                    return root;
                }
            }
            // 从兄弟节点中借或和兄弟节点合并
            else{
                // 父节点元素可能不够
                int i=0;
                // 定位节点在父节点中的位置
                while(i<stk.top()->size+1 && stk.top()->refs[i]!=node){
                    i++;
                }
                BTree* next;
                // 从左节点借
                if(i!=0){
                    // 左节点
                    next=stk.top()->refs[i-1];
                    // 可以从左节点借
                    if(next->size>=(RANK-1)/2+1){
                        int max_key=next->keys[next->size-1];
                        int par_key=stk.top()->keys[i-1];
                        // 移动被删除元素节点中的元素
                        int j=pos;
                        while(j>0){
                            node->keys[j]=node->keys[j-1];
                            node->refs[j+1]=node->refs[j];
                            j--;
                        }
                        node->refs[j+1]=node->refs[j];
                        // 替换三个节点中的元素
                        node->keys[0]=par_key;
                        node->refs[0]=next->refs[next->size];
                        stk.top()->keys[i-1]=max_key;
                        next->size--;
                        return root; // 结束合并，退出循环
                    }
                    // 与左节点合并
                    else{
                        // 借用父节点
                        // 向右移动节点中的元素
                        int j=pos;
                        while(j>0){
                            node->keys[j]=node->keys[j-1];
                            node->refs[j+1]=node->refs[j];
                            j--;
                        }
                        node->refs[j+1]=node->refs[j];
                        // 把父节点元素移动到当前节点
                        int par_key=stk.top()->keys[i-1];
                        node->keys[0]=par_key;
                        // 更新要删除的元素位置
                        pos=i-1;
                        // 与左节点合并
                        // 保留左节点
                        int l_next=next->size;
                        for(int m=0; m<node->size; m++){
                            next->keys[l_next+m]=node->keys[m];
                            next->refs[l_next+m+1]=node->refs[m+1];
                            next->size++;
                        }
                    }
                }
                // 从右节点借
                else{
                    isLeft=true;
                    // 右节点
                    next=stk.top()->refs[i+1];
                    // 可以从右节点借
                    if(next->size>=(RANK-1)/2+1){
                        int min_key=next->keys[0];
                        int par_key=stk.top()->keys[0];
                        // 移动被删除元素节点中的元素
                        int j=pos;
                        while(j<node->size-1){
                            node->keys[j]=node->keys[j+1];
                            node->refs[j+1]=node->refs[j+2];
                            j++;
                        }
                        node->keys[node->size-1]=par_key;
                        node->refs[node->size]=next->refs[0];
                        // 移动右节点元素
                        int r=0;
                        while(r<next->size-1){
                            next->keys[r]=next->keys[r+1];
                            next->refs[r]=next->refs[r+1];
                            r++;
                        }
                        next->refs[r]=next->refs[r+1];
                        stk.top()->keys[0]=min_key;
                        next->size--;
                        return root;  // 结束合并，退出循环
                    }
                    // 与右节点合并
                    else{
                        // 借用父节点
                        // 向左移动节点中的元素
                        int j=pos;
                        while(j<node->size-1){
                            node->keys[j]=node->keys[j+1];
                            node->refs[j+1]=node->refs[j+2];
                            j++;
                        }
                        // 父节点元素是否充足
                        int par_key=stk.top()->keys[i];
                        node->keys[node->size-1]=par_key;
                        // 更新要删除的元素位置
                        pos=0;
                        // 与右节点合并
                        // 保留原节点
                        int l_node=node->size;
                        for(int m=0; m<next->size; m++){
                            node->keys[l_node+m]=next->keys[m];
                            node->refs[l_node+m]=next->refs[m];
                            node->size++;
                        }
                        node->refs[node->size]=next->refs[next->size];
                    }
                }
            }
        }
        return root;
    }
}

// B树的层序遍历
void show(BTree* root){
    queue<BTree*> q;
    q.push(root);
    int level=1;
    while(!q.empty()){
        cout<<"level "<<level<<": ";
        int size=q.size();
        int cnt=0;
        while(cnt<size){
            BTree* node=q.front();
            for(int i=0; i<node->size; i++){
                cout<<node->keys[i] <<" ";
            }
            cout<<"   ";
            q.pop();
            for(int j=0; j<node->size+1; j++){
                if (node->refs[j]!=nullptr){
                    q.push(node->refs[j]);
                }
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
    BTree* root;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        if(i==0){
            root=new BTree(a);
        }
        else{
            root=insert(root,a);
        }
    }
    show(root);

    int r;
    cin>>r;
    root=remove(root,r);
    show(root);
}