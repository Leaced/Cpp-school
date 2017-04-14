#include<conio.h>
#include<iostream>
#include<sstream>
#include<new>

//In Zusammenarbeit mit Nils Werner

//Zwei verschiedene natürliche Zahlen,
//von denen wechselseitig jeweils eine Zahl gleich der Summe der echten Teiler der anderen Zahl ist,
//bilden ein Paar befreundeter Zahlen.

int divSum(int number);
void program();

int main()
{
	program();
	
	std::cout << "\n\nProgrammende!";
	
	getch();
	return(0);
}

int divSum(int number)
{
	int sum = 0;
	for (int idx = 1; idx*2 <= number; idx++) if(number%idx==0) sum += idx;
	return (sum);	
}

void program()
{
	unsigned long long limit = 0;
	std::string input;
	
	do{
		std::cout<< "Gib ein Limit ein: ";	
		getline(std::cin, input);
		std::stringstream(input)>>limit;
		if(limit>=ULLONG_MAX || limit<0) std::cerr << "Error: Dieses Limit ist nicht m\x94glich. ";
	}while(limit>=ULLONG_MAX || limit<0);
	
	try
	{
		unsigned long long *number = new unsigned long long[limit+1];
		
		std::cout<< "befreundete Zahlen sind:\n";
		
		for (int idx = 220; idx<= limit; idx++)
		{
			number[idx] = divSum(idx);
			if(idx > number[idx]) if (idx==number[number[idx]]) std::cout << idx << "	und	" << number[idx] << "\n";
		}
		
		delete[] number;
	}
	catch(std::bad_alloc& ba)
	{
		std::cerr << "Error: Es konnte kein Array dieser Gr\x94\xE1 \be erstellt werden. ";
		program();
	}
	
}
