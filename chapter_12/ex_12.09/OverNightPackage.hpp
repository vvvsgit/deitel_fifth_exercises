#ifndef OVERNIGHTPACKAGE_HPP
#define OVERNIGHTPACKAGE_HPP

#include "Package.hpp"

class OverNightPackage : public Package
{
public:
    OverNightPackage(const std::string &, const std::string &, const std::string &, 
                     const std::string &, const std::string &, const std::string &, 
                     const std::string &, const std::string &, const std::string &, 
                     const std::string &, const double, const double, const double);
    void setFeeForNight(const double);
    double getFeeForNight() const;
    double calculateCost() const;
private:
    double feeForNight_;
};

#endif

