// 给出一棵完全二叉树的先序遍历，输出其后序遍历。结点均为不重复的单个英文字母，区分大小写。结点总数小于52。

#include <iostream>
using namespace std;
#include <vector>

int i=0;
// 递归遍历先序字符串
void preorder(vector<char>& v, int index, string& str){
    if(index>str.length()){
        return;
    }
    v[index]=str[i];  //先根节点
    i++;
    preorder(v,index*2,str); //左子树，根据完全二叉树连续的特点 1，2，4，8，6
    preorder(v,index*2+1,str); //右子树 3，5，7，9
}

// 递归输出后序字符串
void postorder(vector<char>& v, int index, string& str){
    if(index>str.length()){
        return;
    }
    postorder(v,index*2,str);
    postorder(v,index*2+1,str);
    cout<<v[index];
}

int main(){
    string str;
    cin>>str;
    // 数组保存完全二叉树
    vector<char>v;
    // 从1开始编号
    v.resize(str.length()+1);
    preorder(v,1,str);
    for(int i=0; i<v.size(); i++){
        cout<<v[i];
    }
    cout<<endl;
    postorder(v,1,str);

}