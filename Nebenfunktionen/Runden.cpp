#include <iostream>

long double Runden(long double Zahl, int NK=0, bool mathematisch=true)
{
	//Rückgabe Zahl auf NK Nachkommastellen gerundet
	long long Schleife;
	
	for(Schleife=NK;Schleife>0;Schleife--) Zahl*=10;
	for(Schleife=NK;Schleife<0;Schleife++) Zahl/=10;
	if(Zahl-(long long)Zahl>0.5 || Zahl-(long long)Zahl==0.5 && (mathematisch=false || (long long)Zahl%2!=0)) Zahl++;
	
	Zahl=(long long)Zahl;
	for(Schleife=NK;Schleife>0;Schleife--) Zahl/=10;
	for(Schleife=NK;Schleife<0;Schleife++) Zahl*=10;
	
	return(Zahl);
}
