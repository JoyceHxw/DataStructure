#include <iostream>
using namespace std;

// 最大公因子
int max_factor(int a, int b){
    int f=1;
    int i=1;
    // 负数
    a=abs(a);
    b=abs(b);
    // 0
    if(a==0 || b==0){
        return 0;
    }
    int minor=a<b?a:b;
    while(i<=minor){
        if(b%i==0 && a%i==0){
            f=i;
        }
        i++;
    }
    return f;
}

class Fraction
{
public:

    Fraction(int a, int b){
        divident=a;
        divisor=b;
    }
    int divident;
    int divisor;

    Fraction operator+(Fraction& f){
        int res_divisor=divisor*f.divisor;
        int res_divident=divident*f.divisor+f.divident*divisor;
        int c=max_factor(res_divident,res_divisor);
        if(c==0){
            Fraction res(0,0);
            return res;
        }
        else{
            Fraction res(res_divident/c,res_divisor/c);
            return res;
        }
    }
    Fraction operator-(Fraction& f){
        int res_divisor=divisor*f.divisor;
        int res_divident=divident*f.divisor-f.divident*divisor;
        int c=max_factor(res_divident,res_divisor);
        if(c==0){
            Fraction res(0,0);
            return res;
        }
        else{
            Fraction res(res_divident/c,res_divisor/c);
            return res;
        }
    }
    friend Fraction operator*(Fraction &f1,Fraction &f2);
    friend Fraction operator/(Fraction &f1,Fraction &f2);

};

Fraction operator*(Fraction &f1,Fraction &f2){
    int res_divisor=f1.divisor*f2.divisor;
    int res_divident=f1.divident*f2.divident;
    int c=max_factor(res_divident,res_divisor);
    if(c==0){
        Fraction res(0,0);
        return res;
    }
    else{
        Fraction res(res_divident/c,res_divisor/c);
        return res;
    }
}
Fraction operator/(Fraction &f1,Fraction &f2){
    int res_divisor=f1.divisor*f2.divident;
    int res_divident=f1.divident*f2.divisor;
    int c=max_factor(res_divident,res_divisor);
    if(c==0){
        Fraction res(0,0);
        return res;
    }
    else{
        Fraction res(res_divident/c,res_divisor/c);
        return res;
    }
}

ostream &operator<<(ostream& cout,Fraction &f){
    if(f.divident==0){
        cout<<0;
    }
    else if(abs(f.divident)==abs(f.divisor)){
        if(f.divident*f.divisor>0){
            cout<<1;
        }
        else{
            cout<<-1;
        }
    }
    else{
        if(f.divident*f.divisor>0){  //正数
            if(f.divisor==1 || f.divisor==-1){ //整数
                cout<<f.divident;
            }
            else{
                cout<<abs(f.divident)<<'/'<<abs(f.divisor);
            }
        }
        else{
            if(f.divident>0){
                if(f.divisor==1 || f.divisor==-1){
                    cout<<(0-f.divident);
                }
                else{
                    cout<<(0-f.divident)<<'/'<<abs(f.divisor);
                }
            }
            else{
                if(f.divisor==1 || f.divisor==-1){
                    cout<<f.divident;
                }
                else{
                    cout<<f.divident<<'/'<<f.divisor;
                }
            }
        }
    }
    return cout;
}

int main(){
    int f1_divident;
    int f1_divisor;
    int f2_divident;
    int f2_divisor;
    cin>>f1_divident>>f1_divisor>>f2_divident>>f2_divisor;
    Fraction f1(f1_divident,f1_divisor);
    Fraction f2(f2_divident,f2_divisor);
    Fraction r1=f1+f2;
    Fraction r2=f1-f2;
    Fraction r3=f1*f2;
    Fraction r4=f1/f2;
    cout<<r1<<endl;
    cout<<r2<<endl;
    cout<<r3<<endl;
    cout<<r4<<endl;
}