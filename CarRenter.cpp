#include "../header/CarRenter.h"

CarRenter::CarRenter()
{ }

//parameterized constructor that is specific towards the users that are renters
CarRenter::CarRenter(string username, string password, string driverID, string userType){
    setUsername(username);
    setPassword(password);
    setDriverID(driverID);
    setUserType(userType);
}

void CarRenter::browseCars(CarAccess &carAccessObject)
{
    
    for(unsigned int i = 0; i < carAccessObject.cars.size(); ++i) {
        carAccessObject.cars.at(i).display();
    }
}

//changing balance in renter and status in car therefore not const
string CarRenter::rentACar(CarAccess &carAccessObject, const string& id)
{
    for(int i = 0; i < carAccessObject.cars.size(); i++){
        if(carAccessObject.cars.at(i).get_carID() == id){
            if(carAccessObject.cars.at(i).status() == "available"){
                carAccessObject.cars.at(i).rent();
                carAccessObject.cars.at(i).set_renterID(this->getUsername());
                return "You've rented Car " + carAccessObject.cars.at(i).get_carID() + ".";
            }
            else{
               return "Car " + carAccessObject.cars.at(i).get_carID() + " is unavailable to rent.";
            }
    
        }
    }
    return "Please select another Car to rent.";

}

string CarRenter::returnACar(CarAccess &carAccessObject, const string& id){
    for(int i = 0; i < carAccessObject.cars.size(); i++){
        if(carAccessObject.cars[i].get_carID() == id){
            if(carAccessObject.cars.at(i).status() == "unavailable"){
                carAccessObject.cars[i].return_car();
                carAccessObject.cars.at(i).set_renterID("none");
                return "You've returned Car " + carAccessObject.cars.at(i).get_carID() + ".";
            }
            else{
                return "Car " + carAccessObject.cars.at(i).get_carID() + " is available.";
            }
        }
    }
    return "Sorry, Car " + id + " does not exist in our system.";
}

void CarRenter::searchForACar(CarAccess &carAccessObject, const string& car_string_detail){
    bool searchCarVal = false;
    for(int i = 0; i < carAccessObject.cars.size(); i++){
        if(carAccessObject.cars[i].get_carID() == car_string_detail || 
        carAccessObject.cars[i].get_carMake() == car_string_detail || 
        carAccessObject.cars[i].get_carModel() == car_string_detail || 
        carAccessObject.cars[i].get_carColor() == car_string_detail || 
        carAccessObject.cars[i].get_carTransmission() == car_string_detail){
            carAccessObject.cars[i].display();
            searchCarVal = true;
        }
    }
    if (searchCarVal = false){
        cout << "Sorry, there are no cars that match your preferences currently.";
    }
}

void CarRenter::searchForACar(CarAccess &carAccessObject, const int& car_int_detail){
    bool searchCarVal = false;
    for(int i = 0; i < carAccessObject.cars.size(); i++){
        if(carAccessObject.cars[i].get_carYear() == car_int_detail || 
        carAccessObject.cars[i].get_carNumberOfSeats() == car_int_detail){
            carAccessObject.cars[i].display();
            searchCarVal = true;
        }
    }
    if (searchCarVal = false){
        cout << "Sorry, there are no cars that match your preferences currently.";
    }
}

void CarRenter::searchForPriceRange(CarAccess &carAccessObject, const double& min_price, const double& max_price){
    bool searchCarVal = false;
    for(int i = 0; i < carAccessObject.cars.size(); i++){
        if(carAccessObject.cars[i].get_carHourlyRate() >= min_price &&
        carAccessObject.cars[i].get_carHourlyRate() <= max_price){
            carAccessObject.cars[i].display();
            searchCarVal = true;
        }
    }
    if (searchCarVal = false){
        cout << "Sorry, there are no cars that match your preferences currently.";
    }
}
