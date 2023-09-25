#include <iostream>
using namespace std;
#include <unordered_map>
#include <list>


//146LFU的进阶版，基于原有思路，增加频率哈希表，采用list结构

struct Node {
    int key;
    int value;
    int freq;
    Node(int _key, int _value, int _freq): key(_key), value(_value), freq(_freq){}
};

//既要考虑最近使用，还要考虑频率
//两个哈希表+链表
//一个哈希表存放键和节点
//另一个存放频率和链表
//利用list结构
class LFUCache {
public:
    unordered_map<int,Node*> m1;
    unordered_map<int,list<Node*>> m2;
    int min_freq;
    int size;
    int capacity;
    LFUCache(int capacity) {
        this->capacity=capacity;
        min_freq=0;
        size=0;
    }
    
    int get(int key) {
        if(m1.find(key)==m1.end()){
            return -1;
        }
        Node* node=m1[key];
        int node_value=node->value;
        //频率增加，先从原链表删除，再头插新的链表
        int node_freq=node->freq;
        m2[node_freq].remove(node);
        //删除空链表，更新最低频率
        if(m2[node_freq].size()==0){
            m2.erase(node_freq);
            if(min_freq==node_freq){
                min_freq+=1;
            }
        }
        Node* new_node=new Node(key,node_value,node_freq+1);
        m2[node_freq+1].push_front(new_node);
        m1[key]=new_node;
        return node_value;
    }
    
    void put(int key, int value) {
        //新增节点
        if(m1.find(key)==m1.end()){
            //缓存已满
            if(size==capacity){
                //删除最低频率的末节点
                Node* node_last=m2[min_freq].back();
                m1.erase(node_last->key);
                m2[min_freq].pop_back();
                if(m2[min_freq].size()==0){
                    m2.erase(min_freq);
                }
                size--;
            }
            Node* new_node=new Node(key,value,1);
            m2[1].push_front(new_node);
            m1[key]=new_node;
            min_freq=1;
            size++;
        }
        //修改现有节点
        else{
            Node* node=m1[key];
            int node_freq=node->freq;
            m2[node_freq].remove(node);
            if(m2[node_freq].size()==0){
                m2.erase(node_freq);
                if(min_freq==node_freq){
                    min_freq+=1;
                }
            }
            Node* new_node=new Node(key,value,node_freq+1);
            m2[node_freq+1].push_front(new_node);
            m1[key]=new_node;
        }
    }
};

