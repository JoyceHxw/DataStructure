// 设计一个表达式求值的程序。该程序必须可以接受包含（，），+，-，*，/，%和^(求幂)的中缀表达式，并求出结果。如果表达式正确，则输出表达式的值，如果表达式非法，则输出错误信息。
// 注意2^2^3转为后缀应为223^^
// 操作数均转为double运算。
// 幂运算可以直接使用pow(a,b)
// %,操作数转为Int再进行计算。

// 对每个表达式，如果为正确表达式则输出结果（精确到小数点后两位），如果为错误表达式则输出“ERROR IN INFIX NOTATION”

#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
using namespace std;

double cal(double a, double b, char c){
    double result;
    if (c=='+'){
        result=a+b;
    }
    else if(c=='-'){
        result=a-b;
    }
    else if(c=='*'){
        result=a*b;
    }
    else if(c=='/'){
        result=a/b;
    }
    else if(c=='%'){
        result=int(a)%int(b);
    }
    else if(c=='^'){
        result=pow(a,b);
    }
    return result;
}

int level(char c){
    int k;
    if (c=='+' || c=='-'){
        k=1;
    }
    else if(c=='*' || c=='/' || c=='%'){
        k=2;
    }
    else if(c=='^'){
        k=3;
    }
    else{
        k=0;
    }
    return k;
}

int main(){
    string exp;
    cin>>exp;
    char oper[8]={'(',')','+','-','*','/','%','^'};
    int len=exp.length();
    // 符号栈和栈尾
    char stack_oper[len];
    int m=0;
    // 数字栈和栈尾
    double stack_double[len];
    int n=0;
    int start=0;
    int end=0;

    for (int i=0; i<len; i++){
        // cout<<i<<"********"<<endl;
        bool isOper=false;
        bool isNum=false;
        for (int j=0;j<8;j++){
            if (exp[i]==oper[j]){
                isOper=true;
                // 数字入栈
                end=i;
                if(end-start>0){
                    string str=exp.substr(start,end-start);
                    double d=stod(str);
                    stack_double[n]=d;
                    n++;
                }
                start=i+1;

                // cout<<"n="<<n<<endl;
                // for (int i=0; i<n; i++){
                //     cout<<stack_double[i]<<endl;
                // }
                // cout<<"m="<<m<<endl;
                // for (int i=0; i<m; i++){
                //     cout<<stack_oper[i]<<endl;
                // }
                
                // 符号入栈
                if (level(exp[i])>level(stack_oper[m-1]) || exp[i]=='(' || level(exp[i])==3 ){
                    // 符号入栈
                    stack_oper[m]=exp[i];
                    m++;
                }
                else if(exp[i]!=')'){
                    // 数字出栈，符号出栈，符号再入栈
                    while(level(exp[i])<=level(stack_oper[m-1])){
                        double result=cal(stack_double[n-2],stack_double[n-1],stack_oper[m-1]);
                        n-=2;
                        m-=1;
                        stack_double[n]=result;
                        n++;
                    }
                    stack_oper[m]=exp[i];
                    m++;
                }
                else if(exp[i]==')'){
                    // 数字出栈
                    while(stack_oper[m-1]!='(' && m>=1){
                        double result=cal(stack_double[n-2],stack_double[n-1],stack_oper[m-1]);
                        m-=1;
                        n-=2;
                        stack_double[n]=result;
                        n++;
                    }
                    m--;
                }
                break;
            }
        }
        if ((exp[i]>='0' && exp[i]<='9') || exp[i]=='.'){
            isNum=true;
        }
        if (isOper==false && isNum==false){
            goto FLAG;
        }
        // 最后一个数
        if(isOper==false && i==len-1){
            end=i+1;
            string str=exp.substr(start,end-start);
            double d=stod(str);
            stack_double[n]=d;
            n++;
        }
    }
    //计算出栈
    if (m!=n-1){
        FLAG:
        cout<<"ERROR IN INFIX NOTATION"<<endl;
    }
    else {
        while (m>0){
            double result=cal(stack_double[n-2],stack_double[n-1],stack_oper[m-1]);
            m-=1;
            n-=2;
            stack_double[n]=result;
            n++;
        }
        cout<<fixed<<setprecision(2)<<stack_double[n-1]<<endl;
    }
    
}
