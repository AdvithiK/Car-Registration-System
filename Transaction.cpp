#include "../header/Transaction.h"

Transaction::Transaction() {
    _carID = "";
    _renterID = "";
    _loanerID = "";
    _hourlyPrice = 0;
    _hoursRented = 0;
    _totalAmount = 0;
}

Transaction::Transaction(const string carID, const string renterID, const string loanerID, const double hourlyPrice, 
            const double hoursRented) {
    _carID = carID;
    _renterID = renterID;
    _loanerID = loanerID;
    _hourlyPrice = hourlyPrice;
    _hoursRented = hoursRented;
    _totalAmount = _hourlyPrice * _hoursRented;
}

//display function, can be used for user receipt
void Transaction::displayTransaction() {
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << "Renter ID: " << _renterID << ", Loaner ID: " << _loanerID << ", Car ID: " << _carID << endl;
    cout << "Hourly rental price: $" << _hourlyPrice << ", Hours rented: " << _hoursRented << endl; 
    cout << "Total amount charged: $" << _totalAmount << endl; // format so it looks like $xx.xx
    cout << "-------------------------------------------------------------------------------" << endl;
}