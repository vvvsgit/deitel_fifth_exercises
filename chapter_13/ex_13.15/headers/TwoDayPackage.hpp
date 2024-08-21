#ifndef TWODAYPACKAGE_HPP
#define TWODAYPACKAGE_HPP

#include "Package.hpp"

class TwoDayPackage : public Package
{
public:
    TwoDayPackage(const std::string &, const std::string &, const std::string &, 
                  const std::string &, const std::string &, const std::string &, 
                  const std::string &, const std::string &, const std::string &, 
                  const std::string &, const double, const double, const double);
    void setFlatFee(const double);
    double getFlatFee() const;
    virtual double calculateCost() const;
private:
    double flatFee_;
};

#endif

