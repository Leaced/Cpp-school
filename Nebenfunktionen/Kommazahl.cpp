#include<iostream>

long double stringToFloat(const std::string& strng, bool decimalPoint)
{
	/*Alternative mit stold welche in der Deklaration der Nebenfunktion zusätzlich einen Boolean "Komma" benötigt,
	welcher angibt ob es mt oder ohne Kommas arbeiten soll
	
	long double number; 
	bool minus = false;
	std::string::size_type idx;
	std::string FNum = "";
	
	for(char c:str)
	{
		if(c>='0' && c<='9') FNum += c;
		else if(c == '-') minus = true;
		else if((c=='.' || c==',') && decimalPoint) decimalPoint = false, FNum += c;
	}
	
	number = std::stold(FNum, &idx);
	
	if(minus) Zahl*=-1;
	
	return(number);*/
	
	bool DP = false;
	long double number;
	unsigned short place = 0;
	
	for(char c : strng)
	{
		if(c>='0' && c<='9')
		{
			c = c-'0';
			
			if(!DP) number = number*10+c;
			else
			{
				long double number2 = c;
				
				for(unsigned short loop = 0;  loop<=place;  loop++) number2 /= 10;
				
				number += number2, place++;
			}
		}
		else if((c=='.' || c==',') && decimalPoint) DP=true;
	}
	
	return(number);
}
