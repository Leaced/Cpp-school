#include<iostream>
#include<string>
#include<sstream>
#include<conio.h>

int main()
{
	std::string input;
	unsigned long long max = 1;
	
	std::cout << "Gib an bis zu welcher Zahl nach befreundeten Zahlen gesucht werden soll: ";
	
	getline(std::cin, input);
	std::stringstream(input) >> max;
	
	if(max<284)
	{
		std::cout << "\nEs wurden keine befreundeten Zahlen gefunden.";
		getch();
		return(0);
	}
	
	std::cout << "\nbefreundete Zahlen sind:\n";
	
	for(unsigned long long number = 284;  number<=max;  number++)
	{	
		unsigned long long sum = 0, sum2 = 0;
		
		for(unsigned long long factor = 1;  factor*2<=number; factor++) if(number%factor==0) sum += factor;
		
		if(sum<number && sum>=220) for(unsigned long long factor = 1;  factor*2<=sum; factor++) if(sum%factor==0) sum2 += factor;
		if(sum2==number) std::cout << sum << "	und	" << sum2 << "\n";
	}
	
	getch();
	return(0);
}
