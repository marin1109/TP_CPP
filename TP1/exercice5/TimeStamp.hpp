#ifndef _TIMESTAMP_HPP
#define _TIMESTAMP_HPP

class TimeStamp {
    public:
        int hour;
        int minute;
        int second;
        TimeStamp(int h, int m, int s);
        void print();
        void addSecond(int s);
};

#endif