// 给定一个主串S和子串P，使用KMP算法查找子串P在主串S中存在的位置，若子串P在主串S中存在，则输出与子串P中第一字符相等的字符在主串S中的序号；若不存在则输出“no”
#include <iostream>
using namespace std;
#include <windows.h>

int * nextBuild(string p){
    int i=1;
    int j=0;
    int len_p=p.length();
    int *next=new int[len_p];
    next[0]=-1;
    next[1]=0;
    while(i<len_p){
        if(j==-1 || p[i]==p[j]){
            j++;
            i++;
            next[i]=j;
        }
        else{
            j=next[j];
        }
    }
    // for(int i=0; i<len_p; i++){
    //     cout<<next[i];
    // }
    return next;
}

void KPM(string s, string p){
    int * next=nextBuild(p);
    int i=0;
    int j=0;
    int len_s=s.length();
    int len_p=p.length();
    int compare_cnt=0;
    while (j<len_p && i<len_s){
        if(j==-1 || s[i]==p[j]){
            i++;
            j++;
            compare_cnt+=1;
        }
        else{
            compare_cnt+=1;
            j=next[j];
        }
    }
    if(j<len_p-1){
        cout<<"no";
        cout<<"KMP算法比较次数"<<compare_cnt<<endl;
    }
    else{
        cout<<(i-len_p)<<endl;
        cout<<"KMP算法比较次数"<<compare_cnt<<endl;
    }
}

int main(){
    // string s;
    // string p;
    // cin>>s>>p;
    string p="vwxyz{|}~ !\"#$%&'()*+,-./0123456789:;<=>?abcdefghijklmnopqrstuvwxyz{|}~%&'()*+,-./0123456789:;@ABCDEFGHIJK0123456789:;LMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
    string s="hduwji9236djcnklsmci !\"#$%&'()*+,-./0123456789:;vwxyz{|}~ !\"#$%&'()*+,-./9876543210:;<=>?abcdefghijklmnopqrstuvwxyz{|}~%&'()*+,-./0123456789:;@ABCDEFGHIJK0123456789:;LMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~vwxyz{|}~ !\"#$%&'()*+,-./0123456789:;vwxyz{|}~ !\"#$%&'()*+,-./0123456789:;<=>?djdhsenejkisdbhbwk0123893242;vwxyz{|}~ !\"#$%&'()*+,-./9876543210:;<=>?abcdefghijklmnopqrstuvwxyz{|}~%&'()*+,-./0123456789:;@ABCDEFGHIJK0123456789:;LMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~vwxyz{|}~vwxyz{|}~3837362cj`=w !\"#$%&'()*+,-.OPQRSTUVWXYZ[\\]vwxyz{|}~^_`abcdefghijklmnopqrstuvwxyz{|}~ !\"#$%&'()*+,-./0123456789:@ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz{|}~ !\"#$%&'()*+,-./0123456789:;<=>?abcdefghijklmnopqrstuvwxyz{|}~%&'()*+,-./0123456789:;@ABCDEFGHIJK0123456789:;LMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~abcdefghijklmnopqrstuvwxyz";

    // 计时
    LARGE_INTEGER t1, t2, tc;
    QueryPerformanceFrequency(&tc);
    QueryPerformanceCounter(&t1);
    KPM(s,p);
    QueryPerformanceCounter(&t2);
    cout << "KMP算法用时（ms）" << (t2.QuadPart - t1.QuadPart)*1000000 / tc.QuadPart << endl;
}