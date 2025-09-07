#include "../header/CarLoaner.h"
using namespace std;

CarLoaner::CarLoaner()
{ }


void CarLoaner::viewAllCars(CarAccess& carAccessObj)
{
    for (int i = 0; i < carAccessObj.cars.size(); i++) {
        carAccessObj.cars[i].display();
    }
}

void CarLoaner::viewAllMyCars(CarAccess& carAccessObj){
    for (int i = 0; i < carAccessObj.cars.size(); i++) {
        if (carAccessObj.cars[i].get_loanerID() == this->getUsername()) {
            carAccessObj.cars[i].display();
        }
    }
}

void CarLoaner::viewCarsByStatus(CarAccess& carAccessObj, std::string& carStatus)
{
    if (carStatus != "available" && carStatus != "unavailable") {
        cout << "Invalid car status. Please provide 'available' or 'unavailable'." << endl;
        return;
    }

    for (int i = 0; i < carAccessObj.cars.size(); i++) {
        if (carAccessObj.cars[i].status() == carStatus) {
            carAccessObj.cars[i].display();
        }
    }
}


void CarLoaner::addCar(CarAccess& carAccessObj, string carID, string carMake, string carModel, string carColor, 
    int carYear, int carNumOfSeats, string carTransmission, double carHourlyRate, const string loaner_id)
{
    string renter_id = "none";
    Car newCar(carID, carMake, carModel, carColor, carYear, carNumOfSeats, carTransmission, carHourlyRate, renter_id,
        loaner_id);

    // cars_hold = vector inside CarAccess class 
    auto& cars_hold = carAccessObj.cars;
    // check if car already exists in the vector. if it does then prompt the user to try again.
    for(auto& cars : cars_hold) {
        if(cars.get_carID() == carID) {
            cout << "This car ID already exists, please try again." << endl;
            return;
        }
    }

    carAccessObj.push_back(newCar);
    cout << "Your car has been successfully added\n";
}

void CarLoaner::removeCar(CarAccess& carAccessObj, const string& carID)
{
    auto& cars_iter = carAccessObj.cars;

    for (auto it = cars_iter.begin(); it != cars_iter.end(); ++it) {
        if (it->get_carID() == carID) {
            cars_iter.erase(it);
            cout << "Car with ID " << carID << " has been removed." << endl;
            return;
        }
    }
    
    cout << "\nCar with ID " << carID << " not found." << endl;
}

