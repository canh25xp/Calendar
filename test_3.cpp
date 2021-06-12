#include<iostream>
#include <iomanip> 
using namespace std;


class Student{
	private:
		struct subject{
			double marks;
			int credits; 
		}eng,cal,alg,phy,phi;// english, calculus, algebra, physics, philosophy.
		int id;
		char name[50];
		double cpa, gpa;
	public:
		void getData();
		void showData();
		void calculate();
		void editSubject();		
};
void Student::editSubject(){
}
void Student::calculate(){
	eng.credits=2;
	cal.credits=4;
	alg.credits=4;
	phy.credits=5;
	phi.credits=1;
	int sumCredits=eng.credits+cal.credits+alg.credits+phy.credits+phi.credits;
	gpa=(eng.marks*eng.credits+cal.marks*cal.credits+alg.marks*alg.credits+phy.marks*phy.credits+phi.marks*phi.credits);
}
void Student::getData(){
	cout<<"Enter student's ID : ";
	cin>>id;
	cout<<"Enter student name : ";
	cin.ignore();
	cin.getline(name,50);
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
	cout<<"Student record Has Been Created. Press any key to continue... ";
	calculate();
	cin.ignore();
	cin.get();
}
void Student::showData(){
	cout<<"Roll number of student : "<<id;
	cout<<"\nName of student : "<<name;
	cout<<"\nEnglish : "<<eng.marks;
	cout<<"\nCalculus : "<<cal.marks;
	cout<<"\nAlgebra : "<<alg.marks;
	cout<<"\nPhysics : "<<phy.marks;
	cout<<"\nPhilosophy : "<<phi.marks;
	cout<<"\nGPA :"<<gpa;
	cout<<"\nEnd of list. Press any key to continue...";
	cin.ignore();
	cin.get();
}

int main(){
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
			case '1':
				Student st;
				st.getData();
				break;
			case '2':
				cin.ignore();
				cin.get();
				break;
			case '3':
				st.showData();	
				break;
			case '4':
				cin.ignore();
				cin.get();
				break;
			case '5':
				cin.ignore();
				cin.get();
				break;
			case '6':
				cout<<"Exiting, Thank you!";
				exit(0);			
		}
	}
	return 0;
}
