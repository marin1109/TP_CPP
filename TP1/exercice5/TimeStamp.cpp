#include "TimeStamp.hpp"
#include <iostream>

using namespace std;

TimeStamp::TimeStamp(int h, int m, int s) {
    int sh {3600*h};
    int sm {60*m};
    int ss {s};
    int total {sh + sm + ss};
    switch (total < 0)
    {
    case true:
        hour = 0;
        minute = 0;
        second = 0;
        break;
    
    default:
        hour = total/3600;
        minute = (total%3600)/60;
        second = (total%3600)%60;
        break;
    }
}

void TimeStamp::print() {
    cout << hour << ":" << minute << ":" << second << endl;
}

void TimeStamp::addSecond(int s) {
    second += s;
    minute += second/60;
    hour += minute/60;
    second %= 60;
    minute %= 60;
    hour %= 24;
}