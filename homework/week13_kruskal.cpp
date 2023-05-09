#include <iostream>
using namespace std;
#include <vector>

// Kruskal算法的并查集
// 查找根节点（等于自己）
int find(int index, int* parent){
    while(index!=parent[index]){
        index=parent[index];
    }
    return index;
}
// 路径压缩，把途径节点的父节点都设为树的根节点，降低树的高度
int find_compress(int index, int* parent){
    if(index==parent[index]){
        return parent[index];
    }
    if(index!=parent[index]){
        parent[index]=find_compress(parent[index],parent);
    }
    return parent[index];
}
// 路径压缩，把途径节点的父节点设为其祖父节点
int find_compress_split(int index, int* parent){
    while(index!=parent[index]){
        int temp=parent[index];
        parent[index]=parent[parent[index]];
        index=temp;
    }
    return index;
}
// 路径压缩，间隔设置途径节点的父节点为祖父节点
int find_compress_halves(int index, int* parent){
    while(index!=parent[index]){
        parent[index]=parent[parent[index]];
        index=parent[index];
    }
    return index;
}

// 合并两棵树，三种方法
// quick union 快速合并，直接挂接树的根节点，树增高，查找时间多
void unionset_qu(int root1, int root2, int* parent, int v){
    parent[root2]=root1;
}
// quick find 快速查找，子树所有点的父节点都变为index1，树高度保持为2，查找时间少
void unionset_qf(int root1, int root2, int* parent, int v){
    for(int i=0; i<v; i++){
        if(parent[i]==root2){
            parent[i]=root1;
        }
    }
}
// 优化
void unionset_rank(int root1, int root2, int* parent, int v, int* rank){
    if(rank[root1]>rank[root2]){
        parent[root2]=root1;
    }
    else if(rank[root1]<rank[root2]){
        parent[root1]=root2;
    }
    else{
        parent[root2]=root1;
        rank[root1]++;
    }
    return;
}

int main(){
    int v,e; // 顶点和边
    cin>>v>>e;
    int* parent=new int[v];
    int* rank=new int[v];
    for(int i=0; i<v;i++){
        parent[i]=i; // 初始化，根节点为自身
        rank[i]=1;
    }
    
    // 判断两个点是否在连通
    // for(int i=0; i<e; i++){
    //     int v1,v2;
    //     cin>>v1>>v2;
    //     int root1,root2;
    //     root1=find_compress_split(v1,parent);
    //     root2=find_compress_split(v2,parent);
    //     // unionset_qu(root1,root2,parent,v);
    //     unionset_rank(root1,root2,parent,v,rank);
    // }
    // int n;
    // cin>>n;
    // for(int i=0; i<n;i++){
    //     int v1,v2;
    //     cin>>v1>>v2;
    //     if(find_compress_split(v1,parent)==find_compress_split(v2,parent)){
    //         cout<<"true";
    //     }
    //     else{
    //         cout<<"false";
    //     }
    //     cout<<endl;
    // }

    // 最小生成树
    // 边集，按从小到大排列
    vector<vector<int>>edges;
    edges.resize(e);
    int cnt=0;
    for(int i=0; i<e; i++){
        int v1,v2,weight;
        cin>>v1>>v2>>weight;
        vector<int>edge={weight,v1,v2};
        int j=0;
        // 排序
        while(j<cnt && edges[j][0]<weight){
            j++;
        }
        int k=cnt;
        while(k>j){
            edges[k]=edges[k-1];
            k--;
        }
        edges[j]=edge;
        cnt++;
    }
    // 遍历边集选择路径
    int s=0;
    vector<vector<int>>res_edges;
    for(int i=0; i<e; i++){
        int root1=find_compress_halves(edges[i][1],parent);
        int root2=find_compress_halves(edges[i][2],parent);
        if(root1!=root2){
            unionset_rank(root1,root2,parent,v,rank);
            s+=edges[i][0];
            res_edges.push_back(edges[i]);
        }
    }
    cout<<s<<endl;
    for(int i=0; i<res_edges.size(); i++){
        cout<<res_edges[i][0]<<" ";
    }
}