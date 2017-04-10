#include<iostream>

using namespace std;
long double Kommazahl(const std::string& str)
{
	/*long double Zahl; //Alternative mit stold welche in der Deklaration der Nebenfunktion zusätzlich einen boolean wert benötigt ob es mt oder ohne Kommas arbeiten soll
	bool Minus = false;
	std::string::size_type idx;
	std::string FNum = "";
	
	for(char c:str)
	{
		if(c>='0' && c<='9') FNum += c;
		else if(c == '-') Minus = true;
		else if((c=='.' || c==',') && Komma) Komma = false, FNum += c;
	}
	
	Zahl = std::stold(FNum,&idx);
	if(Minus) Zahl*=-1;
	return(Zahl);*/
	
	bool Komma=false, Minus=false;
	long double Zahl = 0;
	unsigned short Stelle = 0;
	for(char c : str)
	{
		if(c>='0' && c<='9')
		{
			if(Komma == false)
			{
				Zahl *= 10;
				Zahl += c - '0';
			}
			else
			{
				long double Zahl2 = c - '0';
				for(unsigned short idx = 0; idx <= Stelle; idx++) Zahl2/=10;
				Zahl += Zahl2;
				Stelle++;
			}
		}
		else if(c=='.') Komma=true;
		else if(c=='-') Minus=true;
	}
	if(Minus==true) Zahl*=-1;
	return(Zahl);
}
