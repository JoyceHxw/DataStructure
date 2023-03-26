// BM算法
// 坏字符规则（Bad Character)：从右往左匹配，找到主字符串中第一个不匹配的字符，即为坏字符，
    // 将模式字符串右移到模式字符串出现与主字符串坏字符对齐的字符，再从右往左找坏字符，
    // 如果模式字符串中没有该坏字符，则直接移到该坏字符的下一位即可，
    // 如果模式字符串中该字符位于坏字符右侧，模式字符串右移一个位置
// 好后缀规则（Good Suffix）：从右往左匹配，找到坏字符，主字符串中坏字符右边的字符串即为好后缀（匹配），
    // 再往坏字符左边找模式字符串中是否还有该好后缀，如果有，将模式字符串右移到与好后缀对齐，
    // 如果模式字符串没有该好后缀，则右移到好后缀的后一位的位置
    // 但是当模式串滑动到前缀与主 串中{u}的后缀有部分重合的时候，并且重合的部分相等的时候，就有可能会存在完全匹配 的情况。
// 我们可以分别计算好后缀和坏字符往后滑动的位数，然后取两个数中最大的，作为模式串往 后滑动的位数。这种处理方法还可以避免我们前面提到的，根据坏字符规则，计算得到的往 后滑动的位数，有可能是负数的情况。

// 给定一个主串S和子串P，使用KMP算法查找子串P在主串S中存在的位置，若子串P在主串S中存在，则输出与子串P中第一字符相等的字符在主串S中的序号；若不存在则输出“no”
// ababcabcacbab abcac 5

#include <iostream>
using namespace std;
#include <windows.h>

// 构建BC哈希表（出现的所有字符的最右边的位置）
int* buildBC(string P){
    int* bc= new int[256];
    for(int i=0; i<256; i++){
        bc[i]=-1; // 初始化
    }
    for(int i=0; i<P.length(); i++){
        bc[P[i]]=i;  // 字符最后出现的位置
    }
    return bc;
}

// 构建GS哈希表
// 所有长度的后缀字符串的相同字符串及其是否是前缀字符串
// 这样来根据好后缀规则判断移动距离不是最高效的
// 下标         0 1 2 3 4 5 6 7 8
// P            1 0 1 0 1 1 0 1 0
// 该算法下的GS  5 5 5 5 5 5 2 1 1
// 最优的GS      5 5 5 5 5 7 2 9 1
// 因为该算法仅考虑最右的与好后缀相匹配的字符串,没有考虑坏字符的信息
// 即匹配的字符串除了好后缀相匹配之外,坏字符那一位是不匹配的
// 比如当P[7]不匹配时，也说明要寻找的字符串应该为 (!1)0 ，观察发现P中并不存在这样的字符串，所以全部跳过
// 比如当P[5]不匹配时，也说明要存照的字符串应该为 (!1)010，观察发现并不存在，所以让长度为2的前后缀匹配
// void buildGS(string P, int* suffix, bool* prefix){
//     // 初始化
//     for(int i=0; i<P.length(); i++){
//         suffix[i]=-1;
//         prefix[i]=false;
//     }
//     for(int i=0; i<P.length()-1; i++){
//         int j=i;
//         int k=0; 
//         while(j>=0 && P[j]==P[P.length()-1-k]){
//             // cout<<"j="<<j<<endl;
//             j--;
//             k++;
//             suffix[k]=j+1;  //使得为最右的相同字符串
//         }
//         if(j==-1){
//             prefix[k]=true;
//         }
//     }

// }



// 采用蛮力算法求ss，再由ss推导gs
// ss为该下标前P字串中，与P后缀相匹配的最大后缀长度
// 最大后缀长度意味着, 下一位是一定不相等的, 使得移动是最高效的
// 下标：0 1 2 3 4 5 6 7 8
// P：   1 0 1 0 1 1 0 1 0
// SS：  0 2 0 4 0 0 2 0 9
// GS：  5 5 5 5 5 7 2 9 1
// 下标：0 1 2 3 4 5 6 7  8  9 10 11
// P：   1 1 0 1 1 1 0 1  1  0 1 1
// SS：  1 2 0 1 5 2 0 1  5  0 1 12
// GS：  7 7 7 7 7 7 3 10 10 6 1 2
int* buildGS(string P){
    int n=P.length();
    int* gs=new int[n];
    int* ss=new int[n];
    for(int i=0; i<n; i++){
        int k=0; //匹配前后缀长度
        for (int j=i; j>=0; j--){
            if(P[j]==P[n-1-k]){
                k++;
            }
            else{
                break;
            }
        }
        ss[i]=k;
        // cout<<k<<" ";
    }
    // 初始化gs
    for(int i=0; i<n; i++){
        gs[i]=n;
    }
    // 分两种情况:1.匹配字符串是P的前缀; 2.匹配字符串不是前缀,是子串的后缀
    // 先考虑第一种情况: 逆向遍历(画家算法)
    for(int i=0, j=n-1; i<n, j>=0; j--){
        if(ss[j]==j+1){
            while(i<n-j-1){
                gs[i]=n-j-1;
                i++;
            }
        }
    }
    // 第二种情况: 正向遍历(画家算法)
    for(int j=0; j<n-1; j++){
        gs[n-ss[j]-1]=n-j-1;
    }
    return gs;
}

void BM(string S, string P){
    int m=P.length();
    int n=S.length();
    int i=0;  //主串匹配起始位置
    int compare_cnt=0;
    int* BC=buildBC(P);
    int* GS=buildGS(P);
    while(i<n-m+1){
        // cout<<"i="<<i<<endl;
        int bc_step;
        int gs_step;
        int step;
        int j;  //模式串匹配起始位置
        for(j=m-1; j>=0; j--){
            if(S[i+j]!=P[j]){
                compare_cnt+=1;
                break;
            }
            compare_cnt+=1;
        }
        if(j==-1){
            // return i;
            cout<<i<<endl;
            cout<<"BM算法比较次数："<<compare_cnt<<endl;
            return;
        }
        else{
            // 算BC移动距离
            if(BC[S[i+j]]>j){
                bc_step=1;
            }
            else{
                bc_step=j-BC[S[i+j]];  //包括了不存在的情况，为-1，j-(-1)=j+1
            }
            // 算GS移动距离
            gs_step=GS[j];
            // cout<<"bc="<<bc_step<<endl;
            // cout<<"gs="<<gs_step<<endl;
            step=max(bc_step,gs_step);
            i+=step;
        }   
    }
    cout<<"no"<<endl;
    cout<<"BM算法比较次数："<<compare_cnt<<endl;
}

int main(){
    // string P;
    // string S;
    // cin>>S>>P;
    string P="vwxyz{|}~ !\"#$%&'()*+,-./0123456789:;<=>?abcdefghijklmnopqrstuvwxyz{|}~%&'()*+,-./0123456789:;@ABCDEFGHIJK0123456789:;LMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
    string S="hduwji9236djcnklsmci !\"#$%&'()*+,-./0123456789:;vwxyz{|}~ !\"#$%&'()*+,-./9876543210:;<=>?abcdefghijklmnopqrstuvwxyz{|}~%&'()*+,-./0123456789:;@ABCDEFGHIJK0123456789:;LMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~vwxyz{|}~ !\"#$%&'()*+,-./0123456789:;vwxyz{|}~ !\"#$%&'()*+,-./0123456789:;<=>?djdhsenejkisdbhbwk0123893242;vwxyz{|}~ !\"#$%&'()*+,-./9876543210:;<=>?abcdefghijklmnopqrstuvwxyz{|}~%&'()*+,-./0123456789:;@ABCDEFGHIJK0123456789:;LMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~vwxyz{|}~vwxyz{|}~3837362cj`=w !\"#$%&'()*+,-.OPQRSTUVWXYZ[\\]vwxyz{|}~^_`abcdefghijklmnopqrstuvwxyz{|}~ !\"#$%&'()*+,-./0123456789:@ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz{|}~ !\"#$%&'()*+,-./0123456789:;<=>?abcdefghijklmnopqrstuvwxyz{|}~%&'()*+,-./0123456789:;@ABCDEFGHIJK0123456789:;LMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~abcdefghijklmnopqrstuvwxyz";
    
    // 计时
    LARGE_INTEGER t1, t2, tc;
    QueryPerformanceFrequency(&tc);
    QueryPerformanceCounter(&t1);
    BM(S,P);
    QueryPerformanceCounter(&t2);
    cout << "BM算法用时（ms）" << (t2.QuadPart - t1.QuadPart)*1000000 / tc.QuadPart << endl;

}