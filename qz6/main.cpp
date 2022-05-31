#include <iostream>
#include <string>
using namespace std;

class Clock {
    public:
    int hour;
    int minute;
    int second;
    string meridian;
    Clock(int h,int m,int s,string t) {
        hour=h;
        minute=m;
        second=s;
        meridian=t;
    }
    int get_hour() {
        return hour;
    }
    int get_min() {
        return minute;
    }
    int get_sec() {
        return second;
    }
    string get_meridian() {
        return meridian;
    }
    void display() {
        cout<<get_hour()<<":"<<get_min()<<":"<<get_sec()<<" "<<get_meridian()<<endl;
    }
};

class StandardClock : Clock {
    public:
    string ti;
    StandardClock(int h,int m,int s,string t) : Clock(h,m,s,t) {
        if(t=="AM") {
            ti="¤W¤È";
        } else {
            ti="¤U¤È";
        }
    }
    string get_ti() {
        return ti;
    }
    void display() {
        cout<<get_ti()<<" "<<get_hour()<<":"<<get_min()<<":"<<get_sec()<<endl;
    }
};

class MilitaryClock : Clock {
    public:
    MilitaryClock(int h,int m,int s,string t) : Clock(h,m,s,t) {
        if(t=="PM") {
            hour+=12;
        }
    }
    void display() {
        cout<<get_hour()<<":"<<get_min()<<":"<<get_sec()<<" "<<endl;
    }
};

int main() {
    Clock cc(10,25,43,"AM");
    StandardClock sc(10,25,43,"AM");
    MilitaryClock mc(10,25,43,"PM");
    cc.display();
    sc.display();
    mc.display();
    return 0;
}
