#include "OverNightPackage.hpp"

OverNightPackage::OverNightPackage(const std::string &nameFrom, const std::string &addressFrom, const std::string &cityFrom, 
                                   const std::string &stateFrom, const std::string &zipCodeFrom, const std::string &nameTo, 
                                   const std::string &addressTo, const std::string &cityTo, const std::string &stateTo, 
                                   const std::string &zipCodeTo, const double weight, const double costPerWeight, const double nightFee)
    : Package(nameFrom, addressFrom, cityFrom, stateFrom, zipCodeFrom,
              nameTo, addressTo, cityTo, stateTo, zipCodeTo,
              weight, costPerWeight)
{
    setFeeForNight(nightFee);
}

void
OverNightPackage::setFeeForNight(const double fee)
{
    feeForNight_ = (fee > 0.0 ? fee : 0.0);
}

double
OverNightPackage::getFeeForNight() const
{
    return feeForNight_;
}

double
OverNightPackage::calculateCost() const
{
    return getFeeForNight() * getWeight() + Package::calculateCost();
}

