#include<iostream>
#include<conio.h>
#include<string>
#include<sstream>

//Zwei verschiedene natürliche Zahlen,
//von denen wechselseitig jeweils eine Zahl gleich der Summe der echten Teiler der anderen Zahl ist,
//bilden ein Paar befreundeter Zahlen.

int main()
{
	std::string input;
	unsigned int amount;
	
	std::cout << "Gib an bis zu welcher Zahl nach befreundeten Zahlen gesucht werden soll: ";
	getline(std::cin, input);
	std::stringstream(input) >> amount;
	
	if(amount<284)
	{
		std::cout << "\nEs wurden keine befreundeten Zahlen gefunden.";
		getch();
		return(0);
	}
	
	std::cout << "\nBefreundete Zahlen sind:\n";
	
	amount -= 219;
	
	//Wenn amount oberhalb von 500000 ist, würde das Programm beim Erstellen des Arrays abstürzen.
	//Dies lässt sich lösen indem man kein Array anlegt,
	//sondern die Teilersumme jeder Teilersumme von Zahlen ab 220 darauf überprüft ob sie mit der jeweiligen Zahl identisch sind.
	//Das Programm dazu existiert bereits unte dem Namen "befreundete Zahlen 2".
	
	if(amount>500000) amount = 500000;
	
	unsigned int number[amount];
	
	for(unsigned long long idx = 0;  idx<amount;  idx++)
	{
		number[idx] = 0;
		
		for(unsigned long long factor = 1;  factor*2<=idx+220; factor++) if((idx+220)%factor==0) number[idx] += factor;
		
		if(number[idx]<idx+220 && number[idx]>=220 && number[number[idx]-220]==idx+220) std::cout << number[idx] << "	und	" << number[number[idx]-220] << "\n"; 
	}
	
	getch();
	return(0);
}
