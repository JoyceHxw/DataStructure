#include <iostream>
using namespace std;
#include <exception>

template <class T>
class matrix
{
public:
	// 构造/析构函数
	matrix(int theRows=0, int theColumns=0);  //参数构造
	matrix(const matrix<T>&);  //拷贝构造
	~matrix(){
		delete[] element;
	}
	// 在成员函数后面加const，修饰的是this指向，不可以修改指针指向值
	int rows()const{
		return theRows;
	}
	int columns()const{
		return theColumns;
	}
	// 重载运算符
	T& operator()(int i, int j) const;
	matrix<T>& operator=(const matrix<T>&);
	matrix<T> operator+() const;
	matrix<T> operator+(const matrix<T>&) const;
	matrix<T> operator-() const;
	matrix<T> operator-(const matrix<T>&) const;
	matrix<T> operator*(const matrix<T>&) const;
	matrix<T>& operator+=(const T&);

private:
	int theRows;
	int theColumns;
	T* element;
};

// 有参构造函数
template<class T>
matrix<T>::matrix(int theRows, int theColumns){
	// 检验行数和列数的有效性
	if(theRows<0 || theColumns <0){
		throw 1;
	}
	if((theRows==0 || theColumns==0) && (theRows!=0 || theColumns!=0)){
		throw 1;
	}
	// 创建矩阵
	this->theRows=theRows;
	this->theColumns=theColumns;
	element=new T[theRows*theColumns];
}

// 拷贝构造函数
template<class T>
matrix<T>::matrix(const matrix<T>& m){
	// 创建矩阵
	theRows=m.theRows;
	theColumns=m.theColumns;
	element=new T[theRows*theColumns];  //深拷贝

	// copy() 函数用于将容器 [first,last] 的所有元素从结果开始复制到不同的容器中
	// int arr[] = { 10, 20, 30, 40, 50 };
    // //向量声明
    // vector<int> v1(5);
    // //复制数组元素到向量
    // copy(arr, arr + 5, v1.begin());
	copy(m.element, m.element+theRows*theColumns, element);
}

// 操作符=
template<class T>
matrix<T>& matrix<T>::operator=(const matrix<T>& m){
	if(this != &m){ //不能自己复制自己
		delete[] element;
		theRows=m.theRows;
		theColumns=m.theColumns;
		element=new T[theRows*theColumns];

		copy(m.element,m.element+theRows*theColumns,element);
	}
	return *this;
}

// 操作符()
template<class T>
T& matrix<T>::operator()(int i, int j) const{
	if(i<1 || i>theRows || j<1 || j> theColumns){
		throw 1;
	}
	return element[(i-1)*theColumns+j-1];
}

// 操作符+
template<class T>
matrix<T> matrix<T>::operator+(const matrix<T>& m) const {
	if(theRows!=m.theRows || theColumns!=m.theColumns){
		throw 1;
	}
	matrix<T>w(theRows, theColumns);
	for(int i=0; i<theRows*theColumns; i++){
		w.element[i]=element[i]+m.element[i];
	}
	return w;
}

template<class T>
matrix<T> matrix<T>::operator*(const matrix<T>& m) const{
	if(theColumns!=m.theRows){  //左边的列数和右边的行数相等  
		throw 1;
	}
	matrix<T> w(theRows, m.theColumns);
	int ct=0, cm=0, cw=0;
	for(int i=1; i<=theRows; i++){
		for(int j=1; j<=m.theColumns; j++){
			T sum=element[ct]*m.element[cm];
			for(int k=2;k<=theColumns; k++){
				ct++;  //同一行的下一个
				cm+=m.theColumns;   //同一列的下一个
				sum+=element[ct]*m.element[cm];
			}
			w.element[cw++]=sum;  //先运算再自增1
			ct-=theColumns-1;  //回到这一行的第一个
			cm=j; //回到下一列的第一个
		}
		ct+=theColumns;  //回到下一行的第一个
		cm=0; //回到第一列的第一个
	}
	return w;
}

int main(){
	matrix<int>m(3,3);
	m(1,1)=1;
	m(1,2)=2;
	m(1,3)=3;
	m(2,1)=4;
	m(2,2)=5;
	m(2,3)=6;
	m(3,1)=7;
	m(3,2)=8;
	m(3,3)=9;

	matrix<int>m2(m);
	m2(1,1)=9;
	m2(1,2)=8;
	m2(1,3)=7;
	m2(2,1)=6;
	m2(2,2)=5;
	m2(2,3)=4;
	m2(3,1)=3;
	m2(3,2)=2;
	m2(3,3)=1;

	for(int i=1; i<=3; i++){
		for(int j=1; j<=3; j++){
			cout<<m(i,j)<<" ";
		}
		cout<<endl;
	}

	for(int i=1; i<=3; i++){
		for(int j=1; j<=3; j++){
			cout<<m2(i,j)<<" ";
		}
		cout<<endl;
	}

	matrix<int>m3;
	m3=m+m2;
	for(int i=1; i<=3; i++){
		for(int j=1; j<=3; j++){
			cout<<m3(i,j)<<" ";
		}
		cout<<endl;
	}

	matrix<int>m4;
	m4=m*m2;
	for(int i=1; i<=3; i++){
		for(int j=1; j<=3; j++){
			cout<<m4(i,j)<<" ";
		}
		cout<<endl;
	}
}