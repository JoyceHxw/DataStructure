#include <iostream>
using namespace std;
#include <cstring>

// 在208基础字典树上加dfs回溯
// 自己成功写出来了，掌握字典树
class WordDictionary {
public:
    // 字典树
    bool isEnd;
    WordDictionary* next[26];

    WordDictionary() {
        isEnd=false;
        memset(next,0,sizeof(next));
    }
    
    void addWord(string word) {
        WordDictionary* node=this;
        for(char c: word){
            if(node->next[c-'a']==nullptr){
                node->next[c-'a']=new WordDictionary;
            }
            node=node->next[c-'a'];
        }
        node->isEnd=true;
    }
    
    bool search(string word) {
        WordDictionary* node=this;
        return dfs(word,0,node);
    }
    // dfs搜索
    bool dfs(string& word,int i,WordDictionary* node){
        if(node==nullptr ){
            return false;
        }
        if(i==word.length()){
            return node->isEnd;
        }
        if(word[i]=='.'){
            WordDictionary* temp=node;
            bool isFlag=false;
            for(int j=0; j<26; j++){
                node=node->next[j];
                isFlag |= dfs(word,i+1,node);
                node=temp;
            }
            return isFlag;
        }
        else{
            node=node->next[word[i]-'a'];
            return dfs(word,i+1,node);
        }
    }
};
