#ifndef CARRENTER_H
#define CARRENTER_H

#include <iostream>

#include <string>
#include <sstream>
#include<fstream>
#include <vector>
#include "../header/Car.h"
#include "../header/account.h"
#include "../header/CarAccess.h"

using namespace std;

class CarAccess;

class CarRenter : public Account{
    public:
        //parameterized constructor that is specific towards the users that are renters
        
        CarRenter();
        
        CarRenter(string& username){
            this->setUsername(username);
        }

        void browseCars(CarAccess &carAccessObject);
        string rentACar(CarAccess &carAccessObject, const string& id);
        string returnACar(CarAccess &carAccessObject, const string& id);
        void searchForACar(CarAccess &carAccessObject, const string& car_string_detail);
        void searchForACar(CarAccess &carAccessObject, const int& car_int_detail);
        void searchForPriceRange(CarAccess &carAccessObject, const double& min_price, const double& max_price);

        // ~CarRenter() = delete;

        CarRenter(string username, string password, string driverID, string userType);

};

#endif