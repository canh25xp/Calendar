/*
Update Version 2 :
	Add grade function inside Student Class.
	Add reset function to delete all file as well as the data inside.
Update Version 3 :
	Fixed a few bugs  
*/

#include<iostream>
#include<iomanip>
#include<fstream>
#include<string.h>
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
		char grade[10];
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
			calculate();
		}
		void showData(){
			cout<<"Student's ID : "<<id;
			cout<<"\nName of student : "<<name;
			cout<<"\nEnglish : "<<eng.marks;
			cout<<"\nCalculus : "<<cal.marks;
			cout<<"\nAlgebra : "<<alg.marks;
			cout<<"\nPhysics : "<<phy.marks;
			cout<<"\nPhilosophy : "<<phi.marks;
			cout<<"\nGpa : "<<gpa<<"/4";
			cout<<"\nGrade : "<<grade;
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
			if(gpa<1){
				strcpy(grade,"Fail");
			}
			else if(gpa>=1&&gpa<=1.49){
				strcpy(grade,"Very Bad");
			}
			else if(gpa>=1.5&&gpa<=1.99){
				strcpy(grade,"Bad");
			}
			else if(gpa>=2&&gpa<=2.49){
				strcpy(grade,"gpa");
			}
			else if(gpa>=2.5&&gpa<=3.19){
				strcpy(grade,"Good");
			}
			else if(gpa>=3.2&&gpa<=3.59){
				strcpy(grade,"Very Good");
			}
			else{
				strcpy(grade,"Excellent");
			}
		}
		int getID(){
			return id;
			//Since "id" is a private variable of class Student, it cannot be access in the main function, therefore this function is needed.
		}
};

int main(){
	//system("color %");
	//The above line of code show instruction to change the background and foreground. Not needed for the final program. 
	system("color 0a");
	Student objStudent;
	char choice;
	int num;
	bool flag;
	cout<<setprecision(2); 
	while(1){
		system("cls");
		cout<<"MENU";
		cout<<"\n1. Add student record";
		cout<<"\n2. Search student by ID";
		cout<<"\n3. Display all students records";
		cout<<"\n4. Delete student record";
		cout<<"\n5. Edit student record";
		cout<<"\n6. Recycle Bin";
		cout<<"\n7. Reset";
		cout<<"\n8. Exit";
		cout<<"\nWhat is your Choice ? (1/2/3/4/5/6/7/8) ";
		cin>>choice;
		system("cls");
		switch(choice){
			case '1':{
				ofstream studentFile;
				studentFile.open("Student List.dat",ios::binary|ios::app);
				objStudent.getData();
				studentFile.write(reinterpret_cast<char*>(&objStudent),sizeof(Student));
				studentFile.close();
				system("pause");
				break;
			}
			case '2':{
				cout<<"Enter ID to found : "; 
				cin>>num;
				ifstream studentFile;
				studentFile.open("Student List.dat",ios::binary);
				if(studentFile==0){
					cout<<"File could not be open.";
					return 0;
				}
				flag=0;
				while(studentFile.read(reinterpret_cast<char*>(&objStudent),sizeof(Student))){
					if(objStudent.getID()==num){
						objStudent.showData();
						cout<<endl;
						flag=1;
					}
				}
				studentFile.close();
				if(flag==0){
					cout<<"ID "<<num<<" does not exists\n";
				}
				system("pause");
				break;
			}
			case '3':{
				ifstream studentFile;
				studentFile.open("Student List.dat",ios::binary);
				if(studentFile==0){
					cout<<"File could not be open.";
					return 0;
				}
				flag=0;
				while(studentFile.read(reinterpret_cast<char*>(&objStudent),sizeof(Student))){
					objStudent.showData();
					cout<<"\n====================================\n";
					flag=1;
				}
				if(flag==0){
					cout<<"Record file is Empty\n";
				}
				studentFile.close();
				system("pause");
				break;
			}	
			case '4':{
				cout<<"Enter ID to delete : "; 
				cin>>num;
				ifstream studentFile;
				studentFile.open("Student List.dat",ios::binary);
				if(studentFile==0){
					cout<<"File could not be open.";
					system("pause");
					return 0;
				}
				ofstream tempFile;
				ofstream recycleBin;
				recycleBin.open("Recycle Bin.dat",ios::binary|ios::app);
				tempFile.open("Temp.dat",ios::out);
				studentFile.seekg(0,ios::beg);
				flag=0;
				while(studentFile.read(reinterpret_cast<char *> (&objStudent), sizeof(Student))){
					if(objStudent.getID()!=num){
						tempFile.write(reinterpret_cast<char *> (&objStudent), sizeof(Student));
					}
					else{
						flag=1;
						recycleBin.write(reinterpret_cast<char *> (&objStudent), sizeof(Student));
					}
				}
				tempFile.close();
				studentFile.close();
				recycleBin.close();
				if(flag==0){
					cout<<"ID "<<num<<" does not exists\n";
					system("pause");
				}
				else{
					remove("Student List.dat");
					rename("Temp.dat","Student List.dat");
					cout<<"Record Deleted.\n";
					system("pause");				
				}
				break;
			}
			case '5':{
				cout<<"Enter ID to edit : "; 
				cin>>num;
				flag=0;
				fstream studentFile;
				studentFile.open("Student List.dat",ios::binary|ios::in|ios::out);
				if(studentFile==0){
					cout<<"File could not be opened.";
					return 0;
				}
				while(studentFile.eof()==0 && flag==0){
					studentFile.read(reinterpret_cast<char*>(&objStudent),sizeof(Student));
					if(objStudent.getID()==num){
						cout<<"====================================\n";
						cout<<"Enter student "<<num<<" new details:\n";
						objStudent.getData();
						int pos=(-1)*static_cast<int>(sizeof(objStudent));
					    studentFile.seekp(pos,ios::cur);
					    studentFile.write(reinterpret_cast<char*>(&objStudent),sizeof(Student));
					    cout<<"\nRecord Updated\n";
					    flag=1;
					}
				}
				studentFile.close();
				if(flag==0)
					cout<<"Record Not Found\n";
				system("pause");
				break;
			}
			case '6':{
				ifstream studentFile;
				studentFile.open("Recycle Bin.dat",ios::binary);
				cout<<"\tRecycle Bin";
				cout<<"\n====================================\n";
				if(studentFile==0){
					cout<<"Recycle Bin is empty\n";
					system("pause");
					break;
				}
				else{
					while(studentFile.read(reinterpret_cast<char*>(&objStudent),sizeof(Student))){
						objStudent.showData();
						cout<<"\n====================================\n";
					}
					studentFile.close();
					system("pause");
					break;
				}
			}
			case '7':{
				char confirm='1';
				cout<<"All recorded data will be delete\nConfirm to reset ? (y/n) ";
				while(confirm!='n'){
					cin>>confirm;
					if(confirm=='y'){
						remove("Student List.dat");
						remove("Recycle Bin.dat");
						cout<<"Reset Successfully.";
						exit(0);					
					}
					else{
						system("cls");
						cout<<"All recorded data will be delete\nConfirm to reset ? (y/n) ";
					}
				}
				break;
			}
			case '8':{
				cout<<"Exiting, Thank you!";
				exit(0);
				break;
			}
		}
	}
	return 0;
}
