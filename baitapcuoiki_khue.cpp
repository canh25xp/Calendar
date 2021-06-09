#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

// the class that stores data
class student
{
int rollno;
char name[50];
double eng_marks, math_marks, phy_marks, che_marks, lit_marks;
double average;
char grade;

public:
void getdata();
void showdata() const;
void calculate();
int retrollno() const;
}; //class ends here

void student::calculate()
{
average=(eng_marks+math_marks+phy_marks+che_marks+lit_marks)/5.0;
if(average>=9.0)
grade='A';
else if(average>=7.5)
grade='B';
else if(average>=5.0)
grade='C';
else if (average>=3.0)
grade='D';
else
grade='F';
}

void student::getdata()
{
cout<<"\nEnter student's roll number: ";
cin>>rollno;
cout<<"\n\nEnter student name: ";
cin.ignore();
cin.getline(name,50);
cout<<"\nAll marks should be out of 10";
cout<<"\nEnter marks in English: ";
cin>>eng_marks;
cout<<"\nEnter marks in Math:  ";
cin>>math_marks;
cout<<"\nEnter marks in Physical:  ";
cin>>phy_marks;
cout<<"\nEnter marks in Chemical:  ";
cin>>che_marks;
cout<<"\nEnter marks in Literature:  ";
cin>>lit_marks;
calculate();
}
void student::showdata() const
{
cout<<"\nRoll number of student : "<<rollno;
cout<<"\nName of student : "<<name;
cout<<"\nEnglish : "<<eng_marks;
cout<<"\nMaths : "<<math_marks;
cout<<"\nSPhysical : "<<phy_marks;
cout<<"\nChemical : "<<che_marks;
cout<<"\nLiturature :"<<lit_marks;
cout<<"\nAverage Marks :"<<average;
cout<<"\nGrade of student is :"<<grade;
}

