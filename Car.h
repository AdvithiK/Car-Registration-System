#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Car {
    private:
        //information about the car to be stored
        string carID;
        string carMake;
        string carModel;
        string carColor;
        int carYear;
        int carNumberOfSeats;
        string carTransmission;
        double carHourlyRate; 
        string renterID;
        string loanerID;
        //stores whether the car is rented or not
        bool rented;
    public:
        //default constructor, allows Car Loner class to input Car details
        Car();
        Car(const string id, const string make, const string model, const string color, const int year, 
           const int seats, const string transmission, const double hourly_rate, string renter_id, const string loaner_id);
        //getters
        string get_carID(){
            return carID;
        }
        string get_carMake(){
            return carMake;
        }
        string get_carModel(){
            return carModel;
        }
        string get_carColor(){
            return carColor;
        }
        int get_carYear(){
            return carYear;
        }
        int get_carNumberOfSeats(){
            return carNumberOfSeats;
        }

        string get_carTransmission(){
            return carTransmission;
        }

        double get_carHourlyRate(){
         return carHourlyRate;
        }
        string get_renterID(){
            return renterID;
        }
        string get_loanerID(){
            return loanerID;
        }

        //no getter for rented, status does the same thing

        //setters
        //carID should not have a setter, this is temporary until we figure out how to automatically set it
        void set_carID(const string id){
            carID = id;
        }
        void set_carMake(const string make){
            carMake = make;
        }
        void set_carModel(const string model){
            carModel = model;
        }
        void set_carColor(const string color){
            carColor = color;
        }
        void set_carYear(const int year){
            carYear = year;
        }
        void set_carNumberOfSeats(const int seats){
            carNumberOfSeats = seats;
        }
        void set_carTransmission(const string transmission){
            carTransmission = transmission;
        }
        void set_carHourlyRate(const double rate){
            carHourlyRate = rate;
        } 

        void set_renterID(const string renter_username){
            renterID = renter_username;
        }

        void set_loanerID(const string loaner_username){
            loanerID = loaner_username;
        }

        //shows if car is available or not
        string status();

        //changes a Car status from available to unavailable  
        void rent();
        //changes a Car status from unavailable to available  
        void return_car();

        //dispalys car
        void display();

        //destructor
        //~Car() = delete;
    
};

#endif