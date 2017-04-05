#include<iostream>
#include<string>
#include<sstream>

int main()
{
	long long depth;
	std::string input;
	
	std::cout << "Geben sie die Tiefe ein: ";
	
	do
	{
		getline(std::cin, input);
		std::stringstream(input) >> depth;
		if(depth<2)std::cout << "ERROR: Die Zahl muss größer als 1 sein. Geben sie die Tiefe erneut ein: ";		
	}while(depth<2);
	
	for(long long idx = 0;  idx<depth*depth;  idx++)
	{
		if(idx%depth==0) std::cout << "\n";
		std::cout << "*";
	}
	
	std::cout << "\n";
	
	for(long long idx = 0;  idx<depth;  idx++)
	{
		std::cout << "\n";
		
		for(long long idx2 = 0;  idx2<idx;  idx2++)
		{
			std::cout << " ";
		}
		
		for(long long idx2 = 0;  idx2<depth*2-1-2*idx;  idx2++)
		{
			std::cout << "*";
		}
	}
	
	std::cout << "\n\n";
	
	for(long long idx = 0;  idx<depth-1;  idx++)
	{	
		for(long long idx2 = 0;  idx2<depth-idx-1;  idx2++)
		{
			std::cout << " ";
		}
		
		std::cout << "*";
		
		for(long long idx2 = 0;  idx2<2*idx-1;  idx2++)
		{
			std::cout << " ";
		}
		
		if(idx>0) std::cout << "*";
		
		std::cout << "\n";
	}
	
	for(long long idx = 0;  idx<2*depth-1;  idx++)
	{
		std::cout << "*";
	}
	
	for(long long idx = 0;  idx<depth-2;  idx++)
	{
		std::cout << "\n*";
		
		for(long long idx2 = 0;  idx2<2*depth-3;  idx2++)
		{
			std::cout << " ";
		}
		
		std::cout << "*";
	}
	
	std::cout << "\n";
	
	for(long long idx = 0;  idx<2*depth-1;  idx++)
	{
		std::cout << "*";
	}
	
	std::cout << "\n\n\n\nProgrammende!";
	getchar();
	return(0);
}
