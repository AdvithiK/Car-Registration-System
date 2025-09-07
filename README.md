# Car Rental System
 Authors: [Gokul Nookula](https://github.com/GokulNookula) , 
          [Kalyani Mantirraju](https://github.com/klynmnti) , 
          [Advithi Kethidi](https://github.com/AdvithiK) , 
          [Sneha Gurung](https://github.com/sneha-grg)

## Project Description
   * In this project we are going to be developing a car rental system that allows users to rent a car from a select number of options for cars as well as provides the choice for the user to provide their car to be rented. We found this to be interesting because as college students who don't own cars, we've faced issues with existing car rental systems such as there not being enough time to rent the car, no cars available, and such issues so we thought creating a car rental system would be cool as we would be able to add our own perspectives on what features we would like on the system. Features we would like to see are the type of cars, number of seats, and more cars available by incorporating the option for some users to give their car for rent too.

   * The language we plan on using for the project is C++. 

   * The input for the project will be a user's login information and their choice to either rent a car or provide the details to give their own car for rent on the system. The output will be list of cars they have rented or have given for rent as well as the cost associated either renting or giving the car for rent. Our goal for the output is to create a log in system where the user's information is stored as well as store information about the cars they have inputted into the system. 


   * Create Account/Login page: This will allow the user to input their information and create an account on the system as well as be able to access the system via logging in with a username and password.
   * Rent a Car feature: This will allow the user to access a list of cars available for rent and let the user choose the car of their choice and will remove that car from the list for the duration the car is being rented for. Users can specifiy the number of people they'll require seating for in the car as well as be able to set a minimum and maximum price they would like to see the available cars being given rent at, as well as other car preferences such as car type. 
   * Give a Car for Rent feature: This will allow for the user to give their car for rent by filling out information regarding their car and will put the car on the list of cars available to rent. Users can set a price that they would like to rent their car at as well as set the desired number of people allowed in the car. 
   * Cars being Rented Page: This is a page that will show all the cars that have been rented by, is currently being rented, and from the user depending on whether they are renting a car or giving a car for rent. This feature will allow users to view their past rented cars as well as have the option to delete and past rentals from the list. This page will also display the price that the cars were rented at both both the renters end and the car loaners end.
   * Transaction feature: This is a feature that will be on both user ends for those that want to rent a car or give a car for rent where they will be able to see how much money they are giving/recieving and will be able to track the expenses as well as handle refunds and recieve a log of reciepts for every transaction. 

 ## Phase II
  In addition to completing the "User Interface Specification" and "Class Diagram" sections below, you will need to:
  * Create an "Epic" (note) for each feature. Place these epics in the `Product Backlog` column
  * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
    * Break down the "Epics" into smaller actionable user stories (i.e. smaller development tasks). Convert them into issues and assign them to team members. Place these in the `TODO` (aka Sprint Backlog) column.
    * These cards should represent roughly 7 days worth of development time for your team. Then, once the sprint is over you should be repeating these steps to plan a new sprint, taking you until your second scrum meeting with the reader in phase III.
  * Schedule two check-ins using Calendly. You need to pick both time slots on Tuesday of week 6. The check-ins will occur on Zoom. Your entire team must be present for both check-ins.
    * The first check-in needs to be scheduled with your lab TA. During that meeting, you will discuss your project design/class diagram from phase II.
   * The second check-in should be scheduled with a reader. During that meeting you will discuss:
      * The tasks you are planning for the first sprint
      * How work will be divided between the team members

## User Interface Specification

### Navigation Diagram
 The navigation diagram includes the different options that a user will have upon opening the car rental system. When the user opens the service, they will first be prompted to either login to an existing account or create a new account. Once they are logged in, they are provided with a menu of options, which vary depending on if they are a renting user or a loaning user.
 
![CS100NavigationDiagram](https://github.com/cs100/final-project-aketh002-kmant009-sguru004-gnook002/assets/146130597/7168fed0-845f-48cf-ae26-a007c5b7b4be)

### Screen Layouts
The first screen starts off as a login page and prompts the user to either enter their login or to create an account. Then, the user is shown the Menu where the user can select one out of the many options that will further guide them through browsing cars, giving a car for rent, renting cars, or viewing transactions. In the Browse Cars page, users can view all cars in the system and select a car to book. In the Add a Car for Rent page, users wanting to rent a car can input a description of their car details and be guided to the View Rented Cars Page where they can see all cars they own and which ones are being rented. It also has a subpage that is more specified to display only cars that are currently being rented instead of all cars they own. There is also a transactions page for users to view all cars that have been rented with informations on the price and how much the rented car costed. 

![CS100 Screen Layout](https://github.com/cs100/final-project-aketh002-kmant009-sguru004-gnook002/assets/111548159/0a36f5f7-e22d-453b-87b2-3af0db007f48)


### Class Diagram

The UML Diagram consists of a Car class that displays all the different components of the car that may be of interest to the renter such as Make, Model, Year, Transmission, Hourly Rate and more. This class creates Car objects which Car Loaners have the ability to do and keep track of and also allows Car Renters to rent. The Account Class is an abstract class that contains all user information that Car Renters and Car Loaners share such as their accounts' balance, username, password, and userID. The CarLoaner class derives from the Account Class and is specific to Car Loaners and allows them access to add Cars, remove Cars, and view the status of their loaned Cars. The CarRenter class derives from the Account Class and specfically allows car renters to rent more cars, rent cars, return cars, search for Cars that match their preferences, search for Cars within their price range, and browse currently listed cars. The Transaction class keeps store of all the monetary transaction information between each specific car renter and car loaner as well as allows the transactions to take place and produces reciepts of them. 

![CarRegistrationUMLdrawio drawio (1)](https://github.com/cs100/final-project-aketh002-kmant009-sguru004-gnook002/assets/147006144/5b5edbbe-40b8-42cb-901d-4e41e6ec3e89)



SOLID:

* What SOLID principle(s) did you apply?
  Single Responsibility Principle (SRP): states that each class should have a single responsibility. Each responsibility should then be completely encapsulated by the class.
  Dependency Inversion Principle (DIP): states that high-level modules should not depend on low-level modules. Instead, these high and low-level modules should depend on abstractions. It is important to note that abstractions should not depend on details. Through the use of this principle, one is encouraged to implement abstractions such as abstract classes when creating classes. 
* How did you apply it? i.e. describe the change. In our Account class, we only allow the user to check their account info. This class prevents access to anything else, which ensures that the user can only perform one action in the Class. If the user wanted to perform another action, they would need to depend on the CarRenter class. This class' function just focuses on renting the car. Parts of the CarRenter class in turn rely on the Account class as user info is needed in order to rent a car. Through this dependency between class, Dependency Inversion Principle (DIP) is demonstrated.
* How did this change help you write better code?
  Applying Single Responsibility and Dependency Inversion Principles have significantly improved the quality of our code. The Single Responsibility Principle (SRP) allows for easier maintenance and better organization of code. When classes are created to focus on a single resposibility, they become easier to understand and maintain as there is only one component that they are focusing on. If there are any changes made in a class, such as the 'Account' class, other classes will not be affected. This principle also helps to create a more organized environment as it can reduce complexity, making it simple and organized and leading to fewer bugs to fix. The Dependency Inversion Principle (DIP) improves the flexibility of our code by depending on abstractions. Abstractions improve flexibility as code can be more easily implemented. One of the reasons why abstractions are so favored is because of their ability to prevent changes on higher level code when lower level code is altered. This can be reflected in our project as we can then change any implementation of the account class without affecting CarRenter as long as the new changes stick to the respective interface. 
 
 
 ## Screenshots
  Screenshots of the input/output after running your application
  ![Reigster User](https://github.com/cs100/final-project-aketh002-kmant009-sguru004-gnook002/assets/111548159/d8104384-929d-489d-8044-7686c0c05b30)
  ![Login User](https://github.com/cs100/final-project-aketh002-kmant009-sguru004-gnook002/assets/111548159/73d0252a-d71c-4d0b-a024-b904114d458b)
  <img width="931" alt="LoginCarLoaner" src="https://github.com/cs100/final-project-aketh002-kmant009-sguru004-gnook002/assets/147006144/5785ea6e-a9d3-4a62-8807-062c7a2aebf8">
<img width="931" alt="CarLoaner" src="https://github.com/cs100/final-project-aketh002-kmant009-sguru004-gnook002/assets/147006144/a4a87fc3-966d-4b82-874a-f2eaace9998d">
<img width="931" alt="LoginCarRenter" src="https://github.com/cs100/final-project-aketh002-kmant009-sguru004-gnook002/assets/147006144/5a786bbb-43e0-4760-a746-3317b43bb0a1">
<img width="931" alt="CarRenter" src="https://github.com/cs100/final-project-aketh002-kmant009-sguru004-gnook002/assets/147006144/0b728a6a-b8b0-4f24-b935-0821a5cdf88c">



 ## Installation/Usage
 1. Clone the link for the project by clicking on the green button saying "Code" found at the top right corner and copy and pasting it into your terminal stating $ git clone <repo> 
 2. Run the command ./main to run the program or ./testCar to run the tests for the program
 3. Enter "register" to make yourself an account and specify whether you'd like to be a Car Renter (view cars available to rent and rent a car) or a Car Loaner (add a car as an option to give for rent)
 4. In the Menu, as a Car Loaner, have the ability to add Cars, remove Cars, and view all the Cars you give for rent. In the Menu as a Car Renter, have the ability to rent a Car, return a Car, search for Cars that match your preferences (color, number of seats, make, model, etc...)  and search for Cars that match a given price range.
 5. Exit the program by selecting the corresponding number that matches the "Exit" option on the program. 
 ## Testing
  We each followed testing methods that were suitable for our working style and assigned epics. Our unit tests covered each function within the features and classes we created, and we also created larger tests that would ensure that our implemented features would work in harmony without problems. We used GTest for our smaller features and also created seperate tests in main to run the program and see what features needed to be changed. While we wrote many tests for all of our features, we made sure to follow the FIRST principles and focus on not having repetitive tests. Between bottom-up and top-down testing, we tended to choose bottom-up testing, so we didn't create many stubs or prototypes. We also did not use continuous integration with the master branch, and instead fully developed our features within our respective branches and merged towards the end.

## Project Board
Link: https://github.com/orgs/cs100/projects/329/views/1
