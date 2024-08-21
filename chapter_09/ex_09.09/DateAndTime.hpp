#ifndef DATEANDTIME_HPP
#define DATEANDTIME_HPP

class DateAndTime
{
public:
    DateAndTime();
    DateAndTime(int, int, int, int, int, int);

    void setTime(int, int, int);
    void setDate(int, int, int);

    void setSecond(int);
    void setMinute(int);
    void setHour(int);
    void setDay(int);
    void setMonth(int);
    void setYear(int);

    int getSecond();
    int getMinute();
    int getHour();
    int getDay();
    int getMonth();
    int getYear();

    void printUniversal();
    void printStandart();
    void tick();
    void nextDay();
private:
    int second_;
    int minute_;
    int hour_;
    int day_;
    int month_;
    int year_;
};

#endif

