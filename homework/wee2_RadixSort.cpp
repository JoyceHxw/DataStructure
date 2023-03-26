// 根据输入，输出基数排序的每趟排序结果。
// 输入格式：输入数字为正整数，先输入排序数字个数，然后输入需要排序的数字序列。
// 输出格式：每趟排序结果。行尾无空格。
// 要求：程序需要实现排序，其他可以使用STL包。

// 按个、十、百...位排序

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    int num;
    cin>>num;
    int arr[num];
    int max_cnt=0;
    // 获取数组并求最大位数
    for (int i=0; i<num; i++) {
        int number;
        cin>>number;
        arr[i]=number;
        int cnt=0;
        while (number!=0) {
            number=number/10;  //整数除以整数得整数
            cnt++;
        }
        max_cnt=max(max_cnt,cnt);
    }
    // cout<<max_cnt;

    // 按位进行排序
    for (int i=1; i<=max_cnt; i++) {
        int stack[num]={0};
        // 获取各个位上的数
        int tens=pow(10,i-1);
        for (int j=0; j<num; j++) {
            // cout<<"arr[j]="<<arr[j]<<"tens="<<tens<<endl;
            // cout<<(arr[j])/tens;
            char s_number=to_string((arr[j])/tens).back(); //取最后一位
            int number1=((int) s_number)-48; //强转要减'0'--48
            stack[j]=number1;
            // cout<<number1;
        }
        // 冒泡排序
        for (int k=0;k<num-1; k++) {
            for (int m=0; m<num-1-k; m++) {
                // cout<<stack[m];
                if(stack[m]>stack[m+1]) {
                    int temp1=arr[m];
                    arr[m]=arr[m+1];
                    arr[m+1]=temp1;
                    int temp2=stack[m];
                    stack[m]=stack[m+1];
                    stack[m+1]=temp2;

                }
            }
        }
        // cout<<arr[1];
        // 输出
        for (int n=0; n<num; n++) {
            if (n!=num-1){
                cout<<arr[n]<<" ";
            }
            else {
                cout<<arr[n];
            }
        }
        cout<<endl;
    }

}