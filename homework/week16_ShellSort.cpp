#include <iostream>
using namespace std;


void shellSort(int* array, int n){
    int d=n/2;
    while(d>0){
        int k=0;
        while(k<d){
            int i=k+d;
            for(int i=k+d; i<n; i+=d){
                int j=k;
                while(j<i && array[j]<=array[i]){
                    j+=d;
                }
                if(j<i){
                    int temp=array[i];
                    int m=i;
                    while(m>j){
                        array[m]=array[m-d];
                        m-=d;
                    }
                    array[j]=temp;
                }
            }
            k++;
        }
        d/=2;
        for(int i=0;i<n;i++){
            cout<<array[i]<<" ";
        }
        cout<<endl;
    }
}


int main(){
    int n;
    cin>>n;
    int array[n];
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        array[i]=a;
    }

    // int d=0;
    // bool isFlag=false;
    // while(!isFlag){
    //     d+=1;
    //     isFlag=true;
    //     int k=0;
    //     while(k<d){
    //         int i=k;
    //         while(i+d<n){
    //             if(array[i]>array[i+d]){
    //                 isFlag=false;
    //                 break;
    //             }
    //             i+=d;
    //         }
    //         k++;
    //     }
    // }
    // cout<<d;

    shellSort(array,n);
}