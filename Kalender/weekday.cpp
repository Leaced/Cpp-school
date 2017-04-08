#include<iostream>
#include<string>
#include<sstream>
#include<conio.h>

int main()
{
	//Aufgabe: Kombiniere dieses Programm mit dem jeweils anderen im Kalender Ordner.
	
	std::string input;
	unsigned short day = 0, month = 0, daysInMonth[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, year = 0;
	
	std::cout << "Gib den Tag des Monats ein: ";
	do
	{
		getline(std::cin, input);
		std::stringstream(input) >> day;
		if(day>31 || day<1) std::cout << "ERROR: Der eingegebene Tag existiert nicht. Gib einen Tag zwischen 1 und 31 ein: ";
	}while(day>31 || day<1);
	
	std::cout << "Gib den Monat ein: ";	
	do
	{
		getline(std::cin, input);
		std::stringstream(input) >> month;
		if(month>12 || month<1) std::cout << "ERROR: Der eingegebene Monat existiert nicht. Gib einen Monat zwischen 1 und 12 ein: ";
		else if(day>daysInMonth[month-1]) std::cout << "ERROR: Der eingegebene Monat hat nicht genug Tage. Gib einen anderen Monat ein: ";
	}while(month>12 || month<1 || day>daysInMonth[month-1]);
	
	std::cout << "Gib das Jahr ein: ";
	do
	{
		getline(std::cin, input);
		std::stringstream(input) >> year;
		if(year<0) std::cout << "ERROR: Das Datum liegt vor dem 1. Januar 0. Gib ein Jahr nach dem 1. Januar 00 ein: ";
		else if(day==29 && month == 2 && (year%4!=0 || year%100==0 && year%400!=0)) std::cout << "ERROR: Die bereits erfolgten Eingaben benötigen ein Schaltjahr. Gib ein anderes Jahr ein: ";
	}while(year<0 || day==29 && month == 2 && (year%4!=0 || year%100==0 && year%400!=0));
	
	std::cout << "\nDer " << day << "." << month << "." << year << " ist ein ";
	
	if(month==1 || month==2) year -=1;
	if(month==1) month = 0;
	else if(month==8) month = 1;
	else if(month==2 || month==6) month = 3;
	else if(month==9 || month==12) month = 4;
	else if(month==4 || month==7) month = 5;
	else if(month == 10) month = 6;
	else month = 2;
	
	day = (day+month+(year%100)+(year%100/4)+year/400-2*(year/100))%7;
	
	while(day<0) day += 7;
	if(day==0) std::cout << "Sonntag";
	else if(day==1) std::cout << "Montag";
	else if(day==2) std::cout << "Dienstag";
	else if(day==3) std::cout << "Mittwoch";
	else if(day==4) std::cout << "Donnerstag";
	else if(day==5) std::cout << "Freitag";
	else std::cout << "Samstag";
	
	getch();
	return(0);
}
