#include<iostream>
#include<conio.h>
#include<string>
#include<sstream>

int main()
{
	std::string input;
	unsigned short amount;
	
	std::cout << "Gib die Anzahl der zahlen ein: ";
	getline(std::cin, input);
	std::stringstream(input) >> amount;
	
	std::cout << "\n";
	
	long double array[amount];
	
	for(unsigned short idx = 0;  idx<amount;  idx++)
	{
		std::cout << "Gib die " << idx+1 << ". Zahl ein: ";
		getline(std::cin, input);
		std::stringstream(input) >> array[idx];
	}
	
	std::cout << "\n";
	
	for(unsigned short idx =0; idx<amount-1; idx++) std::cout << array[idx] << ", ";
	std::cout << array[amount-1] << "\n"; //Ausgabe des unsortierten Arrays
	
	for(unsigned short idx = 0;  idx<amount-1; idx++)
	{
		unsigned short indexMin = idx;
		for(unsigned short idx2 = idx+1; idx2<amount; idx2++) if(array[idx2]<array[indexMin]) indexMin = idx2;
		
		if(indexMin!=idx)
		{
			long double temp = array[idx];
			array[idx] = array[indexMin];
			array[indexMin] = temp;
		}
		
		for(unsigned short idx =0; idx<amount-1; idx++) std::cout << array[idx] << ", ";
		std::cout << array[amount-1] << "\n"; //Ausgabe des Arrays nach jedem Sortierungsschritt
	}
	
	getch();
	return(0);
}
