#include <iostream>
using namespace std;

// 插入排序
void insertSort(int* array,int n, int* current){
    bool isPrint=false;
    for(int i=1; i<n; i++){
        int j=0;
        while(j<i && array[j]<=array[i]){
            j++;
        }
        if(j<i){
            int temp=array[i];
            int k=i;
            while(k>j){
                array[k]=array[k-1];
                k--;
            }
            array[j]=temp;
        }

        bool isFlag=true;
        for(int m=0; m<n; m++){
            if(array[m]!=current[m]){
                isFlag=false;
                break;
            }
        }
        if(isPrint==true){
            for(int m=0; m<n; m++){
                if(m==0){
                    cout<<array[m];
                }
                else{
                    cout<<" "<<array[m];
                }
            }
            break;
        }
        if(isFlag==true){
            cout<<"Insertion Sort"<<endl;
            isPrint=true;
        }
    }
}

// 合并
void merge(int* array, int start1, int start2, int m, int n){
    int temp[m+n];
    int p1=0;
    int p2=0;
    int i=0;

    while(p1<m || p2<n){
        if((p1<m && p2>=n) || (p1<m && p2<n && array[p1+start1]<array[p2+start2])){
            temp[i]=array[p1+start1];
            p1++;
        }
        else{
            temp[i]=array[p2+start2];
            p2++;
        }
        i++;
    }

    for(int i=0; i<m+n; i++){
        array[start1+i]=temp[i];
    }
}

// 归并排序（深度优先遍历，不是同一大小的组先排，是同一边先排再拍另一边）
// void mergeSort(int* array, int start, int n, int array_n){
//     if(n/2==0){
//         return;
//     }
//     mergeSort(array,start,n/2,array_n);
//     mergeSort(array,start+n/2,n-n/2,array_n);
//     merge(array,start,start+n/2,n/2,n-n/2);
//     for(int i=0; i<array_n; i++){
//         cout<<array[i]<<" ";
//     }
//     cout<<endl;
//     return;
// }

// 合并相邻组
void mergeSort(int* array, int n, int* current){
    int i=0;
    int d=1;
    bool isPrint=false;
    while(i+d<n){
        bool isFlag=true;
        while(i+d<n){
            if(n>=i+2*d){
                merge(array,i,i+d,d,d);
            }
            else{
                merge(array,i,i+d,d,n-d);
            }
            i+=2*d;
        }
        for(int j=0; j<n; j++){
            if(array[j]!=current[j]){
                isFlag=false;
                break;
            }
        }
        if(isPrint==true){
            for(int j=0; j<n; j++){
                if(j==0){
                    cout<<array[j];
                }
                else{
                    cout<<" "<<array[j];
                }
            }
            break;
        }
        if(isFlag==true){
            cout<<"Merge Sort"<<endl;
            isPrint=true;
        }

        i=0;
        d*=2;
    }
}

int main(){
    int n;
    cin>>n;
    int array1[n];
    int array2[n];
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        array1[i]=a;
        array2[i]=a;
    }
    int current[n];
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        current[i]=a;
    }
    insertSort(array1,n,current);
    // mergeSort(array1,0,n,n);
    mergeSort(array2,n,current);
}