#include<stdlib.h>
#include<time.h>
#include<iostream>
#include<conio.h>
#include<string>
#include<sstream>

int main()
{	
	bool again = true;
	
	while(again)
	{
		srand(time(NULL));
		again = false;
		short randNumber = rand()%100+1, tries = 0, number = 0;
		std::string input;
		
		std::cout << "Errate die richtige Zahl zwischen 1 und 100: ";
		
		while(number!=randNumber)
		{		
			do
			{
				tries++;
				getline(std::cin, input);
				std::stringstream(input) >> number;
				if(number<1 || number>100) std::cout << "Die eingegebene Zahl liegt nicht im Wertebereich. Gib eine Zahl zwischen 1 und 100 ein: ";
			}while(number<1 || number>100);
			
			if(number<randNumber) std::cout << "\nDie eingegebene Zahl ist zu klein! Versuche es erneut: ";		
			else if(number>randNumber) std::cout << "\nDie eingegebene Zahl ist zu gro\xE1! Versuche es erneut: ";		
		}
		
		//Zusatzaufgabe: Berechne die minimal notwendige Anzahl an Versuchen
		std::cout << "\nTreffer! Du hast " << tries << " Versuche gebraucht.\nM\x94 \bchtest du ein 2. mal spielen? y/n ";
		getline(std::cin, input);
		if(input == "y" || input == "Y") again = true;
		std::cout << "\n\n";
	}
	
	return(0);
}
