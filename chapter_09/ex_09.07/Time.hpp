#ifndef TIME_HPP
#define TIME_HPP

class Time
{
public:
    Time();
    Time(int, int, int);

    void setTime(int, int, int);
    void setHour(int);
    void setMinute(int);
    void setSecond(int);

    int getHour();
    int getMinute();
    int getSecond();

    void printUniversal();
    void printStandart();
    void tick();
private:
    int hour_;
    int minute_;
    int second_;
};

#endif

