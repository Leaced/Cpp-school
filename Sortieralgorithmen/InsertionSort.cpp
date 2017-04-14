#include<iostream>
#include<conio.h>
#include<string>
#include<sstream>
#include<cstdlib>
#include<ctime>

void InsertionSort(long double *array, short amount);
void InsertionSort(int *array, short amount);
void program();
void printArray(long double *array, short amount);
void printArray(short *array, short amount);

int main()
{
	std::cout << "Gib die Anzahl der Zahlen ein: ";
	
	program();
	
	getch();
	return(0);
}
	
void InsertionSort(long double *array, short amount)
{
	std::cout << "\n";
	
	printArray(array, amount);
	
	for(unsigned short idx = 1; idx < amount; idx++)
	{
		int temp = array[idx], idx2 = idx-1;
	
		while(idx2>=0 && array[idx2]>temp) array[idx2+1] = array[idx2--];
		array[idx2+1] = temp;
		
		printArray(array, amount);
	}
}

void InsertionSort(short *array, short amount)
{
	std::cout << "\n";
	
	printArray(array, amount);
	
	for(unsigned short idx = 1; idx < amount; idx++)
	{
		int temp = array[idx], idx2 = idx-1;
	
		while(idx2>=0 && array[idx2]>temp) array[idx2+1] = array[idx2--];
		array[idx2+1] = temp;
		
		printArray(array, amount);
	}
}

void program()
{
	std::string input;
	short amount = 1;
	
	do
	{
		getline(std::cin, input);
		std::stringstream(input) >> amount;
		if(amount >= USHRT_MAX) std::cerr << "Error: Die eingegebene Anzahl ist zu gro\xE1 oder klein. Gib eine andere Anzahl ein: ";
	}while(amount>=SHRT_MAX || amount<2);
	
	do
	{
		std::cout << "\nM\x94 \bchtest du mit zuf\x84lligen Zahlen arbeiten? y/n	";
		getline(std::cin, input);
		if(input != "y" && input != "Y" && input == "n" && input == "N") std::cerr << "Error: Diese Eingabe ist unzulässig. ";
	}while(input != "y" && input != "Y" && input == "n" && input == "N");
	
	if(input == "y" || input == "Y")
	{
		try
		{
			short *array = new short[amount];
			srand(time(0));
			for(unsigned short idx = 0; idx < amount; array[idx++] = rand()%1000);
			InsertionSort(array, amount);
			delete[] array;
		}
		catch(std::bad_alloc& ba)
		{
			std::cerr << "Error: Es konnte kein Array dieser Gr\x94\xE1 \be erzeugt werden. Gib eine andere Anzahl ein: ";
			program();
		}
		catch(std::exception& e)
		{
			std::cerr << "Error: Beim Erstellen des Arrays kam es zu einem unbekannten Fehler. Versuche es mit einer anderen Anzahl: ";
			program();
		}
	}
	else
	{
		try
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
		catch(std::bad_alloc& ba)
		{
			std::cerr << "Error: Es konnte kein Array dieser Gr\x94\xE1 \be erzeugt werden. Gib eine andere Anzahl ein: ";
			program();
		}
		catch(std::exception& e)
		{
			std::cerr << "Error: Beim Erstellen des Arrays kam es zu einem unbekannten Fehler. Versuche es mit einer anderen Anzahl: ";
			program();
		}
	}
}

void printArray(long double *array, short amount)
{
	for(unsigned short idx = 0; idx+1<amount; idx++) std::cout << array[idx] << ",	";
	std::cout << array[amount-1] << "\n";
	getch();
}

void printArray(short *array, short amount)
{
	for(unsigned short idx = 0; idx+1<amount; idx++) std::cout << array[idx] << ",	";
	std::cout << array[amount-1] << "\n";
	getch();
}
