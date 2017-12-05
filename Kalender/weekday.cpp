#include<iostream>
#include<string>
#include<sstream>
#include<conio.h>
#include <stdio.h>

int main()
{
	//Aufgabe: Kombiniere dieses Programm mit dem jeweils anderen im Kalender Ordner.
	
	std::string input;
	unsigned short day = 0, month = 0, daysInMonth[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, year = 0;
	
	printf("Gib den Tag des Monats ein: ");
	do
	{
		getline(std::cin, input);
		std::stringstream(input) >> day;
		if(day>31 || day<1) printf("ERROR: Der eingegebene Tag existiert nicht. Gib einen Tag zwischen 1 und 31 ein: ");
	}while(day>31 || day<1);
	
	printf("Gib den Monat ein: ");	
	do
	{
		getline(std::cin, input);
		std::stringstream(input) >> month;
		if(month>12 || month<1) printf("ERROR: Der eingegebene Monat existiert nicht. Gib einen Monat zwischen 1 und 12 ein: ");
		else if(day>daysInMonth[month-1]) printf("ERROR: Der eingegebene Monat hat nicht genug Tage. Gib einen anderen Monat ein: ");
	}while(month>12 || month<1 || day>daysInMonth[month-1]);
	
	printf("Gib das Jahr ein: ");
	do
	{
		getline(std::cin, input);
		std::stringstream(input) >> year;
		if(year<0) printf("ERROR: Das Datum liegt vor dem 1. Januar 0. Gib ein Jahr nach dem 1. Januar 00 ein: ");
		else if(day==29 && month == 2 && (year%4!=0 || year%100==0 && year%400!=0)) printf("ERROR: Die bereits erfolgten Eingaben benötigen ein Schaltjahr. Gib ein anderes Jahr ein: ");
	}while(year<0 || day==29 && month == 2 && (year%4!=0 || year%100==0 && year%400!=0));
	
	printf("\nDer %i.%i.%i ist ein ", day, month, year);
	
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
	if(day==0) printf("Sonntag");
	else if(day==1) printf("Montag");
	else if(day==2) printf("Dienstag");
	else if(day==3) printf("Mittwoch");
	else if(day==4) printf("Donnerstag");
	else if(day==5) printf("Freitag");
	else printf("Samstag");
	
	getch();
	return(0);
}
