#include<iostream>
#include<conio.h>
#include<string>
#include<sstream>

//Dieses Programm berechnet wann sich 2 Autos auf einer Straße treffen wobei die Geschwindigkeit beider Autos schrittweise erhöht werden kann.

int main()
{
	std::string input;
	long double speed, distance, speedOppositeTrack, position;
	
	std::cout << "Gib die Strecke der Landstra\xE1 \be in km ein: ";
	do
	{
		getline(std::cin, input);
		std::stringstream(input) >> distance;
		if(distance<=0)std::cout << "ERROR: Die Strecke muss gr\x94\xE1 \ber als 0 km sein. Gib die Strecke erneut ein: ";	
	}while(distance<=0);
	
	
	std::cout << "Gib die Startgeschwindigkeit in km/h ein: ";
	do
	{
		getline(std::cin, input);
		std::stringstream(input) >> speed;
		if(speed<0 || speed>200) std::cout << "ERROR: Die Geschwindigkeit muss gr\x94\xE1 \ber als 0 km/h sein und darf 200 km/h nicht \x81 \bberschreiten. Gib die Geschwindigkeit erneut ein: ";
	}while(speed<0 || speed>200);
	
	std::cout << "Gib nun die Geschwindigkeit der Autos der gegen\x81 \bberliegenden Fahrbahn ein: ";
	do
	{
		getline(std::cin, input);
		std::stringstream(input) >> speedOppositeTrack;
		if(speedOppositeTrack<0 || speedOppositeTrack>200)std::cout << "ERROR: Die Geschwindigkeit muss gr\x94\xE1 \ber als 0 km/h sein und darf 200 km/h nicht \x81 \bberschreiten. Gib die Geschwindigkeit erneut ein: ";
	}while(speedOppositeTrack<0 || speedOppositeTrack>200);
	
	std::cout << "\nGib nach jeder Ausgabe \"+\"/\"-\" ein um deine Geschwindigkeit um 5 km/h zu verringern oder erh\x94 \bhen\nDie Autos treffen sich wie folgt:\n";
	
	for(long double time = distance/(speed+speedOppositeTrack), position = time*speed;  position<=distance;  position += speedOppositeTrack/(120*(speed+speedOppositeTrack))*speed, time += speedOppositeTrack/(120*(speed+speedOppositeTrack)))  //Formel fÃ¼r t nicht ausreichend.
	{
		if(position>ULLONG_MAX)
		{
			std::cout << "ERROR: Begegnung kann nicht berechnet werden.";
			break;
		}
		
		std::cout << (int)time << "h:" << (int)(time*60)%60 << "min:" << (int)(time*3600)%60 << "sec:	" << position << "km  	";
		
		getline(std::cin, input);
		
		if(input=="+") speed += 5;
		else if(input=="-") speed -= 5;
		if(-speed>speedOppositeTrack) break;
	}
	
	std::cout << "PROGRAMMENDE!";
	
	getch();
	return(0);
}
