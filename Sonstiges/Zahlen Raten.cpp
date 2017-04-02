#include<stdlib.h>
#include<time.h>
#include<iostream>
#include<conio.h>
#include<string>
#include<sstream>
using namespace std;
int main()
{	
	bool again = true;
	
	while(again==true)
	{
		short randNumber = 0, tries = 0, number = 0;
		std::string input;
		
		std::cout << "Errate die richtige Zahl zwischen 1 und 100: ";
		
		srand(time(NULL));
		randNumber = rand()%100+1;
		
		while(number!=randNumber)
		{
			tries++;
			getline(std::cin, input);
			stringstream(input) >> number;
			
			if(number<randNumber)
			{
				std::cout << "\nDie eingegebene Zahl ist zu klein! Versuche es erneut: ";
			}
			if(number>randNumber)
			{
				std::cout << "\nDie eingegebene Zahl ist zu gro\xE1! Versuche es erneut: ";
			}
		}
		
		number = 0;
		
		//Zusatzaufgabe: Berechne die minimal notwendige Anzahl an Versuchen
		std::cout << "\nTreffer! Du hast " << tries << " Versuche gebraucht.\nWenn du ein 2. mal spielen m\x94 \bchtest, gib \"1\" ein. Zum beenden w\x84hle eine beliebige Eingabe: ";
		getline(std::cin, input);
		stringstream(input) >> randNumber;
		std::cout << endl << endl;
		if(randNumber == 1) again = randNumber;
	}
	
	return(0);
}
