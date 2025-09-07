#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "../header/Car.h"
#include "../header/account.h"
#include "../header/CarRenter.h"
#include "../header/CarAccess.h"
#include "../header/CarLoaner.h"
#include "../header/Transaction.h"

using namespace std;



void DisplayRenterMenu(CarRenter& renter1, CarAccess &rent_car, int& choice);
void DisplayLoanerMenu(CarLoaner& loaner1, CarAccess &rent_car, int& choice);

int main () {
    Account myAccount;
    CarAccess rent_car; 
    int choice = 0;
    //string car_id;
    string user_type;
    string userid;
    string userLoginChoice;

    rent_car.populateAccountVector(myAccount);
    rent_car.populateTransactionsVector();
    rent_car.populateCarVector();

    cout << "WELCOME TO RENT-A-CAR!\n" << endl;
    cout << "Would you like to register (Enter \"register\") as a user or login (Enter \"login\")?: ";
    cin >> userLoginChoice;

    if(userLoginChoice == "register"){
        myAccount.registerUser();
    }
    else if(userLoginChoice == "login"){
        cout << "Welcome back! " << endl;
    }
    else{
        cout << "Invalid Option" << endl;
        exit(0);
    }

    cout << "Are you a renter or a loaner today?: ";
    cin >> user_type;
    cout << endl;
    cout << "Please enter your username: ";
    cin >> userid;
    if(user_type == "renter"){
        CarRenter renter1(userid);
        DisplayRenterMenu(renter1, rent_car, choice);
    }
    else if(user_type == "loaner"){
        CarLoaner loaner1(userid);
        DisplayLoanerMenu(loaner1, rent_car, choice);
    }
    else{
        exit(0);
    }
    return 0;
}

void DisplayRenterMenu(CarRenter& renter1, CarAccess &rent_car, int& choice) {

    string car_detail_choice;
    int car_int_detail;
    string car_string_detail;
    double min_price;
    double max_price;
    string car_id;
    double hours_rented;

    Transaction t;
    Car tempCar;
    
    while (choice != 7)
    {
        cout << "1. Browse all cars\n";
        cout << "2. Rent a Car\n";
        cout << "3. Return a Car\n";
        cout << "4. Search for a Car\n";
        cout << "5. Search for a Car within your Price Range\n";
        cout << "6. View Previous Transactions\n";
        cout << "7. Exit :D\n";
        cout << "Please enter your choice : ";
        cin >> choice;

        switch(choice) {
            case 1 : 
                renter1.browseCars(rent_car);
                break;
            case 2 :
                cout << "Enter the ID of the car you want to rent : ";
                cin >> car_id;
                cout << "Enter the number of hours you want to rent the car: ";
                cin >> hours_rented;
                renter1.rentACar(rent_car, car_id);
                tempCar = rent_car.findCar(car_id);
                // // Transaction* t = new Transaction(car_id, renter1.getUsername(), tempCar.get_loanerID(), 
                // //                                  tempCar.get_carHourlyRate(), hours_rented);
                t.setCarID(car_id);
                t.setRenterID(renter1.getUsername());
                cout << endl << renter1.getUsername() << endl << endl;
                t.setLoanerID(tempCar.get_loanerID());
                t.setHourlyPrice(tempCar.get_carHourlyRate());
                t.setHoursRented(hours_rented);
                t.setTotalAmount();
                rent_car.logTransaction(t);
                cout << "Thank you for renting the car! Here is your receipt: " << endl;
                t.displayTransaction();
                break;
            case 3 : 
                cout << "Enter the ID of the car you want to return : ";
                cin >> car_id;
                renter1.returnACar(rent_car, car_id);
                break;
            case 4 : 
                cout << "Select a type of feature to search all cars that match (ID, Make, Model, Color or Transmission, Year, or Number of Seats (enter \"NOB\" for this option)): ";
                cin >> car_detail_choice;

                if(car_detail_choice == "ID" || car_detail_choice == "Make" || car_detail_choice == "Model" || car_detail_choice == "Color" ||car_detail_choice == "Transmission"){
                    cout << "Enter the specific " + car_detail_choice + " you'd like to browse all cars in: ";
                    cin >> car_string_detail;
                    renter1.searchForACar(rent_car, car_string_detail);
                }
                else if(car_detail_choice == "Year" || car_detail_choice == "NOB"){
                    if(car_detail_choice == "NOB"){
                    cout << "Enter the specific number of seats you'd like to browse all cars in: ";
                    }
                    else{
                        cout << "Enter the specific " + car_detail_choice + " you'd like to browse all cars in: ";
                    }
                    cin >> car_int_detail;
                    renter1.searchForACar(rent_car, car_int_detail);
                }
                else{
                    cout << "Invalid Option. Please Search Again." << endl;
                    break;
                }
                break;
            case 5 : 
                cout << "Enter the minimum price by hour you'd like to see cars listed at: ";
                cin >> min_price;
                cout << "Enter the maximum price by hour you'd like to see cars listed at: ";
                cin >> max_price;
                renter1.searchForPriceRange(rent_car, min_price, max_price);
                break;
            case 6 : 
                cout << "Here are your previous transactions: " << endl;
                rent_car.getRenterTransactionHistory(renter1.getUsername());
                break;
            case 7 : 
                rent_car.populateAccountFile();
                rent_car.populateTransactionsFile();
                rent_car.CarVectorToFile();
                cout << "Exiting...\n";
                break;
            default :
                cout << "Invalid input, please try again.\n";
        }
    }
}

void DisplayLoanerMenu(CarLoaner& person1, CarAccess &rent_car, int& choice)
{
    string car_id, car_make, car_model, car_color, car_transmission, loanerID;
    int car_year, car_seats;
    double car_hourly_rate;
    
    // int choice = 0;
    string status_avail;

    cout << "Please choose one of the following" << endl;
    
    while (choice != 6)
    {
        cout << "\n1. Browse all cars\n";
        cout << "2. Browse available/unavailable cars\n";
        cout << "3. Browse all my cars\n";
        cout << "4. Add my car for rent\n";
        cout << "5. Remove my car\n";
        cout << "6. Exit :D\n";
        cout << "Enter your choice : ";
        cin >> choice;

        switch(choice) {
            case 1 : 
                person1.viewAllCars(rent_car);
                break;
            case 2 :
                cout << "Enter available or unavailable : \n";
                cin >> status_avail;
                person1.viewCarsByStatus(rent_car, status_avail);
                break;
            case 3 : 
                person1.viewAllMyCars(rent_car);
                break;
            case 4 :
                cout << "Enter your carID: ";
                cin >> car_id;
                cout << "Enter your car's make: ";
                cin >> car_make;
                cout << "Enter your car's model: ";
                cin >> car_model;
                cout << "Enter your car's color: ";
                cin >> car_color;
                cout << "Enter your car's year: ";
                while(!(cin >> car_year)) {
                    cout << "Invalid input, please enter a number: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cout << "Enter the number of car seats: ";
                while(!(cin >> car_seats)) {
                    cout << "Invalid input, please enter a number: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cout << "Enter your car's transmission: ";
                cin >> car_transmission;
                cout << "Enter your car's hourly rate: ";
                while(!(cin >> car_hourly_rate)) {
                    cout << "Invalid input, please enter a number: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cout << "Enter your loaner id: ";
                cin >> loanerID;
                
                person1.addCar(rent_car, car_id, car_make, car_model, car_color, car_year, car_seats, 
                car_transmission, car_hourly_rate, loanerID);
                break;
            case 5 :
                cout << "Enter carID of the car you would like to remove : ";
                cin >> car_id;
                person1.removeCar(rent_car, car_id);
                break;
            case 6 : 
                rent_car.populateAccountFile();
                rent_car.populateTransactionsFile();
                rent_car.CarVectorToFile();
                cout << "Exiting...\n";
                break;
            default :
                cout << "Invalid input, please try again.\n";
        }
    }
}