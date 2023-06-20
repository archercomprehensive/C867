#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include "degree.h"
#include <iostream>
#include <string>
using namespace std;


/*
For the Student class, do the following:
1.  In files student.h and student.cpp create the Student class, which includes each of the following variables:
•  student ID
•  first name
•   last name
•  email address
•  age
•  array of number of days to complete each course
•  degree program
2.  Create each of the following functions in the Student class:
a.  an accessor (i.e., getter) for each instance variable from part D1
b.  a mutator (i.e., setter) for each instance variable from part D1
c.  All external access and changes to any instance variables of the Student class must be done using accessor and mutator functions.
d.  constructor using all of the input parameters provided in the table
e.  print() to print specific student data
*/

class Student {
   public:

    const static int DaysInCourseSize = 3;

  private: 
    string studentID;
    string firstName;
    string lastName;
    string email;
    int age;
    int DaysInCourse[DaysInCourseSize];
    DegreeProgram degreeprogram;
  
  public:
    
    Student();
    Student(string studentID, string firstName, string lastName, string email, int age, int DaysInCourse[], DegreeProgram degreeprogram);

    //getters//
    string getstudentID();
    string getfirstName();
    string getlastName();
    string getemail();
    int getage();
    const int* getDaysInCourse();
    DegreeProgram getdegreeprogram();

    //setters//
    void setstudentID(string studentID);
    void setfirstName(string firstName);
    void setlastName(string lastName);
    void setemail(string email);
    void setage(int age);
    void setDaysInCourse(const int DaysInCourse[]);
    void setdegreeprogram(DegreeProgram degreeprogram);

    //print//
    void printstuID();
    void printfirstName();
    void printlastName();
    void printemail();
    void printage();
    void printdegreeprogram();
    void print();

};

#endif