// 请判断输入的整数序列是否为堆。
// 如果为最大堆，请输出“max ”以及整理后的最小堆，整数序列数字之间有空格，最后无空格。
// 如果为最小堆，请输出“min ” 以及整理后的最大堆，整数序列数字之间有空格，最后无空格。
// 如果不为堆，请输出整理后的最大堆，整数序列数字之间有空格，最后无空格。
// 如果既是最大堆也是最小堆，请只输出“max min ”

#include <iostream>
using namespace std;

bool maxHeap(int* array, int n){
    for(int i=n/2; i>=1; i--){
        if(n%2==0 && i==n/2){
            if(array[i]<array[i*2]){
                return false;
            }
        }
        else{
            if(array[i]<array[i*2] || array[i]<array[i*2+1]){
                return false;
            }
        }
    }
    return true;
}

bool minHeap(int* array, int n){
    for(int i=n/2; i>=1; i--){
        if(n%2==0 && i==n/2){
            if(array[i]>array[i*2]){
                return false;
            }
        }
        else{
            if(array[i]>array[i*2] || array[i]>array[i*2+1]){
                return false;
            }
        }
    }
    return true;
}

int* buildMaxHeap(int* array, int n){
    for(int i=n/2; i>=1; i--){
        if(n%2==0 && i==n/2){
            if(array[i]<array[i*2]){
                int temp=array[i*2];
                array[i*2]=array[i];
                array[i]=temp;
            }
        }
        else{
            // 注意降维到满足条件为止
            int j=i;
            while((j*2<=n && array[j]<array[j*2]) || (j*2+1<=n && array[j]<array[j*2+1])){
                if(array[j*2]>array[j*2+1]){
                    int temp=array[j*2];
                    array[j*2]=array[j];
                    array[j]=temp;
                    j=j*2;
                }
                // 两个相等子节点情况下，整理过程中，父节点下沉时，选择右沉。
                else{
                    int temp=array[j*2+1];
                    array[j*2+1]=array[j];
                    array[j]=temp;
                    j=j*2+1;
                }
            }
        }
    }
    return array;
}

int* buildMinHeap(int* array, int n){
    for(int i=n/2; i>=1; i--){
        if(n%2==0 && i==n/2){
            if(array[i]>array[i*2]){
                int temp=array[i*2];
                array[i*2]=array[i];
                array[i]=temp;
            }
        }
        else{
            // 注意降维到满足条件为止
            int j=i;
            while((j*2<=n && array[j]>array[j*2]) || (j*2+1<=n && array[j]>array[j*2+1])){
                if(array[j*2]<array[j*2+1]){
                    int temp=array[j*2];
                    array[j*2]=array[j];
                    array[j]=temp;
                    j=j*2;
                }
                else{
                    int temp=array[j*2+1];
                    array[j*2+1]=array[j];
                    array[j]=temp;
                    j=j*2+1;
                }
            }
        }
    }
    return array;
}

void print(int* array, int n){
    for(int i=1; i<=n; i++){
        if(i!=n){
            cout<<array[i]<<" ";
        }
        else{
            cout<<array[i];
        }
    }
}

int main(){
    int n;
    cin>>n;
    int* array=new int[n+1];
    for(int i=1; i<=n; i++){
        int a;
        cin>>a;
        array[i]=a;
    }
    bool isMax=maxHeap(array,n);
    bool isMin=minHeap(array,n);
    if(isMax==true && isMin==true){
        cout<<"max min ";
    }
    else if(isMax==true && isMin==false){
        cout<<"max ";
        buildMinHeap(array,n);
        print(array,n);
    }
    else if(isMax==false && isMin==true){
        cout<<"min ";
        buildMaxHeap(array,n);
        print(array,n);
    }
    else{
        buildMaxHeap(array,n);
        print(array,n);
    }

}