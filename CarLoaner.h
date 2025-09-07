#ifndef CARLOANER_H
#define CARLOANER_H

#include <iostream>
#include <string>
#include <fstream>
#include "../header/Car.h"
#include "../header/account.h"
#include "../header/CarAccess.h"

using namespace std;

class CarAccess;

class CarLoaner : public Account {
    private:

    public:
        CarLoaner();

        CarLoaner(string& username) {
            this->setUsername(username);
        }

        // outputting cars
        void viewAllCars(CarAccess& carAccessObj);
        void viewAllMyCars(CarAccess& carAccessObj);
        void viewCarsByStatus(CarAccess& carAccessObj, std::string& carStatus);

        // allows user to loan their car for rent
        void addCar(CarAccess& carAccessObj, string carID, string carMake, string carModel, string carColor, int carYear, 
            int carNumOfSeats, string carTransmission, double carHourlyRate, const string loaner_id);
        void removeCar(CarAccess& carAccessObj, const string& carID);

        // user knows how much they earned
        void viewPaymentLoan();

        void viewAllMyCars();
};

#endif