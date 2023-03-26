// 给定一个非最简的Linux文件绝对路径，将其简化为标准的Linux文件绝对路径。
// 在Linux文件路径中，一个英文句号 . 表示当前目录，两个连续的英文句号 .. 表示返回到上一级目录。
// 标准的Linux文件绝对路径具有以下特点
// 第一个字符为斜杠 /
// 两个目录名称直接有且仅有一个斜杠 /
// 除根目录外，路径结尾不能为斜杠 
// 不会出现一个英文句号 . 或者两个连续的英文句号 ..

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin>>str;
    char * stack = new char[str.length()+1];
    stack[0]='/';
    int j=1;
    for(int i=0; i<str.length(); i++) {
        if (str[i]!='.' && str[i]!='/'){
            stack[j]=str[i];
            j++;
            stack[j]='\0';
            cout<<"first"<<stack<<endl;
            cout<<"j="<<j<<endl;
        }
        else if(str[i]=='/' && stack[j-1]!='/'){
            stack[j]=str[i];
            j++;
            stack[j]='\0';
            cout<<"second"<<stack<<endl;
            cout<<"j="<<j<<endl;
        }
        else if(str[i]=='.' && str[i+1]=='.'){
            if (j>1){
                bool isFlag=false;
                while(stack[j-1]!='/' || isFlag==false){
                    if (stack[j-1]=='/'){
                        isFlag=true;
                    }
                    j--;
                    cout<<"j="<<j<<endl;
                    stack[j]='\0';
                    cout<<"third"<<stack<<endl;
                }
            }
        }
    }
    if (j>1 && stack[j-1]=='/'){
        stack[j-1]='\0';
        cout<<stack<<endl;
    }
    else{
        stack[j]='\0';
        cout<<stack<<endl;
    }
}