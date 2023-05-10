#include <iostream>
using namespace std;

class Date
{
    friend ostream & operator<<(ostream &cout, Date& date);
    friend istream & operator>>(istream& cin, Date& date);
public:
    Date(int y, int m, int d){
        year=y;
        month=m;
        day=d;
    }
    int year;
    int month;
    int day;
};

ostream & operator<<(ostream &cout, Date& date){
    cout<<date.year<<"-"<<date.month<<"-"<<date.day;
    return cout;
}
istream & operator>>(istream& cin, Date& date){
    cin>>date.year>>date.month>>date.day;
    return cin;
}

class Time
{
    friend ostream & operator<<(ostream &cout, Time& time);
    friend istream & operator>>(istream& cin, Time& time);
public:
    Time(int h, int m, int s){
        hour=h;
        minute=m;
        second=s;
    }
    int hour;
    int minute;
    int second;
};

ostream & operator<<(ostream &cout, Time& time){
    cout<<time.hour<<":"<<time.minute<<":"<<time.second;
    return cout;
}
istream & operator>>(istream& cin, Time& time){
    cin>>time.hour>>time.minute>>time.second;
    return cin;
}

class Date_Time: public Date, public Time
{
    friend ostream & operator<<(ostream &cout, Date_Time& date_time);
    friend istream & operator>>(istream& cin, Date_Time& date_time);
public:
    Date_Time(int y, int mon, int d, int h, int min, int s): Date(y,mon,d), Time(h,min,s){
        year=y;
        month=mon;
        day=d;
        hour=h;
        minute=min;
        second=s;
    }
    bool operator>(Date_Time& dt2){
        if(year>dt2.year){
            return true;
        }
        else if(year<dt2.year){
            return false;
        }
        else{
            if(month>dt2.month){
                return true;
            }
            else if(month<dt2.month){
                return false;
            }
            else{
                if(day>dt2.day){
                    return true;
                }
                else if(day<dt2.day){
                    return false;
                }
                else{
                    if(hour>dt2.hour){
                        return true;
                    }
                    else if(hour<dt2.hour){
                        return false;
                    }
                    else{
                        if(minute>dt2.minute){
                            return true;
                        }
                        else if(minute<dt2.minute){
                            return false;
                        }
                        else{
                            if(second>dt2.second){
                                return true;
                            }
                            else {
                                return false;
                            }
                        }
                    }
                }
            }
        }
    }
};

ostream & operator<<(ostream &cout, Date_Time& date_time){
    cout<<date_time.year<<"-"<<date_time.month<<"-"<<date_time.day<<" "<<date_time.hour<<":"<<date_time.minute<<":"<<date_time.second;
    return cout;
}
istream & operator>>(istream& cin, Date_Time& date_time){
    cin>>date_time.year>>date_time.month>>date_time.day>>date_time.hour>>date_time.minute>>date_time.second;
    return cin;
}

int main(){
    int year,month,day,hour,minute,second;
    Date_Time dt(year,month,day,hour,minute,second);
    cin>>dt;
    int year2,month2,day2,hour2,minute2,second2;
    Date_Time dt2(year2,month2,day2,hour2,minute2,second2);
    cin>>dt2;
    if(dt>dt2){
        cout<<dt2;
    }
    else{
        cout<<dt;
    }
}