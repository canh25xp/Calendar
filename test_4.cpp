#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;


class Student{
	private:
		struct subject{
			double marks;
			int credits; 
		}eng,cal,alg,phy,phi;// english, calculus, algebra, physics, philosophy.
		int id;
		char name[50];
		double gpa;
	public:
		void getData(){
			cout<<"Enter student's ID : ";
			cin>>id;
			cout<<"Enter student name : ";
			cin.ignore();
			cin.getline(name,50);
			cout<<"Enter marks in scale of 10\n"; 
			cout<<"Enter marks in English : ";
			cin>>eng.marks;
			cout<<"Enter marks in Calculus : ";
			cin>>cal.marks;
			cout<<"Enter marks in Algebra : ";
			cin>>alg.marks;
			cout<<"Enter marks in Physics : ";
			cin>>phy.marks;
			cout<<"Enter marks in Philosophy : ";
			cin>>phi.marks;
		}
		void showData(){
			cout<<"Roll number of student : "<<id;
			cout<<"\nName of student : "<<name;
			cout<<"\nEnglish : "<<eng.marks;
			cout<<"\nCalculus : "<<cal.marks;
			cout<<"\nAlgebra : "<<alg.marks;
			cout<<"\nPhysics : "<<phy.marks;
			cout<<"\nPhilosophy : "<<phi.marks;
			calculate();
			cout<<"\nGPA : "<<gpa<<"/4";
		}
		void calculate(){
			eng.credits=2;
			cal.credits=4;
			alg.credits=4;
			phy.credits=5;
			phi.credits=1;
			int sumCredits=eng.credits+cal.credits+alg.credits+phy.credits+phi.credits;
			gpa=(eng.marks*eng.credits+cal.marks*cal.credits+alg.marks*alg.credits+phy.marks*phy.credits+phi.marks*phi.credits)/sumCredits;
			gpa=(gpa*4)/10;
		}
};

int main(){
	//system("color %");
	system("color 0a");
	Student student1;
	char choice;
	cout<<setprecision(2); 
	while(1){
		system("cls");
		cout<<"MENU";
		cout<<"\n1. Create student record";
		cout<<"\n2. Search student record";
		cout<<"\n3. Display all students records ";
		cout<<"\n4. Delete student record";
		cout<<"\n5. Modify student record";
		cout<<"\n6. Exit";
		cout<<"\nWhat is your Choice (1/2/3/4/5/6) ";
		cin>>choice;
		system("cls");
		switch(choice){
			case '1':{
				ofstream studentFile;
				studentFile.open("Student List.dat",ios::binary|ios::app);
				student1.getData();
				studentFile.write(reinterpret_cast<char *>(&student1),sizeof(Student));
				studentFile.close();
				system("pause");
				break;
			}
			case '2':{
				system("pause");
				break;
			}
			case '3':{
				ifstream studentFile;
				studentFile.open("Student List.dat",ios::binary);
				if(studentFile==0){
					cout<<"File could not be open.\n";
					system("pause");
				}
				while(studentFile.read(reinterpret_cast<char *>(&student1), sizeof(Student))){
					student1.showData();
					cout<<"\n====================================\n";
				}
				studentFile.close();
				system("pause");
				break;
			}	
			case '4':{
				break;
			}
			case '5':{
				break;
			}
			case '6':
				cout<<"Exiting, Thank you!";
				exit(0);			
		}
	}
	return 0;
}
