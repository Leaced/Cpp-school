#include<iostream>
#include<conio.h>
#include<string>
#include<sstream>

int main()
{
	std::string input;
	unsigned short amount;
	
	std::cout << "Gib die Anzahl der Zahlen ein: ";
	getline(std::cin, input);
	std::stringstream(input) >> amount;
	
	std::cout << "\n";
	
	long double array[amount];
	
	for(unsigned short idx = 0; idx < amount; idx++)
	{
		std::cout << "Gib die " << idx+1 << ". Zahl ein: ";
		getline(std::cin,input);
		std::stringstream(input) >> array[idx];
	}
	
	std::cout << "\n";
	
	for(unsigned short idx = 0; idx<amount-1; idx++) std::cout << array[idx] <<", ";
	std::cout << array[amount-1] << "\n"; //Ausgabe des Arrays nach jedem Sortierungsschritt
	
	for(unsigned short idx = 1; idx < amount; idx++)
	{
		int temp = array[idx];
		int idx2 = idx - 1;
	
		while(idx2>=0 && array[idx2]>temp) array[idx2+1] = array[idx2--];
		array[idx2+1] = temp;
		
		for(unsigned short idx =0; idx<amount-1; idx++) std::cout << array[idx] << ", ";
		std::cout << array[amount-1] << "\n"; //Ausgabe des sortierten Arrays
	}
	
	getch();
	return(0);
}
