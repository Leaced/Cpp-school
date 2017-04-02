#include<iostream>
#include<string>
#include<sstream>
int main()
{
	std::string stringInput;
	unsigned long long day, month, year;
	short daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
	
	std::cout << "Gib den Tag des Monats ein: ";
	getline(std::cin, stringInput);
	std::stringstream(stringInput) >> day;
	
	if(day>31 || day<1)
	{
		std::cout << "ERROR: Der eingegebene Tag existiert nicht.";
		return(1);
	}
	
	std::cout << "Gib den Monat ein: ";
	getline(std::cin, stringInput);
	std::stringstream(stringInput) >> month;
	
	if(month>12 || month<1)
	{
		std::cout << "ERROR: Der eingegebene Monat existiert nicht.";
		return(1);
	}
	
	if(day>daysInMonth[month] && month!=2 || month==2 && day>29)
	{
		std::cout << "ERROR: Es wurden zuviele Tage f\x81r diesen Monat eingegeben.";
		return(1);
	}
	
	if(day==29 && month==2) daysInMonth[1]++;
	
	std::cout << "Gib das Jahr ein: ";
	getline(std::cin, stringInput);
	std::stringstream(stringInput) >> year;
	
	if(year<0)
	{
		std::cout << "ERROR: Der 1. Januar 0 liegt in der Zukunft.";
		return(1);
	}
	
	if(day==29 && month == 2 && (year%4!=0 || year%100==0 && year%400!=0))
	{
		std::cout << "ERROR: Die bereits erfolgten Eingaben benötigen ein Schaltjahr.";
		return(1);
	}
	
	std::cout << "\nVom 1. Januar 0 bis zum " << day << "." << month << "." << year;
	
	for(short idx = 0; idx<month-1; idx++)
	{
		day += daysInMonth[idx];
	}
	
	std::cout << " sind " << year*365+year/4-year/100+year/400+day-1 <<" Tage vergangen.";
	
	getchar();
	return(0);
}
