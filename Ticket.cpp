// File Name: Ticket.cpp
// Author: James Meli
// Student ID: a738m747
// Assignment Number: 3

//Importing all neccessary libraries
#include <string>
#include <iostream>
#include "Ticket.hpp"
using namespace std;

namespace {
  const float TEST_WEIGHT_PER_BUSHEL = 60;
  const float IDEAL_MOISTURE_LEVEL = 12;
}

//Default constructor
 Ticket::Ticket()
 {
  ticketNumber = "";
  grossWeight = 0;
  tareWeight = 0;
  moistureLevel = 0;
  foreignMaterial = 0;
}

//Custom constructor
 Ticket::Ticket(string number, float grossWeight, float tareWeight, float moistureLevel, float foreignMaterial)
  : ticketNumber(number), grossWeight(grossWeight), tareWeight(tareWeight), moistureLevel(moistureLevel), foreignMaterial(foreignMaterial)
  {}

  bool operator== (Ticket &t1, Ticket &t2)
  {
    return (t1.getTicketNumber() == t2.getTicketNumber());
  }

  ostream& operator<< (ostream &out, Ticket &t)
  {
    out << t.toString();
    return out;
  }

//Returns the ticket number
string Ticket::getTicketNumber()
{
  return ticketNumber;
}
//Returns the gross weight
float Ticket::getGrossWeight()
{
  return grossWeight;
}
//Returns the tare weight
float Ticket::getTareWeight()
{
  return tareWeight;
}
//Returns the moisture level
float Ticket::getMoistureLevel()
{
  return moistureLevel;
}
//Returns the foreign material
float Ticket::getForeignMaterial()
{
  return foreignMaterial;
}

//Calculates the net weight
float Ticket::calNetWeight()
{
  netWeight = grossWeight - tareWeight;
  return netWeight;
}
//Calculates the gross bushels
float Ticket::calGrosBushels()
{
  grossBushels = netWeight / TEST_WEIGHT_PER_BUSHEL;
  return grossBushels;
}
//Calculates the moisture dockage
float Ticket::calMoistureDockage()
{
  if(moistureLevel < 12)
    return 0;
  else
    moistureDockage = grossBushels * ((moistureLevel/100) - (IDEAL_MOISTURE_LEVEL/100));
    return moistureDockage;
}
//Calculates the net bushels
float Ticket::calNetBushels()
{
  netBushels = grossBushels - moistureDockage - foreignMaterialDockage;
  return netBushels;
}
//Calculates the foreign material dockage
float Ticket::calForeignMaterialDockage()
{
  foreignMaterialDockage = grossBushels * (foreignMaterial / 100);
  return foreignMaterialDockage;
}

string Ticket::toString()
{
  return (
    "\nTicket " + ticketNumber + ":\n" +
    "\t" + to_string(grossWeight) + " Gross Weight\n" +
    "\t" + to_string(tareWeight) + " Tare Weight\n" +
    "\t" + to_string(this->calNetWeight()) + " Net Weight\n\n" +
    "\t" + to_string(this->calGrosBushels()) + " Gross Bushels\n" +
    "\t" + to_string(this->calMoistureDockage()) + " Moisture Level" + "(" + to_string(moistureLevel) + "%)\n" +
    "\t" + to_string(this->calForeignMaterialDockage()) + " Foreign Material" + "(" + to_string(foreignMaterial) + "%)\n" +
    "\t" + to_string(this->calNetBushels()) + " Net Bushels\n"
  );
}
