#include<iostream>
#include<string>
#include<sstream>
#include<conio.h>

int main()
{
	short depth = 1;
	std::string input;
	
	std::cout << "Gib die Tiefe ein: ";
	do
	{
		getline(std::cin, input);
		std::stringstream(input) >> depth;
		if(depth<2 || depth==SHRT_MAX)std::cout << "ERROR: Die Zahl ist zu gro\xE1 oder klein. Gib die Tiefe erneut ein: ";		
	}while(depth<2 || depth==SHRT_MAX);
	
	
	for(short idx = 0;  idx<depth*depth;  std::cout << "*") if(idx++%depth==0) std::cout << "\n";
	
	
	std::cout << "\n";
	
	
	for(short idx = 0;  idx<depth;  idx++)
	{
		std::cout << "\n";
		for(short idx2 = 0;  idx2<idx;  idx2++) std::cout << " ";
		for(short idx2 = 0;  idx2<depth*2-1-2*idx;  idx2++) std::cout << "*";
	}
	
	
	std::cout << "\n\n";
	
	
	for(short idx = 0;  idx<depth-1;  std::cout << "\n")
	{	
		for(short idx2 = 0;  idx2<depth-idx-1;  idx2++) std::cout << " ";
		std::cout << "*";
		for(short idx2 = 0;  idx2<2*idx-1;  idx2++) std::cout << " ";
		if(idx++>0) std::cout << "*";
	}
	for(short idx = 0;  idx<2*depth-1;  idx++) std::cout << "*";
	for(short idx = 0;  idx<depth-2;  idx++)
	{
		std::cout << "\n*";
		for(short idx2 = 0;  idx2<2*depth-3;  idx2++) std::cout << " ";
		std::cout << "*";
	}
	std::cout << "\n";
	for(short idx = 0;  idx<2*depth-1;  idx++) std::cout << "*";
	
	std::cout << "\n\n\nProgrammende!";
	getch();
	return(0);
}
