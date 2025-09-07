#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std;

class Transaction {
    private:
        string _carID;
        string _renterID;
        string _loanerID;
        double _hourlyPrice;
        double _hoursRented;
        double _totalAmount;
    public:
        Transaction();
        Transaction(const string carID, const string renterID, const string loanerID, 
                    const double hourlyPrice, const double hoursRented);
        void displayTransaction();
        const string& getCarID() { return _carID; }
        const string& getRenterID() { return _renterID; }
        const string& getLoanerID() { return _loanerID; }
        const double getHourlyPrice() { return _hourlyPrice; }
        const double getHoursRented() { return _hoursRented; }
        const double getTotalAmount() { return _totalAmount; }

        void setCarID(const string& carID) { _carID = carID; }
        void setRenterID(const string& renterID) { _renterID = renterID; }
        void setLoanerID(const string& loanerID) { _loanerID = loanerID; }
        void setHourlyPrice(const double hourlyPrice) { _hourlyPrice = hourlyPrice; }
        void setHoursRented(const double hoursRented) { _hoursRented = hoursRented; }
        void setTotalAmount() { _totalAmount = _hourlyPrice * _hoursRented; }
};

#endif