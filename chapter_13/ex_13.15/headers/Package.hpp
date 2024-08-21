#ifndef PACKAGE_HPP
#define PACKAGE_HPP

#include <string>

class Package
{
public:
Package(const std::string &, const std::string &, const std::string &, 
        const std::string &, const std::string &, const std::string &, 
        const std::string &, const std::string &, const std::string &, 
        const std::string &, const double, const double);

    void setNameFrom(const std::string &);
    void setAddressFrom(const std::string &);
    void setCityFrom(const std::string &);
    void setStateFrom(const std::string &);
    void setZipCodeFrom(const std::string &);

    std::string getNameFrom() const;
    std::string getAddressFrom() const;
    std::string getCityFrom() const;
    std::string getStateFrom() const;
    std::string getZipCodeFrom() const;

    void setNameTo(const std::string &);
    void setAddressTo(const std::string &);
    void setCityTo(const std::string &);
    void setStateTo(const std::string &);
    void setZipCodeTo(const std::string &);

    std::string getNameTo() const;
    std::string getAddressTo() const;
    std::string getCityTo() const;
    std::string getStateTo() const;
    std::string getZipCodeTo() const;

    void setWeight(const double);
    void setCostPerWeight(const double);
    double getWeight() const;
    double getCostPerWeight() const;

    virtual double calculateCost() const;
    void print() const;
private:
    std::string nameFrom_;
    std::string addressFrom_;
    std::string cityFrom_;
    std::string stateFrom_;
    std::string zipCodeFrom_;

    std::string nameTo_;
    std::string addressTo_;
    std::string cityTo_;
    std::string stateTo_;
    std::string zipCodeTo_;

    double weight_;
    double costPerWeight_;
};

#endif

