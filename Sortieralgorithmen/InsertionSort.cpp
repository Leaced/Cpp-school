#include<iostream>
#include<conio.h>
#include<string>
#include<sstream>
#include<cstdlib>
#include<ctime>

void InsertionSort(long double *array, unsigned short amount);
void InsertionSort(int *array, unsigned short amount);

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
		for(unsigned short idx = 0; idx < amount; array[idx++] = rand()%1000);
		InsertionSort(array, amount);
		delete[] array;
	}
	else
	{
		long double *array = new long double[amount];
		for(unsigned short idx = 0;  idx < amount;  std::stringstream(input) >> array[idx++])
		{
			std::cout << "Gib die " << idx+1 << ". Zahl ein: ";
			getline(std::cin,input);
		}
		InsertionSort(array, amount);
		delete[] array;
	}
	
	getch();
	return(0);
}
	
void InsertionSort(long double *array, unsigned short amount)
{
	std::cout << "\n";
	
	for(unsigned short idx = 0; idx<amount-1; idx++) std::cout << array[idx] <<",	";
	std::cout << array[amount-1] << "\n"; //Ausgabe des unsortierten Arrays
	
	for(unsigned short idx = 1; idx < amount; idx++)
	{
		int temp = array[idx], idx2 = idx-1;
	
		while(idx2>=0 && array[idx2]>temp) array[idx2+1] = array[idx2--];
		array[idx2+1] = temp;
		
		for(idx2 = 0; idx2<amount-1; idx2++) std::cout << array[idx2] << ",	";
		std::cout << array[amount-1] << "\n"; //Ausgabe des Arrays nach jedem Sortierungsschritt
	}
}

void InsertionSort(int *array, unsigned short amount)
{
	std::cout << "\n";
	
	for(unsigned short idx = 0; idx<amount-1; idx++) std::cout << array[idx] <<",	";
	std::cout << array[amount-1] << "\n"; //Ausgabe des unsortierten Arrays
	
	for(unsigned short idx = 1; idx < amount; idx++)
	{
		int temp = array[idx], idx2 = idx-1;
	
		while(idx2>=0 && array[idx2]>temp) array[idx2+1] = array[idx2--];
		array[idx2+1] = temp;
		
		for(unsigned short idx2 = 0; idx2<amount-1; idx2++) std::cout << array[idx2] << ",	";
		std::cout << array[amount-1] << "\n"; //Ausgabe des Arrays nach jedem Sortierungsschritt
	}
}
