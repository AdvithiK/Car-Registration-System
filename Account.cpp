#include <iostream>
#include <string>
#include<fstream>
#include "../header/Car.h"
#include "../header/account.h"
using namespace std;

<<<<<<< HEAD
<<<<<<< HEAD:header/CarRenter.h
=======
<<<<<<< HEAD:src/Account.cpp
class Account {
    private:
        string us
=======
>>>>>>> 0938e8a75de0e4c3d63485a55f015882abfae9e3
#ifndef CARRENTER_H
#define CARRENTER_H

class CarRenter : public Account {
<<<<<<< HEAD
=======
class Account {
    private:
        string us
>>>>>>> AdvithiK-rentCar:src/Account.cpp
=======
>>>>>>> refs/remotes/origin/master:header/CarRenter.h
>>>>>>> 0938e8a75de0e4c3d63485a55f015882abfae9e3
    public:
        //constructor
        CarRenter();
        //parameterized constructor that is specific towards the users that are renters
        CarRenter(string username, string password, string driverID, string userType);
        //destructor that deletes all car renters from file too
        ~CarRenter() = delete; 
        //allows car renter to rent a car
        void rentCar();
        //allows car renter to return a car to the car loaner
        void returnCar();
        // allows care renter to view available car listings
        void browseCarListings();
        // allows user to add funds to their balance 
        void addFunds();
};
