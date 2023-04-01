#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        // 我的解答：双指针
        // int left=0;
        // int right=0;
        // int i=0;
        // int len;
        // while(i<s.length()){
        //     if(s[i]!=' '){
        //         i++;
        //         right=i;
        //         if(right>left){
        //             len=right-left;
        //         }
        //     }
        //     else{
        //         i++;
        //         left=i;
        //     }
        //     cout<<"left="<<left<<endl;
        // } 
        // return len;

        // 答案：反向遍历
        int index = s.size() - 1;
        while (s[index] == ' ') {
            index--;
        }
        int wordLength = 0;
        while (index >= 0 && s[index] != ' ') {
            wordLength++;
            index--;
        }

        return wordLength;

    }
};