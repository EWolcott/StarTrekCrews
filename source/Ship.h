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

#ifndef _Ship_H_
#define _Ship_H_
#include "Officer.h"
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

class Ship
{

private:
    string class_;
    string reg_number_;
    double mass_;
    vector<Officer *> officers_;
    // Max number of officers allowed: Added to avoid magic constants in code
    static const int max_officers_ = 5;

public:
    // Default constructor
    Ship() : class_(""), reg_number_(""), mass_(0) {}

    // Class, registry and mass in metric tons
    Ship(string ShipClass, string RegNumber, double Mass);

    // Add an officer if possible add an officer or return false if no room
    bool AddOfficer(Officer *officer);

    // Return rank of officer or "not found"
    string GetOfficerRank(string name);

    // Return the count of officers with a given rank
    int CountRank(string Rank);

    // Return the sum of all the ages of the crew
    int GetTotalCrewAge();

    // Sort all the crew on the ship
    void Sort();

    // Global opertor to output a ship to a stream
    friend ostream &operator<<(ostream &os, Ship *&s);

    // Global operator to input a ship from a stream
    friend istream &operator>>(istream &is, Ship *&s);
};

#endif