// File Name: WheatHarvest.cpp
// Author: James Meli
// Student ID: a738m747
// Assignment Number: 3

//Importing all neccessary libraries and files
#include<iostream>
#include<string>
#include<vector>
#include "Ticket.hpp"
using namespace std;

int main(void) {
  //Declaring a vector to hold the list of tickets
  vector<Ticket> tickets;

  cout << "Welcome start entering the data for each ticket." << endl;

  //Integer to count the number of tickets entered
  int ticketCount = 1;

  //Variable to count number of duplicates
  int duplicate = 0;

  //This variable controls whether the user wants to enter a new ticket or not
  char x;

  //Loop for user to enter all the tickets
  do {

    //Declaring all neccessary variables to store data for each ticket
    string ticketNumber;
    float grossWeight, tareWeight;
    float moistureLevel, foreignMaterial;
    cout << "\nTicket number " << ticketCount << " (alphanumerical): ";
    cin >> ticketNumber;
    cout << "Gross weight (lbs): ";
    cin >> grossWeight;
    cout << "Tare weight (lbs): ";
    cin >> tareWeight;
    cout << "Moisture level(%): ";
    cin >> moistureLevel;
    cout << "Foreign material(%): ";
    cin >> foreignMaterial;

    //New ticket is created
    Ticket ticket(ticketNumber, grossWeight, tareWeight, moistureLevel, foreignMaterial);

    //Checking for duplicate ticket
    for(int i = 0; i < tickets.size(); i++) {
      if(ticket == tickets[i]) {
         duplicate += 1;
      }
    }
    if(duplicate == 0) {
      //Ticket is added to the list
      tickets.push_back(ticket);
      ticketCount += 1;
    } else {
      cout << "Sorry a ticket already exists with this number. Please enter a different number" << endl;
    }
    duplicate = 0;
    cout << "Enter new ticket ? ('Y' or 'y' for yes, 'N' or 'n' for no): ";
    cin >> x;
  } while(x == 'Y' || x == 'y');

  //Variables to hold total gross bushels and total net brushels
  float totGrossBushels = 0;
  float totNetBushels = 0;

  //Loop to process all the tickets and print out their data
  for(int i = 0; i < tickets.size(); i++) {
    cout << tickets[i];
    totGrossBushels += tickets[i].calGrosBushels();
    totNetBushels += tickets[i].calNetBushels();
  }

  //Printing out the total gross bushels and total net brushels
  cout << "\nWheat harvest summary" << endl;
  cout << "\t" << totGrossBushels << " Gross bushels" << endl;
  cout << "\t" << totNetBushels << " Net bushels" << endl;

  return 0;
}
