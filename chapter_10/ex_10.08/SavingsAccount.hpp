#ifndef SAVINGSACCOuNT_HPP
#define SAVINGSACCOuNT_HPP

class SavingsAccount
{
public:
    SavingsAccount(double = 0.0);
    void setBalance(double);
    double getBalance();
    void calculateMonthlyInterest();
    void setSavingsBalance(double);
    double getSavingsBalance();
    static void modifyInterestRate(double);
    static double getAnnualInterestRate();
    void printBalance();
private:
    double savingsBalance_;
    double balance_;
    static double annualInterestRate_;
};

#endif

