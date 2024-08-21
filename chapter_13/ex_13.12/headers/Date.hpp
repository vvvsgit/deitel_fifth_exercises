#ifndef DATE_HPP
#define DATE_HPP

class Date
{
public:
    Date();
    Date(const int, const int, const int);

    int getDay() const;
    int getMonth() const;
    int getYear() const;

    void setDate(const int, const int, const int);
    bool isLeapYear(const int) const;
private:
    int year_;
    int month_;
    int day_;

    static const int daysPerMonth_[];
};

#endif

