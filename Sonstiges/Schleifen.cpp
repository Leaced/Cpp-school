#include<iostream>
#include<string>
#include<sstream>
#include<conio.h>
#include <stdio.h>

int main()
{
	short depth = 1;
	std::string input;
	
	printf("Gib die Tiefe ein: ");
	do
	{
		getline(std::cin, input);
		std::stringstream(input) >> depth;
		if(depth<2 || depth==SHRT_MAX)printf("ERROR: Die Zahl ist zu gro\xE1 oder klein. Gib die Tiefe erneut ein: ");		
	}while(depth<2 || depth==SHRT_MAX);
	
	
	for(short idx = 0;  idx<depth*depth;  printf("*")) if(idx++%depth==0) printf("\n");
	
	
	printf("\n");
	
	
	for(short idx = 0;  idx<depth;  idx++)
	{
		printf("\n");
		for(short idx2 = 0;  idx2<idx;  idx2++) printf(" ");
		for(short idx2 = 0;  idx2<depth*2-1-2*idx;  idx2++) printf("*");
	}
	
	
	printf("\n\n");
	
	
	for(short idx = 0;  idx<depth-1;  printf("\n"))
	{	
		for(short idx2 = 0;  idx2<depth-idx-1;  idx2++) printf(" ");
		printf("*");
		for(short idx2 = 0;  idx2<2*idx-1;  idx2++) printf(" ");
		if(idx++>0) printf("*");
	}
	for(short idx = 0;  idx<2*depth-1;  idx++) printf("*");
	for(short idx = 0;  idx<depth-2;  idx++)
	{
		printf("\n*");
		for(short idx2 = 0;  idx2<2*depth-3;  idx2++) printf(" ");
		printf("*");
	}
	printf("\n");
	for(short idx = 0;  idx<2*depth-1;  idx++) printf("*");
	
	printf("\n\n\nProgrammende!");
	getch();
	return(0);
}
