#ifndef STRING_HPP
#define STRING_HPP

#include <iostream>

class String
{
    friend std::ostream &operator<<(std::ostream &, const String &);
    friend std::istream &operator>>(std::istream &, String &);
public:
    String(const char * = "");
    String(const String &);
    ~String();

    int getLength();
    char & operator[](int subscript);
    char operator[](int subscript) const;
    const String &operator=(const String &);
    const String operator+(const String &);
    const String &operator+=(const String &);
private:
    int length_;
    char *stringPtr_;

    void setString(const char *);
};

#endif

