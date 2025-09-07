#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include "../header/account.h"

using namespace std;

Account::Account()
{

    username = "";
    password = ""; 
    driverID = "";
    userType = "";
    balance = 0.0;

}

//void Account::DeleteAllAccounts() 
// {
//     string filename = "files/loginData.txt";  // Declare and initialize filename

//     // Open the input file for reading
//     ifstream inputFile(filename);

//     if (!inputFile.is_open()) 
//     {
//         cout << "Error opening file: " << filename << endl;
//         return;
//     }

//     // Open the output file for writing (truncate it to erase all content)
//     ofstream outputFile(filename, ofstream::trunc);

//     if (!outputFile.is_open()) 
//     {
//         cerr << "Error opening file for writing: " << filename << endl;
//         return;
//     }

//     // Inform the user that all accounts will be deleted
//     cout << "Deleting all accounts..." << endl;

//     // Close the files to ensure changes are saved
//     inputFile.close();
//     outputFile.close();

//     cout << "All accounts deleted successfully." << endl;
// }

Account::Account(string givenUsername, string givenPass, string givenDriverID, string givenUserType, double givenBalance)
{
    // ofstream outfile;

    // outfile.open("../files/loginData.txt");

    // if (!outfile.is_open())
    // {
    //     cout << "Error opening file loginData.txt" << endl;
    //     return;
    // }

    username = givenUsername;
    password = givenPass;
    driverID = givenDriverID;
    userType = givenUserType;
    balance = givenBalance;

    // outfile << username << "," << password << "," << driverID << "," << userType << "," << balance << endl;

    // outfile.close();
}

void Account::deleteAccount(const string& username, const string& password) 
{
    string filename = "files/loginData.txt";  // Declare and initialize filename
    
    ifstream inputFile(filename);

    if (!inputFile.is_open()) 
    {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    vector<string> lines;
    string currentLine;
    
    // Read all lines into a vector
    while (getline(inputFile, currentLine)) 
    {
        lines.push_back(currentLine);
    }

    // Find and remove the line with matching username and password
    for (auto i = lines.begin(); i != lines.end(); i++) 
    {
        istringstream lineStream(*i);
        string storedUsername, storedPassword;

        if (lineStream >> storedUsername >> storedPassword) 
        {
            if (storedUsername == username && storedPassword == password) 
            {
                lines.erase(i);

                // Write the modified content back to the original file
                ofstream outputFile(filename);
                if (!outputFile.is_open()) 
                {
                    cerr << "Error opening file for writing: " << filename << endl;
                    return;
                }

                // Write each line back to the file
                for (const auto& line : lines) 
                {
                    outputFile << line << '\n';
                }

                cout << "Account deleted successfully." << endl;
                return;
            }
        }
    }

    cout << "Account not found in the file." << endl;
}

void Account::setUsername(string givenUsername)
{
    username = givenUsername;
}

void Account::setPassword(string givenPassword)
{
    password = givenPassword;
}

void Account::setDriverID(string givenID)
{
    driverID = givenID;
}

void Account::setUserType(string givenUserType)
{
    userType = givenUserType;
}

void Account::setBalance(double givenBalance)
{
    balance = givenBalance;
}

void Account::registerUser()
{
    string givenUsername, givenPassword,givenDriverID,givenUserType;
    bool userNameSet = false;

    cout << "Enter your desired Username (without spaces and contain more than 5 Characters): ";

    while (userNameSet == false)
    {
        cin >> givenUsername;
        cout << endl;

        if(isUserNameValid(givenUsername) == true)
        {
            setUsername(givenUsername);
            userNameSet = true;
        }
        else
        {
            cout << "Try a different username as it is already taken." << endl;
            cout << endl;
            cout << "Enter your desired Username (without spaces and contain more than 5 Characters): ";
        }
    }

    cout << "Password requirements:" << endl;
    cout << "  - At least 8 characters" << endl;
    cout << "  - Contains both uppercase and lowercase letters" << endl;
    cout << "  - Contains at least one digit" << endl;
    cout << "  - Contains at least one special character (e.g., !@#$%^&*)" << endl;
    cout << "  - Should not contain spaces" << endl;
    cout << "Enter your Password: ";

    bool passwordSet = false;

    while(passwordSet == false)
    {
        cin >> givenPassword;
        cout << endl;

        if (isPasswordValid(givenPassword) == true)
        {
            setPassword(givenPassword);
            cout << "User has succesfully been added to the system" << endl;
            passwordSet = true;
        }
        else
        {
            cout << "Weak Password" << endl;
            cout << endl;
            cout << "Password requirements:" << endl;
            cout << "  - At least 8 characters" << endl;
            cout << "  - Contains both uppercase and lowercase letters" << endl;
            cout << "  - Contains at least one digit" << endl;
            cout << "  - Contains at least one special character (e.g., !@#$%^&*)" << endl;
            cout << "  - Should not contain spaces" << endl;
            cout << "Enter your Password: ";
        }
    }
    bool driverIDSet = false;
    while(driverIDSet == false)
    {
        cout << "DriverID must meet the following requirements:" << endl;
        cout << "- Should consist of more than 4 capital letters." << endl;
        cout << "- Should contain more than 3 numerical digits." << endl;
        cout << "Enter your DriverID: ";
        cin >> givenDriverID;
        cout << endl;
        if (isDriverIDValid(givenDriverID) == true)
        {
            driverID = givenDriverID;
            driverIDSet = true;
        }
        else
        {
            cout << "Invalid DriverID." << endl;
            cout << endl;
        }

    }
    while(true)
    {
        cout << "Choose an option to either Loan or Rent a Car:" << endl;
        cout << "Loaner - Enter 'Loaner'" << endl;
        cout << "Renter - Press 'Renter'" << endl;
        cout << "Enter your UserType: ";
        cin >> givenUserType;
        cout << endl;

        if(givenUserType == "Loaner" || givenUserType == "Renter")
        {
            userType = givenUserType;
            break;
        }
        else
        {
            cout << "Invalid input.Please try again" << endl;
            cout << endl;
        }
    }
    return;
}

void Account::loginUser()
{
    string givenUsername, givenPassword;
    ifstream infile;
    string tempUser,tempPass,tempDriverID,tempUserType;
    double tempBal;
    bool loginChecker = false;

    while (loginChecker == false)
    {
        cout << "Enter Username: ";
        cin >> givenUsername;
        cout << endl;
        cout << "Enter Password: ";
        cin >> givenPassword;
        cout << endl;

        infile.open("files/loginData.txt");

        if (!infile.is_open())
        {
            cout << "Error opening file loginData.txt" << endl;
            return;
        }

        while(infile >> tempUser >> tempPass >> tempDriverID >> tempUserType >> tempBal)
        {
            if (tempUser == givenUsername && tempPass == givenPassword)
            {
                cout << "Login successful" << endl;
                username = tempUser;
                password = tempPass;
                driverID = tempDriverID;
                userType = tempUserType;
                balance = tempBal;

                loginChecker = true;
            }
            if (!infile.eof())
            {
                infile.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        if (loginChecker == false)
        {
            cout << "Login Failed Please Check your Username or Password" << endl;
        }
    }

    infile.close();
    return;
}

bool Account::isPasswordValid(const string& password) 
{
    // Define the regex pattern for a strong password
    // At least 8 characters
    // Contains both uppercase and lowercase letters
    // Contains at least one digit
    // Contains at least one special character (e.g., !@#$%^&*)
    regex pattern("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[@$!%*?&])[A-Za-z\\d@$!%*?&]{8,}$");

    // Check if the password matches the pattern
    return regex_match(password, pattern);
}

bool Account::isUserNameValid(string checkUsername)
{
    string tempUsername,tempPassword,tempDriverID,tempUserType,TempBalance;
    ifstream infile;

    //To check if the username has more than 5 characters
    if(checkUsername.length() < 5)
    {
        cout << "Username should contain more than 5 characters" << endl;
        return false;
    }

    infile.open("files/loginData.txt");

    if (!infile.is_open())
    {
        cout << "Error opening file loginData.txt" << endl;
    }

    while(infile >> tempUsername >> tempPassword >> tempDriverID >> tempUserType >> TempBalance)
    {
        //To check if the username already exists in the database
        if(tempUsername == checkUsername)
        {
            return false;
        }
        if (!infile.eof())
        {
            infile.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    infile.close();

    //If we dont find any instance of a previous username having it we return true
    return true;
}

bool Account::isDriverIDValid(const string& driverID) 
{
    // Define the regex pattern
    regex pattern("[A-Z]{4,}[0-9]{3,}");

    // Use regex_match to check if the driverID matches the pattern
    return regex_match(driverID, pattern);
}
