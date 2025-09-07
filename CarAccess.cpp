#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <fstream>
#include "../header/Transaction.h"
#include "../header/CarAccess.h"
#include "../header/CarRenter.h"
#include "../header/account.h"

using namespace std;



vector<string> CarAccess::populateAccountVector(Account userAccount)
{

    accountVec.clear();

    // Add the user account data to accountVec
    accountVec.push_back(userAccount.getUsername());
    accountVec.push_back(userAccount.getPassword());
    accountVec.push_back(userAccount.getDriverID());
    accountVec.push_back(userAccount.getUserType());
    accountVec.push_back(to_string(userAccount.getBalance()));

    // Return a copy of accountVec if needed
    return accountVec;
}

void CarAccess::populateAccountFile()
{
    ofstream outfile;

    outfile.open("files/loginData.txt", ios::app);

    if (!outfile.is_open())
    {
        cout << "Error opening file loginData.txt" << endl;
        return;
    }

    for (unsigned int i = 0; i < accountVec.size(); i++)
    {
        outfile << accountVec.at(i);
    }
    outfile << '\n';
    
    outfile.close();
}

void CarAccess::initializeCars() {
    cars.push_back(Car("DK004", "Chevrolet", "Malibu", "Black", 2017, 5, "automatic", 16.20, "renter3", "loaner3"));
    cars.push_back(Car("EK005", "Nissan", "Altima", "White", 2018, 5, "automatic", 18.00, "renter4", "loaner4"));
    cars.push_back(Car("FK006", "BMW", "320i", "Grey", 2020, 5, "automatic", 20.45, "renter5", "loaner5"));
    cars.push_back(Car("GK007", "Mercedes", "C300", "Silver", 2021, 5, "automatic", 22.50, "renter6", "loaner6"));
}

void CarAccess::push_back(Car& car_obj)
{
    cars.push_back(car_obj);
}

void CarAccess::CarVectorToFile(){
    ofstream outFS;
    unsigned i;

    outFS.open("files/Car.txt");

    if(not outFS.is_open()) { throw runtime_error("Car.txt was unable to be opened");}

    if(outFS.good()){
        for(i = 0; i < cars.size(); i++){
            outFS << cars.at(i).get_carID() << " " << cars.at(i).get_carMake() << " " << cars.at(i).get_carModel() << " " << " " << cars.at(i).get_carColor() << " " << cars.at(i).get_carYear() 
                << " " << cars.at(i).get_carNumberOfSeats() << " " << cars.at(i).get_carTransmission() << " " << cars.at(i).get_carHourlyRate() << " " << cars.at(i).get_renterID() << " " << cars.at(i).get_loanerID() << " " << cars.at(i).status() << endl;
        }
    }
    cars.push_back(Car("BK002", "Honda", "Civic", "Blue", 2012, 5, "manual", 12.50, "renter1", "loaner1"));
    cars.push_back(Car("ZP003", "Ford", "Focus", "Red", 2015, 5, "automatic", 14.30, "renter2", "loaner2"));
}

Car CarAccess::findCar(const string& carID) {
    for (unsigned i = 0; i < cars.size(); i++) {
        if (cars.at(i).get_carID() == carID) {
            return cars.at(i);
        }
    }
    return cars.at(0);
}

void CarAccess::populateCarVector()
{
    ifstream infile("files/Car.txt");

    if(!infile.is_open()) {
        throw runtime_error("Car.txt was unable to open");
        return;
    }

    string line;
    int year, numOfSeats;
    double hourlyRate;
    string numID, model, make, color, transmission, renterID, loanerID;
    string status;

    if(infile.good()) {
        while(getline(infile, line, '\n')) 
        {
            stringstream ss(line);
            ss >> numID >> make >> model >> color >> year >> numOfSeats >> transmission >> hourlyRate >> renterID >> loanerID >> status;

            Car holdNewCar(numID, make, model, color, year, numOfSeats, transmission, hourlyRate, renterID, loanerID);
            cars.push_back(holdNewCar);
        }
    }

    infile.close();
    
    if (infile.is_open()) 
        throw runtime_error("Car.txt was unable to be closed");
}

void CarAccess::logTransaction(Transaction t) {
    transactions.push_back(t);
}

//helper func to delete later
void CarAccess::outputTransactions() {
    for (unsigned i = 0; i < transactions.size(); i++) {
        transactions.at(i).displayTransaction();
    }
}

void CarAccess::populateTransactionsFile() {
    ofstream outFS;
    unsigned i;

    outFS.open("files/transactionHistory.txt");

    if (not outFS.is_open()) { throw runtime_error("transactionHistory.txt was unable to be opened"); }

    if (outFS.good()) { 
        for (i = 0; i < transactions.size(); i++) {
            outFS << transactions.at(i).getCarID() << " " << transactions.at(i).getRenterID() << " " << transactions.at(i).getLoanerID()
                  << " " << transactions.at(i).getHourlyPrice() << " " << transactions.at(i).getHoursRented() << " " 
                  << (transactions.at(i).getHourlyPrice() * transactions.at(i).getHoursRented()) << endl;
        }
    }

    outFS.close();

    if (outFS.is_open()) { throw runtime_error("transactionHistory.txt was unable to be closed"); }
}

void CarAccess::populateTransactionsVector() {
    ifstream inFS;
    stringstream ss;
    string line;
    string word;
    string carID;
    string renterID;
    string loanerID;
    double hourlyRate;
    double hoursRented;
    double totalAmount;

    inFS.open("files/transactionHistory.txt");

    if (not inFS.is_open()) { throw runtime_error("transactionHistory.txt was unable to open"); }

    // will store all transactions into vector
    // then when the user asks to see their transactions, search through that vector and output transactions

    if (inFS.good()) {
        while (getline(inFS, line, '\n')) {
            stringstream ss(line);
            ss >> carID;
            ss >> renterID;
            ss >> loanerID;
            ss >> hourlyRate;
            ss >> hoursRented;
            ss >> totalAmount;
            transactions.push_back(Transaction(carID, renterID, loanerID, hourlyRate, hoursRented));
        }

    }
    inFS.close();
 
}




void CarAccess::getRenterTransactionHistory(const string &renterID) {
    bool hasTransactions = false;
    unsigned i = 0;

    if (transactions.size() == 0) { hasTransactions = false; }

    for (i = 0; i < transactions.size(); i++) {
        if (transactions.at(i).getRenterID() == renterID) {
            transactions.at(i).displayTransaction();
            hasTransactions = true;
        }
    }

    if (not hasTransactions) { cout << "You have no transaction history available." << endl; }
}


void CarAccess::getLoanerTransactionHistory(const string &loanerID) {
    bool hasTransactions = false;
    unsigned i = 0;

    if (transactions.size() == 0) { hasTransactions = false; }

    for (i = 0; i < transactions.size(); i++) {
        if (transactions.at(i).getLoanerID() == loanerID) {
            transactions.at(i).displayTransaction();
            hasTransactions = true;
        }
    }

    if (not hasTransactions) { cout << "You have no transaction history available." << endl; }
}

