#include<iostream>
#include<string>
#include<sstream>
#include<conio.h>

int main()
{
	std::string input;
	short day, month, daysInMonth[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, weekday, year;
	
	std::cout << "Gib das Tagesdatum ein: ";
	getline(std::cin, input);
	std::stringstream(input) >> day;
	
	if(day==0 || day>31)
	{
		std::cout << "\nERROR: Das eingegebene Tagesdatum existiert nicht.";
		getch();
		return(1);
	}
	
	std::cout << "Gib den Monat ein: ";
	getline(std::cin, input);
	std::stringstream(input) >> month;
	
	if(daysInMonth[month-1]<day)
	{
		std::cout << "\nERROR: Der eingegebene Monat hat keine " << day << " Tage.";
		getch();
		return(1);
	}
	
	if(month>12 || month==0)
	{
		std::cout << "\nERROR: Der eingegebene Tag existiert nicht.";
		getch();
		return(1);
	}
	
	std::cout << "Gib das jahr ein: ";
	getline(std::cin, input);
	std::stringstream(input) >> year;
	
	if(year>10000 || year<0)
	{
		std::cout << "\nERROR: Im eingegeben Jahr lässt sich der Wochentag nicht ermitteln.";
		getch();
		return(1);
	}
	
	if(day==29 && month==2 && (year%4!=0 || year%100==0))
	{
		std::cout << "\nERROR: Die Eingaben ben\x94tigen ein Schaltjahr.";
		getch();
		return(1);
	}
	
	std::cout << "\nDer " << day << "." << month << "." << year << " war ein ";
	
	if(month==1 || month==2) year -=1;
	
	switch (month)
	{
		case 1:		month = 0;		break;
		case 8:		month = 1;		break;
		case 2:
		case 6:		month = 3;		break;
		case 9:
		case 12:	month = 4;		break;
		case 4:
		case 7:		month = 5;		break;
		case 10:	month = 6;		break;
		default:	month = 2;		break;
	}
	
	weekday = (day+month+(year%100)+(year%100/4)+year/400-2*(year/100))%7;
	
	while(weekday<0) weekday += 7;
	
	switch(weekday)
	{
		case 0:	std::cout << "Sonntag";		break;
		case 1:	std::cout << "Montag";		break;
		case 2:	std::cout << "Dienstag";	break;
		case 3:	std::cout << "Mittwoch";	break;
		case 4:	std::cout << "Donnerstag";	break;
		case 5:	std::cout << "Freitag";		break;
		case 6:	std::cout << "Samstag";		break;
	}
	
	getch();
	return(0);
}
