#include <iostream>
using namespace std;

template<class T>
class diagonalMatrix
{
public:
    diagonalMatrix(int theN=10);
    ~diagonalMatrix(){
        delete[] element;
    }
    T get(int, int) const;
    void set(int, int, const T&);
private:
    int n;
    T* element;
};

template<class T>
diagonalMatrix<T>::diagonalMatrix(int theN){
    if(theN<1){
        throw 1;
    }
    n=theN;
    element=new T[n];
}

template<class T>
T diagonalMatrix<T>::get(int i,int j) const{
    if(i<1 || j<1 || i>n || j>n){
        throw 1;
    }
    if(i==j){
        return element[i-1];
    }
    else{
        return 0;
    }
}

template<class T>
void diagonalMatrix<T>::set(int i, int j, const T& newValue){
    if(i<1 || j<1 || i>n || j>n){
        throw 1;
    }
    if(i==j){
        element[i-1]=newValue;
    }
    else{
        if (newValue!=0){
            throw 1;
        }
    }
}

int main(){

}