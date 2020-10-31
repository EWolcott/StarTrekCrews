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

#pragma once
#include "Commander.h"

// TODO
class Counselor : public Commander
{
public:
    // Create a default Counselor
    Counselor()
    {
        rank_ = "Counselor/Commander";
        setName("undefined");
        setAge(0.0);
    }

    // Create an Counselor with Name, Rank and Age.
    Counselor(string name, double age)
    {
        rank_ = "Counselor/Commander";
        setName(name);
        setAge(age);
    }

    //returns the rank
    string GetRank()
    {
        return rank_;
    }
    //returns the title
    string GetTitle()
    {
        return rank_ + " " + GetName();
    }

private:
    string rank_;
};