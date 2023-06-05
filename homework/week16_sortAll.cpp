#include <iostream>
using namespace std;

void swap(int& a, int& b){
    int temp=b;
    b=a;
    a=temp;
}

// 冒泡排序
void bubbleSort(int* array, int n){
    for(int i=0; i<n-1; i++){
        for(int j=1; j<=n-i-1; j++){
            if(array[j]<array[j-1]){
                swap(array[j],array[j-1]);
            }
        }
    }
}

// 选择排序
void selectSort(int* array, int n){
    for(int i=0; i<n-1; i++){
        int min_pos=i;
        for(int j=i+1; j<n; j++){
            if(array[j]<array[min_pos]){
                min_pos=j;
            }
        }
        swap(array[i],array[min_pos]);
    }
}

// 插入排序
void insertSort(int* array, int n){
    for(int i=1; i<n; i++){
        int j=i;
        int temp=array[i];
        while(j>=0 && array[j-1]>temp){
            array[j]=array[j-1];
            j--;
        }
        array[j]=temp;
    }
}

// 希尔排序
void shellSort(int* array, int n){
    int d=n/2;
    while(d>0){
        int k=0;
        while(k<d){
            for(int i=k+d; i<n; i+=d){
                int j=i;
                int temp=array[i];
                while(j>=k && array[j-d]>temp){
                    array[j]=array[j-d];
                    j-=d;
                }
                array[j]=temp;
            }
            k++;
        }
        d=d/2;
    }
}

// 归并排序
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

void mergeSort(int* array, int start, int n){
    if(n/2==0){
        return;
    }
    mergeSort(array,start,n/2);
    mergeSort(array,start+n/2,n-n/2);
    merge(array,start,start+n/2,n/2,n-n/2);
    return;
}

// 快速排序
int partition(int* array, int lo, int hi){
    swap(array[lo],array[lo+rand()%(hi-lo+1)]); // 随机交换
    int pivot=array[lo];
    while(lo<hi){
        while(lo<hi && pivot<=array[hi]){
            hi--;
        }
        swap(array[lo],array[hi]);
        while(lo<hi && array[lo]<=pivot){
            lo++;
        }
        swap(array[lo],array[hi]);
    }
    return lo;
}

void quickSort(int* array, int lo, int hi){
    if(lo>=hi){
        return;
    }
    int pivot_pos=partition(array,lo,hi);
    quickSort(array,lo,pivot_pos-1);
    quickSort(array,pivot_pos+1,hi);
    for(int i=0; i<9; i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int array[]={2,5,3,7,8,6,1,9,4};
    // bubbleSort(array,9);
    // selectSort(array,9);
    // insertSort(array,9);
    quickSort(array,0,8);
    for(int i=0; i<9; i++){
        cout<<array[i]<<" ";
    }
}