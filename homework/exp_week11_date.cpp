#include <iostream>
using namespace std;
#include <unordered_map>




class Date
{
public:
    Date(int y, int m, int d){
        year=y;
        month=m;
        day=d;
    }
    int year;
    int month;
    int day;
    Date operator++(int){
        unordered_map<int,int>m;
        if((year%4==0 && year%100!=0) || year%400==0){
            m={{1,31},{2,29},{3,31},{4,30},{5,31},{6,30},{7,31},{8,31},{9,30},{10,31},{11,30},{12,31}};
        }
        else{
            m={{1,31},{2,28},{3,31},{4,30},{5,31},{6,30},{7,31},{8,31},{9,30},{10,31},{11,30},{12,31}};
        }
        if(day==m[month]){
            if(month==12){
                year++;
                month=1;
            }
            else{
                month++;
            }
            day=1;
        }
        else{
            day++;
        }
        return *this;
    }
};

int main(){
    int year;
    int month;
    int day;
    cin>>year>>month>>day;
    Date d(year,month,day);
    d++;
    cout<<d.year<<"年"<<d.month<<"月"<<d.day<<"日";
}