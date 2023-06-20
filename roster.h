#ifndef ROSTER_H
#define ROSTER_H
#include <iostream>
#include <string>
#include <array>
#include "degree.h"
#include "student.h"

using namespace std;

class Roster {

  public:

    int lastIndex = -1;
    const static int rosterSize = 5;
    Student* classRosterArray[rosterSize];

    void parse(string studentData);
    void add(string studentID, string firstName, string lastName, string email, int age, int DaysInCourse1, int DaysInCourse2, int       
    DaysInCourse3, DegreeProgram degreeprogram);
    void remove(string studentID);
    void printAll();
    void printaverageDaysInCourse(string studentID);
    void printinvalidEmails();
    void printbyDegreeProgram(DegreeProgram degreeprogram);
    ~Roster();

};

#endif