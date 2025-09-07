#ifndef CARACCESS_H
#define CARACCESS_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "../header/Car.h"
#include "../header/account.h"
#include "../header/CarRenter.h"
#include "../header/CarLoaner.h"
#include "../header/Transaction.h"
using namespace std;


class CarAccess {
    friend class Account;
    friend class CarRenter;
    friend class CarLoaner;
    
    private:
        vector<Car> cars;
        vector<string> accountVec;
        vector<Transaction> transactions;
        // Account currentAccount;
        
    public:
        void addCarInfo(string, string, string, string, int, int, string, double);
        
        //return vector for other classes to use ??
        vector<Car> accessVector();
        vector<string> populateAccountVector(Account);

        CarAccess() {};
        //temp until file vector conversion is made
        void initializeCars();
        void push_back(Car& car_obj);

        //return vector for other classes to use ??
        vector<Car> accessCars() {
            return cars;
        }
        vector<Transaction> accessTransactions() { 
            return transactions;
        }

        // file -> AccountVec
        void populateAccountVector();
        void populateCarVector();
        void CarVectorToFile();

        Car findCar(const string& carID);

        void populateAccountFile();


        void getLoanerTransactionHistory(const string &loanerID);
        void getRenterTransactionHistory(const string &renterID);
        void populateTransactionsVector();
        void populateTransactionsFile();
        void outputTransactions();
        void logTransaction(Transaction t);
};

#endif