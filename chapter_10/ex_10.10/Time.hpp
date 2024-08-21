#ifndef TIME_HPP
#define TIME_HPP

class Time
{
public:
    Time();
    Time(int, int, int);

    void setTime(int, int, int);

    int getHour();
    int getMinute();
    int getSecond();

    void printUniversal();
    void printStandart();
private:
    int secondsTime_;
};

#endif

