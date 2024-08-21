#ifndef DATE_HPP
#define DATE_HPP

class Date
{
public:
    Date();
    Date(int, int, int);
    Date(int, int);
    Date(char *, int, int);

    void setDate(int, int, int);
    void setMonth(int);
    void setDay(int);
    void setYear(int);
    int getMonth();
    int getDay();
    int getYear();

    void printDDMMYY();
    void printDDDYYYY();
    void printMonthDDYYYY();
private:
    int month_;
    int day_;
    int year_;
};

#endif

