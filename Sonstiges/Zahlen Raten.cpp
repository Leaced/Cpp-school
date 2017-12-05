#include<stdlib.h>
#include<time.h>
#include<iostream>
#include<conio.h>
#include<string>
#include<sstream>

//Zusatzaufgabe: Berechne die minimal notwendige Anzahl an Versuchen

int main()
{	
	std::string input;
	
	do
	{
		srand(time(NULL));
		short randNumber = rand()%100+1, tries = 0, number;

		printf("Errate die richtige Zahl zwischen 1 und 100: ");
		
		do
		{		
			tries++;
			getline(std::cin, input);
			std::stringstream(input) >> number;
			
			if(number<1 || number>100) printf("Error: Die eingegebene Zahl liegt nicht im Wertebereich. Gib eine Zahl zwischen 1 und 100 ein: ");
			else if(number<randNumber) printf("\nDie eingegebene Zahl ist zu klein! Versuche es erneut: ");		
			else if(number>randNumber) printf("\nDie eingegebene Zahl ist zu gro\xE1! Versuche es erneut: ");		
		}while(number!=randNumber || number<1 || number>100);
		
		printf("\nTreffer! Du hast %i Versuche gebraucht.\nM\x94 \bchtest du ein 2. mal spielen? y/n ", tries);
		do
		{
			getline(std::cin, input);
			if(input != "y" && input != "Y" && input != "n" && input !="N") printf("Error: Die Eingabe ist ung\x81ltig. M\x94 \bchtest du ein 2. mal spielen? y/n ");
			else printf("\n\n");
		}while(input != "y" && input != "Y" && input != "n" && input !="N");
	}while(input == "y" || input ==  "Y");
	
	return(0);
}
