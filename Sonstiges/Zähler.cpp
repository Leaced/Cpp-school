#include<iostream>
#include<conio.h>
#include<sstream>
#include<string>

int main ()
{
	long long start=0, end=0;
	std::string input;
	
	printf("Geben sie den Startwert ein: ");
	getline(std::cin, input);
	std::stringstream(input) >> start;
	
	printf("Geben sie den Endwert ein: ");
	getline(std::cin, input);
	std::stringstream(input) >> end;
	
	printf("\n");
	
	if(start<end) for(int idx = start; idx<end; idx++) printf("%i, ", idx);
	else for(int idx = start; idx>end; idx--) printf("%i, ", idx);
	
	printf("%i\n\nDie Summe der natuerlichen Zahlen von %i bis %i betraegt: ",end, start, end);
	if(start<end) printf("%i", (end*(end+1)-start*(start-1))/2);
	else printf("%i", (end*(end-1)-start*(start+1))/2);
	
	getch();
	return(0);
}
