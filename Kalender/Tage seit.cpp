#include<iostream>
#include<conio.h>
#include<string>
#include<sstream>
#include <stdio.h>

int main()
{
	//Aufgabe: Kombiniere dieses Programm mit dem jeweils anderen im Kalender Ordner.

	std::string input;
	unsigned short daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30}, day = 0, month = 0, year = 0;

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
		if(day==29 && month==2) daysInMonth[1]++;
		else if(month>12 || month<1) printf("ERROR: Der eingegebene Monat existiert nicht. Gib einen Monat zwischen 1 und 12 ein: ");
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

	printf("\nVom 1. Januar 0 bis zum %i.%i.%i", day, month, year);

	for(short idx = 0; idx<month-1; idx++) day += daysInMonth[idx];

	printf(" sind %i Tage vergangen.", year*365+year/4-year/100+year/400+day-1);

	getch();
	return(0);
}
