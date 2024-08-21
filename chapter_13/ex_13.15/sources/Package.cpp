#include <iostream>

#include "../headers/Package.hpp"

Package::Package(const std::string &nameFrom, const std::string &addressFrom, const std::string &cityFrom, 
                 const std::string &stateFrom, const std::string &zipCodeFrom, const std::string &nameTo, 
                 const std::string &addressTo, const std::string &cityTo, const std::string &stateTo, 
                 const std::string &zipCodeTo, const double weight, const double costPerWeight)
{
    setNameFrom(nameFrom);
    setAddressFrom(addressFrom);
    setCityFrom(cityFrom);
    setStateFrom(stateFrom);
    setZipCodeFrom(zipCodeFrom);

    setNameTo(nameTo);
    setAddressTo(addressTo);
    setCityTo(cityTo);
    setStateTo(stateTo);
    setZipCodeTo(zipCodeTo);

    setWeight(weight);
    setCostPerWeight(costPerWeight);
}

void
Package::setNameFrom(const std::string &name)
{
    nameFrom_ = name;
}

void
Package::setAddressFrom(const std::string &address)
{
    addressFrom_ = address;
}

void
Package::setCityFrom(const std::string &city)
{
    cityFrom_ = city;
}

void
Package::setStateFrom(const std::string &state)
{
    stateFrom_ = state;
}

void
Package::setZipCodeFrom(const std::string &zipCode)
{
    zipCodeFrom_ = zipCode;
}

std::string
Package::getNameFrom() const
{
    return nameFrom_;
}

std::string
Package::getAddressFrom() const
{
    return addressFrom_;
}

std::string
Package::getCityFrom() const
{
    return cityFrom_;
}

std::string
Package::getStateFrom() const
{
    return stateFrom_;
}

std::string
Package::getZipCodeFrom() const
{
    return zipCodeFrom_;
}

void
Package::setNameTo(const std::string &name)
{
    nameTo_ = name;
}

void
Package::setAddressTo(const std::string &address)
{
    addressTo_ = address;
}

void
Package::setCityTo(const std::string &city)
{
    cityTo_ = city;
}

void
Package::setStateTo(const std::string &state)
{
    stateTo_ = state;
}

void
Package::setZipCodeTo(const std::string &zipCode)
{
    zipCodeTo_ = zipCode;
}

std::string
Package::getNameTo() const
{
    return nameTo_;
}

std::string
Package::getAddressTo() const
{
    return addressTo_;
}

std::string
Package::getCityTo() const
{
    return cityTo_;
}

std::string
Package::getStateTo() const
{
    return stateTo_;
}

std::string
Package::getZipCodeTo() const
{
    return zipCodeTo_;
}

void
Package::setWeight(const double weight)
{
    weight_ = (weight > 0 ? weight : 1.0);
}

void
Package::setCostPerWeight(const double costPerWeight)
{
    costPerWeight_ = (costPerWeight >= 0 ? costPerWeight : 0.0);
}

double
Package::getWeight() const
{
    return weight_;
}

double
Package::getCostPerWeight() const
{
    return costPerWeight_;
}

double
Package::calculateCost() const
{
    return getWeight() * getCostPerWeight();
}

void
Package::print() const
{
    std::cout << "Package details" << std::endl;
    std::cout << getNameFrom() << " ---> " << getNameTo() << std::endl;
    std::cout << getAddressFrom() << " ---> " << getAddressTo() << std::endl;
    std::cout << getCityFrom() << " ---> " << getCityTo() << std::endl;
    std::cout << getStateFrom() << " ---> " << getStateTo() << std::endl;
    std::cout << getZipCodeFrom() << " ---> " << getZipCodeTo() << std::endl;
}

