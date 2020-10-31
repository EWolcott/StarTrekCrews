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

#include "Officer.h"
#include "Captain.h"
#include "Commander.h"
#include "Counselor.h"
#include "Ensign.h"
#include "Lieutenant.h"
#include "LtCommander.h"

//////////////////////////////////////////////////////////////////////////////////////
// Officer Member functions
//////////////////////////////////////////////////////////////////////////////////////

// Create a default Officer
Officer::Officer()
{
  name_ = "undefined";
  age_ = -1;
}

// Create an officer with Name, Rank and Age.
// Valid Ranks for now: "Crewman", "Ensign","Commander","Captain"
Officer::Officer(string Name, int Age)
{
  name_ = Name;
  age_ = Age;
}

// Return the name of the officer
string Officer::GetName()
{
  return name_;
}

// Return the age of the officer
int Officer::GetAge()
{
  return age_;
}

// Allow derived classes to set name when constructed
void Officer::setName(string n)
{
  name_ = n;
}

// Allow derived classes to set age when constructed
void Officer::setAge(double a)
{
  age_ = a;
}

//////////////////////////////////////////////////////////////////////////////////////
// Global functions for an Officer
//////////////////////////////////////////////////////////////////////////////////////

// Factory function for making officers
Officer *MakeOfficer(string rank, string name, double age)
{
  // factory for making the officer
  Officer *optr = NULL;
  if (rank == "Captain")
    optr = new Captain(name, age);
  else if (rank == "Commander")
    optr = new Commander(name, age);
  else if (rank == "Counselor/Commander")
    optr = new Counselor(name, age);
  else if (rank == "Ensign")
    optr = new Ensign(name, age);
  else if (rank == "Lieutenant")
    optr = new Lieutenant(name, age);
  else if (rank == "Lt. Commander")
    optr = new LtCommander(name, age);
  else
  {
    cerr << "Error: Parsing ship file failed. Unknown rank " << rank << endl;
    exit(-1);
  }
  return optr;
}

// overloaded operator to output an officer to a stream
ostream &operator<<(ostream &os, Officer *o)
{
  os << "Rank : " << o->GetRank() << endl;
  os << "Name : " << o->GetName() << endl;
  os << "Age  : " << o->GetAge();
  return os;
}

// input an officer from a string
istream &operator>>(istream &is, Officer *&po)
{
  string strank, stname, colon, stage, realrank, realname;
  double doage;
  is >> strank >> colon >> ws; //read rank
  getline(is, realrank);       //get rank
  is >> stname >> colon >> ws; //read name
  getline(is, realname);       //get name
  is >> stage >> colon >> ws;  //read age
  is >> doage;                 //get age

  po = MakeOfficer(realrank, realname, doage); //build the officer and assign it to the pointer

  return is; //send the istream back for further reading.
}
