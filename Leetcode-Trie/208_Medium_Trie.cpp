#include <iostream>
using namespace std;
#include <cstring>

// 掌握前缀树的概念和操作
class Trie {
public:
    bool isEnd;
    Trie* next[26];  // 只申明变量，没分配空间

    Trie() {
        isEnd=false;
        memset(next,0,sizeof(next));
    }
    
    void insert(string word) {
        Trie* node=this;
        for(char c: word){
            if(node->next[c-'a']==nullptr){
                node->next[c-'a']=new Trie();
            }
            node=node->next[c-'a'];
        }
        node->isEnd=true;
    }
    
    bool search(string word) {
        Trie* node=this;
        for(char c: word){
            node=node->next[c-'a'];
            if(node==nullptr){
                return false;
            }
        }
        // 结尾才能表示存在
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie* node=this;
        for(char c: prefix){
            node=node->next[c-'a'];
            if(node==nullptr){
                return false;
            }
        }
        // 不需要结尾
        return true;
    }
};
