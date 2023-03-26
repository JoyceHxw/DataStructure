// 给定一个仅含有英文大小写字母的字符串序列 s，若其中任意两个相邻字符都不是同一个字母的大小写形式，则称其为互斥字符串。
// 程序需要将给定的字符串转换为互斥字符串。aa为互斥，aA和Aa为非互斥。
// 程序的每次操作可以从字符串中选出满足上述条件的两个相邻字符并删除，直到字符串整理好为止。
#include <iostream>
#include <string>
using namespace std;

bool isSame(char a, char b){
    return abs(a-b)==abs('A'-'a');
}

int main(){
    string str;
    cin>>str;
    char * stack = new char[str.length()+1];
    int pos=0;
    for (int i=0;i<str.length();i++) {
        // cout<<"i="<<i;
        // cout<<"pos="<<pos;
        // cout<<stack[pos-1]<<endl;  //栈的栈顶，最后一个
        //比较栈的最后一个和字符串的第i个，互斥则入栈
        if (pos && isSame(stack[pos-1],str[i])) {
            pos--;
        }
        else {
            stack[pos++]=str[i];
        }
    }
    if (pos) {
        stack[pos]='\0';
        cout<<stack<<endl;
    }
    else {
        cout<<-1<<endl;
    }
    
}