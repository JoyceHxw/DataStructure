#include <iostream>
using namespace std;
#include <vector>

template<class T>
class matrixTerm
{
public:
    // matrixTerm(int r, int c, T v){
    //     if(r>0 && c>0){
    //         row=r;
    //         col=c;
    //         value=v;
    //     }
    //     else{
    //         throw 1;
    //     }
    // };
    int row;
    int col;
    T value;
};

template<class T>
class sparseMatrix
{
    // 友元类外实现
    template<class T1>
    friend ostream& operator<<(ostream& cout, sparseMatrix<T1>& x);
    template<class T2>
    friend istream& operator>>(istream& cin, sparseMatrix<T2>& x);
public:
    void transpose(sparseMatrix<T>& b);
    void add(sparseMatrix<T>& b, sparseMatrix<T> &c);
private:
    int rows,cols;
    vector<matrixTerm<T>> terms;
};

// 只能利用全局函数重载左移运算符
template<class T>
ostream& operator<<(ostream& cout, sparseMatrix<T>& x){
    cout<<"rows="<<x.rows<<" columns="<<x.cols<<endl;
    cout<<"nonzero terms="<<x.terms.size()<<endl;
    for(typename::std::vector<matrixTerm<T>>:: iterator it=x.terms.begin(); it!=x.terms.end(); it++){
        cout<<"a("<<(*it).row<<","<<(*it).col<<")="<<(*it).value<<endl;
    }
    return cout;
}

template<class T>
istream& operator>>(istream& cin, sparseMatrix<T>& x){
    int numberOfTerms;
    cout<<"Enter number of rows, columns, and #terms"<<endl;
    cin>>x.rows>>x.cols>>numberOfTerms;
    // x.terms.resize(numberOfTerms);  //vector动态空间不需要resize
    
    matrixTerm<T> mTerm;
    for(int i=0; i<numberOfTerms; i++){
        int a=i+1;
        cout<<"Enter row, column, and value of term"<<a<<endl;
        cin>>mTerm.row>>mTerm.col>>mTerm.value;
        x.terms.push_back(mTerm);
        cout<<x.terms.size();
    }
    return cin;
}

template<class T>
void sparseMatrix<T>:: transpose(sparseMatrix<T>& b){
    b.cols=rows;
    b.rows=cols;
    // b.terms.resize(terms.size());
    int* colSize=new int[cols+1];
    int* rowNext=new int[cols+1];

    // 每一列元素个数的哈希表
    // 初始化
    for(int i=1; i<=cols; i++){
        colSize[i]=0;
    }
    for(typename::std::vector<matrixTerm<T> >::iterator i=terms.begin(); i!=terms.end(); i++){
        colSize[(*i).col]++;
    }

    // 每一行的起始点
    rowNext[1]=0;
    for(int i=2; i<=cols; i++){
        rowNext[i]=rowNext[i-1]+colSize[i-1];
    }

    // 实施从*this到b的转置复制
    matrixTerm<T> mTerm;
    for(typename::std::vector<matrixTerm<T> >::iterator i=terms.begin(); i!=terms.end(); i++){
        int j=rowNext[(*i).col]++;
        mTerm.row=(*i).col;
        mTerm.col=(*i).row;
        mTerm.value=(*i).value;
        b.terms.push_back(mTerm);
    }
}

template<class T>
void sparseMatrix<T>:: add(sparseMatrix<T>& b, sparseMatrix<T>& c){
    if(rows!=b.rows || cols!=b.cols){
        throw 1;
    }
    // 结果矩阵c
    c.rows=rows;
    c.cols=cols;
    c.terms.clear();
    int cSize=0;

    typename::std::vector<matrixTerm<T> >::iterator it=terms.begin();
    typename::std::vector<matrixTerm<T> >::iterator ib=b.terms.begin();
    typename::std::vector<matrixTerm<T> >::iterator itEnd=terms.end();
    typename::std::vector<matrixTerm<T> >::iterator ibEnd=b.terms.end();

    while(it!=itEnd && ib!=ibEnd){
        int tIndex=(*it).row*cols+(*it).col;
        int bIndex=(*ib).row*cols+(*ib).col;

        if(tIndex<bIndex){
            c.terms.insert(cSize++, *it);
            it++;
        }
        else{
            if(tIndex==bIndex){
                if((*it).value+(*ib).value!=0){
                    matrixTerm<T> mTerm;
                    mTerm.row=(*it).row;
                    mTerm.col=(*it).col;
                    mTerm.value=(*it).value+(*ib).value;
                    c.terms.insert(cSize++, mTerm);
                }
                it++;
                ib++;
            }
            else{
                c.terms.insert(cSize++, *ib);
                ib++;
            }
        }
        // 复制剩余项
        for(;it!=itEnd; it++){
            c.terms.insert(cSize++, *it);
        }
        for(;ib!=ibEnd; ib++){
            c.terms.insert(cSize++, *ib);
        }
    }
}

int main(){
    sparseMatrix<int> sm;
    cin>>sm;
    cout<<sm;

    sparseMatrix<int> sm2;
    sm.transpose(sm2);
    cout<<sm2;

}