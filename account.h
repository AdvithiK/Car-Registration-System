#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <string>
#include <regex>
#include <fstream>

using namespace std;
//Make account class virtual aka it needs to talk with car renter and car loaner make it protected
class Account
{
    // friend class CarAccess;
private:
    string username;
    string password;
    string driverID;
    string userType;
    double balance;

public:
    //Default Constructor
    Account();
    //Destructor which deletes all accounts in the file
    //void DeleteAllAccounts();
    //Parameterized constructor
    Account(string,string,string,string,double);
    // Removes a user from the system.
    void deleteAccount(const string& username, const string& password);
    //Setting the Username
    virtual void setUsername(string);
    //Setting the Password
    virtual void setPassword(string);
    //Setting the Driver ID
    virtual void setDriverID(string);
    //Setting the UserType for renting a car or loaning a car
    virtual void setUserType(string);
    //Setting the Balance
    virtual void setBalance(double);
    //Retriving the Username
    virtual string getUsername() const {return username;}
    //Retriving the Password
    virtual string getPassword() const {return password;}
    //Retriving the Driver ID
    virtual string getDriverID() const {return driverID;}
    //Retriving the UserType
    virtual string getUserType() const {return userType;}
    //Retriving the Balance
    virtual double getBalance() const {return balance;}
    // Adds a new user to the system.
    void registerUser();
    // Checks if the user is registered in the system.
    void loginUser(); 
    // Verifies if the password meets the criteria for a strong password.
    bool isPasswordValid(const string& password);
    // Checks whether a username is already in use.
    virtual bool isUserNameValid(string);
    // Validates if the given driver ID follows the pattern: at least 4 uppercase letters followed by 3 or more numerical digits.
    bool isDriverIDValid(const string&); 
};

#endif