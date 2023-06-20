#include <iostream>
#include <string>
#include <array>
#include "roster.h"
#include "degree.h"
#include "student.h"

using namespace std;


void Roster::parse(string student){
    
    int right = student.find(",");
    string sID = student.substr(0, right);
    
    int left = right + 1;
    right = student.find(",", left);
    string fname = student.substr(left, right - left);
  
    left = right + 1;
    right = student.find(",", left);
    string lname = student.substr(left, right - left);
  
    left = right + 1;
    right = student.find(",", left);
    string smail = student.substr(left, right - left);
  
    left = right + 1;
    right = student.find(",", left);
    int sage = stoi(student.substr(left, right - left));
  
    int dic[3];
    for (int i = 0; i < 3; i++){
      left = right + 1;
      right = student.find(",", left);
      dic[i] = stoi(student.substr(left, right - left));
    }
    int dic1 = dic[0];
    int dic2 = dic[1];
    int dic3 = dic[2];
  
    DegreeProgram dp = DegreeProgram::NETWORK;
    if (student.back() == 'E') dp = DegreeProgram::SOFTWARE;
    else if (student.back() == 'Y') dp = DegreeProgram::SECURITY;

    add(sID, fname, lname, smail, sage, dic1, dic2, dic3, dp);
  
};

void Roster::add(string studentID, string firstName, string lastName, string email, int age, int DaysInCourse1, int DaysInCourse2, int       
DaysInCourse3, DegreeProgram degreeprogram){
  
  int avgDaysInCourse[3] = {DaysInCourse1, DaysInCourse2, DaysInCourse3};
  classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, email, age, avgDaysInCourse, degreeprogram);
  
  };

void Roster::printAll(){
  cout << "Displaying All Students: " << endl;
  for (int i = 0; i < rosterSize; i++) {
    if (classRosterArray[i] == nullptr) {continue; }
    else {classRosterArray[i]->print();}
  }
  cout << endl;
  return;
}

void Roster::printbyDegreeProgram(DegreeProgram degreeprogram){
  cout << "Showing Students in Degree Program: SOFTWARE" << endl;
  for (int i = 0; i < rosterSize; i++){
    if (Roster::classRosterArray[i]->getdegreeprogram() == degreeprogram){ classRosterArray[i]->print(); }
  }
}

void Roster::printinvalidEmails() {
  cout << "Invalid Email Adresses: " << endl;
  for (int i = 0; i < rosterSize; i++){
    string emailspot = classRosterArray[i]->getemail();
    if(emailspot.find('.') == string::npos || emailspot.find('@') == string::npos || emailspot.find(" ") != string::npos){
      cout<< emailspot << "- Is invalid." << endl;
    }
  }
}

void Roster::printaverageDaysInCourse(string studentID){
  for (int i = 0; i < rosterSize; i++){
    if (studentID == classRosterArray[i]->getstudentID()){
      cout << "Student: " 
           << studentID
           << ","
           << " average days in course is: "
           << (classRosterArray[i]->getDaysInCourse()[0] + classRosterArray[i]->getDaysInCourse()[1] + classRosterArray[i]->getDaysInCourse()[2]) / 3
           << endl;
    }
  }
}

//remove
void Roster::remove(string studentID) {
  cout << "Removing Student A3: " << endl;
  bool found = false;
  for (int i = 0; i < rosterSize; i++){
    if (classRosterArray[i] == nullptr) {
      continue;
    } else if (classRosterArray[i]->getstudentID() == studentID){
      classRosterArray[i] = nullptr;
      found = true; break;
    }
  };
  if (found == true){
    cout << "Student " 
         << studentID
         << " Reomved"
         << endl;
  } else {cout << "Student Not Found" << endl;};
}


//destructor
Roster::~Roster(){
  for(int i = 0; i < rosterSize; i++){
    delete classRosterArray[i];
    classRosterArray[i] = nullptr;
  };
}