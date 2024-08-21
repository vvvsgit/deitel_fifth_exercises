#include "../headers/TwoDayPackage.hpp"

TwoDayPackage::TwoDayPackage(const std::string &nameFrom, const std::string &addressFrom, const std::string &cityFrom, 
                             const std::string &stateFrom, const std::string &zipCodeFrom, const std::string &nameTo, 
                             const std::string &addressTo, const std::string &cityTo, const std::string &stateTo, 
                             const std::string &zipCodeTo, const double weight, const double costPerWeight, const double flatFee)
    : Package(nameFrom, addressFrom, cityFrom, stateFrom, zipCodeFrom,
              nameTo, addressTo, cityTo, stateTo, zipCodeTo,
              weight, costPerWeight)
{
    setFlatFee(flatFee);
}

void
TwoDayPackage::setFlatFee(const double fee)
{
    flatFee_ = (fee >= 0.0 ? fee : 0.0);
}

double
TwoDayPackage::getFlatFee() const
{
    return flatFee_;
}

double
TwoDayPackage::calculateCost() const
{
    return getFlatFee() + Package::calculateCost();
}

