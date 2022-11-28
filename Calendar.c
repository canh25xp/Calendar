#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

int daysOfMonth(int month, int year);
int checkLeapYear(int year);
int dayOfWeek(int day, int month, int year);
void dayName(int index);
void monthName(int month);
void yearName(int year);
void astrologicalSign(int day,int month);
void fullCalender(int day, int month, int year);
void printMonth(int month,int year);
void setColor(int ForgC);
void setColorAndBackground(int ForgC, int BackC);
void nextMonth(int *month, int *year);
void previousMonth(int *month, int *year);
void teamMember();
void introduction();

int main(){
	SetConsoleTitle("This is simply a calender");
	int d,m,y;
	int choice=0;
	char ch='a';
	while(1){
		system("cls");
		printf("A wibu team production\nVerion 1.2\n");
		printf("-----------------------\n");
		printf("1.Show team members.\n");
		printf("2.Show introduction.\n");
		printf("3.Calendar.\n");
		printf("4.Check your astrological sign.\n");
		printf("5.Exit\n\nEnter your option : ");
		scanf("%i",&choice);
		system("cls");	
		switch(choice){
			case 1 :
				teamMember();
				printf("\nPress any key to continue...");
				getch();
				break;
			case 2 : 
				introduction();
				printf("\nPress any key to continue...");
				getch();
				break;
			case 3 :	
				printf("Enter date (DD MM YYYY) : ");
				begin :
				scanf("%i %i %i",&d,&m,&y);
				if(d<=0||d>=32||m<=0||m>=13||y<=0){
					system("cls");
					setColor(12);
					printf("Error ! The day %i/%i/%i does not exist.",d,m,y);
					setColor(15);
					printf("\nEnter date again (DD MM YYYY) : ");
					goto begin;
				}
				system("cls");
				printf("%i ",y);
				yearName(y);
				printf(" year\n\n");
				fullCalender(d,m,y);
				printf("\n\nPress 'n' to next month, 'p' to previous month, 'e' to exit...");
				while(ch!='e'){
					ch=getch();
					if(ch=='n'){
						nextMonth(&m,&y);
						system("cls");
						printf("%i ",y);				
						yearName(y);
						printf("\n\n");
						printMonth(m,y);
					}
					else if(ch=='p'){
						previousMonth(&m,&y);
						system("cls");	
						printf("%i ",y);					
						yearName(y);
						printf("\n\n");		
						printMonth(m,y);
					}
					printf("\n\nPress 'n' to next month, 'p' to previous month, 'e' to exit...");
				}
				break;
			case 4 :
				printf("Enter your birthday (DD MM) : ");
				scanf("%i %i",&d,&m);
				system("cls");
				printf("Your astrological sign is ");
				astrologicalSign(d,m);
				printf("\nPress any key to continue...");
				getch();
				break;
			case 5 : 
				exit(0);		
			}
	}
	return 0;
}

void teamMember(){
	printf("Wibu team :\n");
	printf("Ngo Van Canh - 20193203 \n");
	printf("Vu Huy Hoang - 20193220 \n");
	printf("Phung Manh Dung - 20193210 \n");
	printf("Nguyen Danh khue - 20133224");
}
void introduction(){
	printf("You can check for date, print full month Calender, or even Zodaic sign.\n");
	printf("Update version 1.2 : Check astrological sign\n");
	printf("This version may still contain a few bugs");
}
int daysOfMonth(int month, int year){
	switch(month){
		case 1: return (31);
		case 2:
			if(checkLeapYear(year)==1)
				return (29);
			else 
				return (28);
		case 3: return (31);
		case 4: return (30);
		case 5: return (31);
		case 6: return (30);
		case 7: return (31);
		case 8: return (31);
		case 9: return (30);
		case 10:return (31);
		case 11:return (30);
		case 12:return (31);	
	}
}
int checkLeapYear(int year){
	if(year%4==0&&year%100!=0||year%400==0)
		return 1;
	else
		return 0;	
	//Reference : https://en.wikipedia.org/wiki/Leap_year	
}
int dayOfWeek(int day, int month, int year){
	int index=-1;
	static int t[]={0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
	if(month==1||month==2)
		year--;
	index = (year + year/4 - year/100 + year/400 + t[month-1] + day) % 7 ;
	return index;
	//Reference : https://en.wikipedia.org/wiki/Determination_of_the_day_of_the_week
	//Sakamoto’s Algorithm
}	
void dayName(int index){
	switch(index){
		case 0 : printf("Sunday");		break;
		case 1 : printf("Monday");		break;
		case 2 : printf("Tuesday");		break;
		case 3 : printf("Wednesday");	break;
		case 4 : printf("Thursday");	break;
		case 5 : printf("Friday");		break;
		case 6 : printf("Saturday");	break;
	}
}
void monthName(int month){
	switch(month){
		case 1 : printf("January");		break;
		case 2 : printf("February");	break;
		case 3 : printf("March");		break;
		case 4 : printf("April");		break;
		case 5 : printf("May");			break;
		case 6 : printf("June");		break;
		case 7 : printf("July");		break;
		case 8 : printf("August");		break;
		case 9 : printf("September");	break;
		case 10: printf("Octorber");	break;
		case 11: printf("November");	break;
		case 12: printf("December");	break;										
	}
}
void yearName(int year){
	int index=year%12;
	switch(index){
		case 4 : printf("The Rat");		break;
		case 5 : printf("The Ox");		break;
		case 6 : printf("The Tiger");	break;
		case 7 : printf("The Cat");		break;
		case 8 : printf("The Dragon");	break;
		case 9 : printf("The Snake");	break;
		case 10: printf("The Horse");	break;
		case 11: printf("The Goat");	break;
		case 0 : printf("The Monkey");	break;
		case 1 : printf("The Rooster");	break;
		case 2 : printf("The Dog");		break;
		case 3 : printf("The Pig"); 	break;
	}
}
void astrologicalSign(int day,int month){
	if((month==12&&day>=22)||(month==1&&day<=19)){
		printf("Capricorn");
	}
	else if((month==1&&day>=20)||(month==2&&day<=18)){
		printf("Aquarius");
	}	
	else if((month==2&&day>=19)||(month==3&&day<=20)){
		printf("Pisces");
	}
	else if((month==3&&day>=21)||(month==4&&day<=19)){
		printf("Aries");
	}
	else if((month==4&&day>=20)||(month==5&&day<=20)){
		printf("Taurus");
	}
	else if((month==5&&day>=21)||(month==6&&day<=21)){
		printf("Gemini");
	}
	else if((month==6&&day>=22)||(month==7&&day<=22)){
		printf("Cancer");
	}
	else if((month==7&&day>=23)||(month==8&&day<=22)){
		printf("Leo");
	}
	else if((month==8&&day>=23)||(month==9&&day<=22)){
		printf("Virgo");
	}
	else if((month==9&&day>=23)||(month==10&&day<=22)){
		printf("Libra");
	}
	else if((month==10&&day>=23)||(month==11&&day<=22)){
		printf("Scorpio");
	}
	else if((month==11&day>=23)||(month=12&&day<=21)){
		printf("Sagittarius");
	}
	else{
		setColor(12);
		printf("Invalid date");
		setColor(15);
	}
}
void fullCalender(int day, int month, int year){
	int index=dayOfWeek(1,month,year);
	int days=daysOfMonth(month,year);
	int i; 
	printf("          ");
	monthName(month);
	printf("\n--------------------------");
	printf("\nS   M   T   W   T   F   S\n");
	for(i=0;i<index;i++){
		printf("    ");
	}
	index=6-index;
	for(i=1;i<=days;i++){
		if(i==day)
			setColor(12);
		else
			setColor(15);
		if(i<10)
			printf("%i   ",i);		
		else
			printf("%i  ",i);
		while(index==0){
			printf("\n");
			index=7;
		}
		index--;
	}
}
void printMonth(int month,int year){
	int index=dayOfWeek(1,month,year);
	int days=daysOfMonth(month,year);
	int i; 
	printf("          ");
	monthName(month);
	printf("\n--------------------------");
	printf("\nS   M   T   W   T   F   S\n");
	for(i=0;i<index;i++){
		printf("    ");
	}
	index=6-index;
	for(i=1;i<=days;i++){
		if(i<10)
			printf("%i   ",i);		
		else
			printf("%i  ",i);
		while(index==0){
			printf("\n");
			index=7;
		}
		index--;
	}	
}
void nextMonth(int *month, int *year){
	++*month;
	if(*month>12){
		++*year;
		*month=1;
	}
}
void previousMonth(int *month, int *year){
	--*month;
	if(*month<1){
		--*year;
		*month=12;
	}
}
void setColor(int ForgC){
    WORD wColor;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi)){
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
    	SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}
void setColorAndBackground(int ForgC, int BackC){
    WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
    return;
}
