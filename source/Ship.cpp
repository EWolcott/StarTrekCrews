// Signed: Ethan Wolcott
// Date: 11/24/2019
// Fall 2019
// CS 172 Exam 1
// I affirm that all code I generated for this project was written solely by me,
// and that any help I received was within the rules stated for this exam.
// I understand that any form of academic dishonesty on this exam will at a minimum
// result in a zero for this exam and a report to the Academic Dean which can have
// serious consequences for my future academic and professional career.
// Resources used: URL: cplusplus.com and our instructor

#include "Ship.h"

// Class, registry and mass in metric tons
Ship::Ship(string ShipClass, string RegNumber, double Mass)
{
  class_ = ShipClass;
  reg_number_ = RegNumber;
  mass_ = Mass;
}

// If possible add an officer or return false if no room
bool Ship::AddOfficer(Officer *officer)
{
  if (officers_.size() >= max_officers_)
    return false;
  officers_.push_back(officer);
  return true;
}

// Return rank of officer or "not found"
string Ship::GetOfficerRank(string Name)
{
  for (int i = 0; i < officers_.size(); i++)
  {
    if (officers_[i]->GetName() == Name)
      return officers_[i]->GetRank();
  }
  return string("not found");
}

// Return count of officers with a given rank
int Ship::CountRank(string Rank)
{
  int count = 0;
  for (int i = 0; i < officers_.size(); i++)
  {
    if (officers_[i]->GetRank() == Rank)
      count++;
  }
  return count;
}

// Sum all the ages of the crew
int Ship::GetTotalCrewAge()
{
  int total = 0;
  for (int i = 0; i < officers_.size(); i++)
  {
    total += officers_[i]->GetAge();
  }
  return total;
}

//compare the ranks and names of two passed officers
bool less_than(Officer *a, Officer *b)
{
  if (a->GetRank() < b->GetRank())
    return true;
  else if (a->GetRank() == b->GetRank() && a->GetName() < b->GetName())
    return true;
  else
    return false;
}

// Sort the officers on a ship
void Ship::Sort()
{
  sort(officers_.begin(), officers_.end(), less_than);
}

//////////////////////////////////////////////////////////////////////////////////////
// Global functions for a Ship
//////////////////////////////////////////////////////////////////////////////////////

// Output a ship to a stream
ostream &operator<<(ostream &os, Ship *&s)
{
  os << "Class : " << s->class_ << endl;
  os << "RegNumber : " << s->reg_number_ << endl;
  os << "Mass : " << s->mass_ << endl;
  os << "Crew : " << s->officers_.size() << endl;
  for (int i = 0; (i < (s->officers_.size() - 1)); i++)
    os << s->officers_[i] << endl;
  os << s->officers_[s->officers_.size() - 1] << endl;
  return os;
}

// Input a ship from a stream
istream &operator>>(istream &is, Ship *&s)
{
  string stclass, stregnumber, stmass, stcrew, colon;
  int num;
  is >> stclass >> colon >> ws;            // Read Class
  getline(is, s->class_);                  // get the ship classname
  is >> stregnumber >> colon >> ws;        // Read RegNumber
  getline(is, s->reg_number_);             // get the registration number
  is >> stmass >> colon >> ws >> s->mass_; // Read Mass
  is >> stcrew >> colon >> ws;             // Read Crew
  is >> num;
  // Read in all the officers
  for (int i = 0; i < num; i++)
  {
    Officer *po;
    is >> po;
    s->AddOfficer(po);
  }
  return is;
}
