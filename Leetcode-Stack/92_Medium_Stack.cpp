#include <iostream>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // 我的方法：栈（遍历两次中间部分，占用额外空间）
        // int index=1;
        // ListNode* ans=new ListNode;
        // ans->next=head;
        // ListNode* parent=ans;
        // while(head!=nullptr){
        //     if(index+1==left){
        //         parent=head;
        //         break;
        //     }
        //     index++;
        //     head=head->next;
        // }
        // if(head==nullptr){
        //     head=ans;
        //     index=0;
        // }
        // head=head->next;
        // index++;
        // stack<ListNode*> stk;
        // while(index!=right){
        //     stk.push(head);
        //     head=head->next;
        //     index++;
        // }
        // stk.push(head);
        // head=head->next;
        // while(!stk.empty()){
        //     ListNode* node=stk.top();
        //     stk.pop();
        //     parent->next=node;
        //     parent=parent->next;
        // }
        // parent->next=head;
        // return ans->next;

        // 答案：穿针引线（链表操作）
        // 逐个将下一个节点移到最前面
        ListNode* ans=new ListNode;
        ans->next=head;
        ListNode* parent=ans;
        for(int i=0; i<left-1; i++){
            parent=parent->next;
        }
        ListNode* current=parent->next;
        ListNode* nextnode;
        for(int i=0; i<right-left; i++){
            nextnode=current->next;
            current->next=nextnode->next;
            nextnode->next=parent->next;  //注意是parent->next不是current，因为parent位置不变
            parent->next=nextnode;
        }
        return ans->next;
    }
};