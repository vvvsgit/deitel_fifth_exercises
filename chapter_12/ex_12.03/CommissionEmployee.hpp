#ifndef COMMISSIONEMPLOYEE_HPP
#define COMMISSIONEMPLOYEE_HPP

#include <string>

class CommissionEmployee
{
public:
    CommissionEmployee(const std::string &, const std::string &, const std::string &, double = 0.0, double = 0.0);

    void setFirstName(const std::string &);
    void setLastName(const std::string &);
    void setSocialSecurityNumber(const std::string &);
    void setGrossSales(const double);
    void setCommissionRate(const double);

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getSocialSecurityNumber() const;
    double getGrossSales() const;
    double getCommissionRate() const;

    double earnings() const;
    void print() const;
private:
    std::string firstName_;
    std::string lastName_;
    std::string socialSecurityNumber_;
    double grossSales_;
    double commissionRate_;
};

#endif

