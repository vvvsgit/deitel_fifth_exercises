#ifndef DATE_HPP
#define DATE_HPP

class Date
{
public:
    Date();
    Date(int, int, int);

    void setDate(int, int, int);
    void setMonth(int);
    void setDay(int);
    void setYear(int);
    int getMonth();
    int getDay();
    int getYear();

    void print();
    void nextDay();
private:
    int month_;
    int day_;
    int year_;
};

#endif

