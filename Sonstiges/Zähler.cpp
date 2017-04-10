#include<iostream>
#include<conio.h>
#include<sstream>
#include<string>

int main ()
{
	long long start=0, end=0;
	std::string input;
	
	std::cout << "Geben sie den Startwert ein: ";
	getline(std::cin, input);
	std::stringstream(input) >> start;
	
	std::cout << "\nGeben sie den Endwert ein: ";
	getline(std::cin, input);
	std::stringstream(input) >> end;
	
	std::cout << "\n";
	
	if(start<end) for(int idx = start; idx<end; idx++) std::cout << idx << ", ";
	else for(int idx = start; idx>end; idx--) std::cout << idx << ", ";
	std::cout << end << "\n\nDie Summe der natuerlichen Zahlen von " << start << " bis " << end << " betraegt: " << (end*(end+1)-start*(start-1))/2;
	
	getch();
	return(0);
}
