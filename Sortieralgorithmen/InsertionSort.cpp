#include<iostream>
#include<conio.h>
#include<string>
#include<sstream>
#include<cstdlib>
#include<ctime>

void InsertionSort(long double *ptr, unsigned short amount);
void InsertionSort(int *ptr, unsigned short amount);

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
		for(unsigned short idx = 0; idx < amount; idx++) array[idx] = rand()%1000;
		InsertionSort(array, amount);
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
		InsertionSort(array, amount);
		delete[] array;
	}
	
	getch();
	return(0);
}
	
void InsertionSort(long double *ptr, unsigned short amount)
{
	std::cout << "\n";
	
	for(unsigned short idx = 0; idx<amount-1; idx++) std::cout << ptr[idx] <<", ";
	std::cout << ptr[amount-1] << "\n"; //Ausgabe des unsortierten Arrays
	
	for(unsigned short idx = 1; idx < amount; idx++)
	{
		int temp = ptr[idx];
		int idx2 = idx - 1;
	
		while(idx2>=0 && ptr[idx2]>temp) ptr[idx2+1] = ptr[idx2--];
		ptr[idx2+1] = temp;
		
		for(unsigned short idx =0; idx<amount-1; idx++) std::cout << ptr[idx] << ", ";
		std::cout << ptr[amount-1] << "\n"; //Ausgabe des Arrays nach jedem Sortierungsschritt
	}
}

void InsertionSort(int *ptr, unsigned short amount)
{
	std::cout << "\n";
	
	for(unsigned short idx = 0; idx<amount-1; idx++) std::cout << ptr[idx] <<", ";
	std::cout << ptr[amount-1] << "\n"; //Ausgabe des unsortierten Arrays
	
	for(unsigned short idx = 1; idx < amount; idx++)
	{
		int temp = ptr[idx];
		int idx2 = idx - 1;
	
		while(idx2>=0 && ptr[idx2]>temp) ptr[idx2+1] = ptr[idx2--];
		ptr[idx2+1] = temp;
		
		for(unsigned short idx =0; idx<amount-1; idx++) std::cout << ptr[idx] << ", ";
		std::cout << ptr[amount-1] << "\n"; //Ausgabe des Arrays nach jedem Sortierungsschritt
	}
}
