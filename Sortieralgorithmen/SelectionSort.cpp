#include<iostream>
#include<conio.h>
#include<string>
#include<sstream>
#include<cstdlib>
#include<ctime>

void SelectionSort(long double *array, unsigned short amount);
void SelectionSort(int *array, unsigned short amount);

int main()
{
	std::string input;
	unsigned short amount = 1;
	
	std::cout << "Gib die Anzahl der Zahlen ein: ";
	getline(std::cin, input);
	std::stringstream(input) >> amount;
	
	std::cout << "\nM\x94 \bchtest du mit zuf\x84lligen Zahlen arbeiten? y/n	";
	getline(std::cin, input);
	if(input == "y" || input == "Y")
	{
		int *array = new int[amount];
		srand(time(0));
		for(unsigned short idx = 0; idx < amount; idx++) array[idx] = rand()%100;
		SelectionSort(array, amount);
		delete[] array;
	}
	else
	{
		long double *array = new long double[amount];
		for(unsigned short idx = 0; idx < amount; idx++)
		{
			std::cout << "Gib die " << idx+1 << ". Zahl ein: ";
			getline(std::cin,input);
			std::stringstream(input) >> array[idx];
		}
		SelectionSort(array, amount);
		delete[] array;
	}
	
	getch();
	return(0);
}
	
void SelectionSort(long double *array, unsigned short amount)
{
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
}

void SelectionSort(int *array, unsigned short amount)
{
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
}
