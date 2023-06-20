#include <iostream>
#include <string>
#include "roster.h"
#include "degree.h"
#include "student.h"
using namespace std;

// Project by Luke Schaffer lscha58@wgu.edu student#010909873
int main() {

  cout << "C867 Scripting and Programming Applications" << endl;
  cout << "Language: C++" << endl;
  cout << "Student ID: 010909873" << endl;
  cout << "Name: Luke Schaffer" << endl << endl;
  
  const string studentData[] = {
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Luke,Schaffer,lscha58@wgu.edu,23,20,30,40,SOFTWARE"
  };

  const int rosterSize = 5;

  Roster classRoster;

  for (int i = 0; i < rosterSize; i++) { classRoster.parse(studentData[i]);};
  classRoster.printAll();
  classRoster.printinvalidEmails();
  cout << endl;
  cout << "Displaying Average Days in Courses: " << endl;
  for (int i = 0; i < rosterSize; i++){classRoster.printaverageDaysInCourse(classRoster.classRosterArray[i]->getstudentID());};
  cout << endl; 
  classRoster.printbyDegreeProgram(SOFTWARE);
  cout << endl;
  classRoster.remove("A3"); 
  cout << endl;
  classRoster.remove("A3");
  cout << "DONE";
  
  return 0;
}

