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

#ifndef _Officer_H_
#define _Officer_H_
#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

class Officer
{

public:
    // Create a default Officer
    Officer();

    // Create an office with Name and Age.
    Officer(string Name, int Age);

    // Return the name of the officer
    string GetName();

    // Return combined string of Rank + Name
    virtual string GetTitle() = 0;

    // Return the rank of the officer
    virtual string GetRank() = 0;

    // Return the age of the officer
    int GetAge();

    // Allows derived classes to set name value
    void setName(string n);

    // Allows derived classes to set age value
    void setAge(double a);

    // output a Officer
    friend ostream &operator<<(ostream &os, Officer *o);

    friend istream &operator>>(istream &is, Officer *&po);

private:
    string name_;
    int age_;
};

#endif