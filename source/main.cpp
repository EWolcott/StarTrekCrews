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

#include <iostream>
#include <fstream>
#include "Officer.h"
#include "Captain.h"
#include "Commander.h"
#include "Counselor.h"
#include "Ensign.h"
#include "Lieutenant.h"
#include "LtCommander.h"
#include "Ship.h"
#include <vector>
using namespace std;

int main()
{
    // Note: All these tests must pass without modifying the code in this file

    // Vector to hold all the ships in the fleet
    vector<Ship *> starfleet;

    // Read in the all ships and officers from the file ship.dat
    ifstream fin("ships.dat");
    if (!fin)
    {
        cerr << "Error: Failed to open ships.dat" << endl;
    }
    string stships, colon;
    int num_ships;

    // Get the number of ships in the fleet
    fin >> ws >> stships >> colon >> ws >> num_ships;

    // Read in each ship from the file
    for (int i = 0; i < num_ships; i++)
    {
        Ship *tmp = new Ship();
        fin >> ws >> tmp; // Read in the ship
        starfleet.push_back(tmp);
    }

    // Close the file
    fin.close();

    // Check GetTotalCrewAge()
    int errors = 0;
    if (starfleet[0]->GetTotalCrewAge() != 152 || starfleet[1]->GetTotalCrewAge() != 133)
    {
        errors++;
        cerr << "error: GetTotalCrewAge() returning invalid total." << endl;
    }

    // Check GetOfficerRank() method
    int tmp = errors;
    if (starfleet[0]->GetOfficerRank("Jean-Luc Picard") != "Captain")
        errors++;
    if (starfleet[0]->GetOfficerRank("William Riker") != "Commander")
        errors++;
    if (starfleet[0]->GetOfficerRank("Data") != "Lt. Commander")
        errors++;
    if (starfleet[0]->GetOfficerRank("Deanna Troi") != "Counselor/Commander")
        errors++;

    if (starfleet[1]->GetOfficerRank("Tasha Yar") != "Lieutenant")
        errors++;
    if (starfleet[1]->GetOfficerRank("Geordi La Forge") != "Lt. Commander")
        errors++;
    if (starfleet[1]->GetOfficerRank("Dr. Beverly Crusher") != "Commander")
        errors++;
    if (starfleet[1]->GetOfficerRank("Worf") != "Lieutenant")
        errors++;

    if (errors > tmp)
        cerr << "error: GetOfficerRank() has an error." << endl;

    // Check CountRank() method
    int ranks = 0;
    for (int c = 0; c < 2; c++)
    {
        ranks += starfleet[c]->CountRank("Captain");
        ranks += starfleet[c]->CountRank("Commander");
        ranks += starfleet[c]->CountRank("Counselor/Commander");
        ranks += starfleet[c]->CountRank("Lieutenant");
        ranks += starfleet[c]->CountRank("Lt. Commander");
    }

    if (ranks != 8)
    {
        errors++;
        cerr << "error: CountRank() has an error." << endl;
    }

    // Check AddOfficer() method
    tmp = errors;
    for (int d = 0; d < 2; d++)
    {
        if (!starfleet[d]->AddOfficer(new Commander("One", 50)))
            errors++;
        if (starfleet[d]->AddOfficer(new Commander("Two", 50)))
            errors++;
    }
    if (tmp != errors)
        cerr << "error: AddOfficer has an error!" << endl;

    if (errors == 0)
        cout << "Passed all tests\n";
    else
        cout << "Errors: " << errors << endl;

    cout << endl
         << "Output ships with crew sorted: " << endl;

    // call the sort method for every starship
    for (int i = 0; i < starfleet.size(); i++)
    {
        starfleet[i]->Sort();
    }

    // Output first ship in sorted order
    cout << starfleet[0] << endl;

    // Output second ship in sorted order
    cout << starfleet[1] << endl;

    return 0;
}
