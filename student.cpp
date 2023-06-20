#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"
using namespace std;


Student::Student(){
  this->studentID = "";
  this->firstName = "";
  this->lastName = "";
  this->email = "";
  this->age = 0; 

  for (int i = 0; i < DaysInCourseSize; i++)
    this->DaysInCourse[i] = 0;

  this->degreeprogram;
  
}

Student::Student(string studentID, string firstName, string lastName, string email, int age, int DaysInCourse[], DegreeProgram degreeprogram){

  this->studentID = studentID;
  this->firstName = firstName;
  this->lastName = lastName;
  this->email = email;
  this->age = age; 

  for (int i = 0; i < DaysInCourseSize; i++)
    this->DaysInCourse[i] = DaysInCourse[i];

  this->degreeprogram = degreeprogram;
  }

//get
string Student::getstudentID() {return studentID; }
string Student::getfirstName() {return firstName; }
string Student::getlastName() {return lastName; }
string Student::getemail() {return email; }
int Student::getage() {return age; }
const int* Student::getDaysInCourse() {return this->DaysInCourse; }
DegreeProgram Student::getdegreeprogram() {return this-> degreeprogram; }
//set
void Student::setstudentID(string studentID) {this->studentID = studentID;}
void Student::setfirstName(string fristName) {this->firstName = firstName;}
void Student::setlastName(string lastName) {this->lastName = lastName;}
void Student::setemail(string email) {this->email = email;}
void Student::setage(int age) {this->age = age;}
  
void Student::setDaysInCourse(const int DaysInCourse[]){
  for(int i = 0; i < DaysInCourseSize; i++)
    this->DaysInCourse[i] = DaysInCourse[i];
}
void Student::setdegreeprogram(DegreeProgram degreepm) { this-> degreeprogram = degreepm; };
//print
void Student::printstuID() { cout << studentID << endl; return; }
void Student::printfirstName() { cout << firstName << endl; return; }
void Student::printlastName() { cout << lastName << endl; return; }
void Student::printemail() { cout << email << endl; return; }
void Student::printage() { cout << age << endl; return; }
void Student::printdegreeprogram() {
  string degree;
  if (degreeprogram == SECURITY) {
    degree = "SECURITY";
  }
  else if (degreeprogram == NETWORK) {
    degree = "NETWORK";
  }
  else if (degreeprogram == SOFTWARE) {
    degree = "SOFTWARE";
  }
}

void Student::print(){
  string degree;
  if (degreeprogram == SECURITY) {
    degree = "SECURITY";
  }
  else if (degreeprogram == NETWORK) {
    degree = "NETWORK";
  }
  else if (degreeprogram == SOFTWARE) {
    degree = "SOFTWARE";
  }
  cout << this->studentID << "\t"
       << this->firstName << "\t"
       << this-> lastName << "\t"
       << this->age << "\t"
       << this->DaysInCourse[0] << "\t"
       << this->DaysInCourse[1] << "\t"
       << this->DaysInCourse[2] << "\t"
       << degree
       << endl;
}