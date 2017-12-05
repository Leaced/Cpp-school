#include<iostream>
#include<conio.h>
#include<string>
#include<sstream>

//Der Body-Mass-Index (BMI) - auch Körpermasseindex (KMI), Körpermassenzahl (KMZ) oder Quetelet-Kaup-Index - ist eine Maßzahl für die Bewertung des Körpergewichts eines Menschen in Relation zu seiner Körpergröße.

int main()
{
	long double height = 0, weight = 0;
	std::string input;
	
	printf("Gib deine Gr\x94\xE1 \be in metern ein: ");
	do
	{
		getline(std::cin,input);
		std::stringstream(input)>>height;
		if(height<0.5 || height>2.5) printf("ERROR: Die eingegebene Gr\x94\xE1 \be ist nicht im Wertebereich. Bitte gib eine Gr\x94\xE1 \be von 0,5 bis 2,5 ein: ");
	}while(height<0.5 || height>2.5);
	
	printf("...und jetzt dein Gewicht in Kilogramm: ");
	do
	{
		getline(std::cin,input);
		std::stringstream(input)>>weight;
		if(weight<30 || weight>500) printf("ERROR: Das eingegebene Gewicht ist nicht im Wertebereich. Bitte gib ein Gewicht von 30 bis 500 ein: ");
	}while(weight<30 || weight>500);
	
	printf("\nDein BMI ist: %f", weight/(height*height));
	
	getch();
	return(0);
}
