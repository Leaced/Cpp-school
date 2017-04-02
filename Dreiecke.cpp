#include<iostream>
#include<sstream>
#include<string>
#include<math.h>

#define PI 3.14159

int main()
{
	std::string input;
	long double a = 0, b = 0, c = 0, alpha = 0, beta = 0, gamma = 0;
	
	std::cout << "F\x81ge deiner Eingabe \"\xF8\" hinzu um einen Winkel im Gradma\xE1 einzugeben.\n\nGib Seite a oder Winkel alpha ein: ";
	getline(std::cin, input);
	
	for(char cha : input) if(cha=='\xF8') a++;
	
	if(a!=0)
	{
		std::stringstream(input) >> alpha;
		
		if(alpha>180 || alpha==0)
		{
			std::cout << "ERROR: Mit dem angegebenen Winkel lässt sich kein Dreieck konstruieren.";
			return(1);
		}
		
		alpha = alpha/180*PI;
		a = 0;
	}
	else std::stringstream(input) >> a;
	
	if(a+alpha<0)
	{
		std::cout << "ERROR: Konstruktion eines Dreiecks mit negativen Werten nicht m\x94glich.";
		return(1);
	}
	
	std::cout << "Gib Seite b oder Winkel beta ein: ";
	getline(std::cin, input);

	for(char cha : input) if(cha=='\xF8') b++;
	
	if(b!=0)
	{
		std::stringstream(input) >> beta;
		
		if(beta>180 || beta==0)
		{
			std::cout << "ERROR: Mit dem angegebenen Winkel lässt sich kein Dreieck konstruieren.";
			return(1);
		}
		
		beta = beta/180*PI;
		b = 0;
	}
	else std::stringstream(input) >> b;
	
	if(b+beta<0)
	{
		std::cout << "ERROR: Konstruktion eines Dreiecks mit negativen Werten nicht m\x94glich.";
		return(1);
	}
	
	std::cout << "Gib Seite c oder Winkel gamma ein: ";
	getline(std::cin, input);
	
	for(char cha : input) if(cha=='\xF8') c++;
	
	if(c!=0)
	{
		std::stringstream(input) >> gamma;
		
		if(gamma>180 || gamma==0)
		{
			std::cout << "ERROR: Mit dem angegebenen Winkel lässt sich kein Dreieck konstruieren.";
			return(1);
		}
		
		gamma = gamma/180*PI;
		c = 0;
	}
	else std::stringstream(input) >> c;
	
	if(c+gamma<0)
	{
		std::cout << "ERROR: Konstruktion eines Dreiecks mit negativen Werten nicht m\x94glich.";
		return(1);
	}
	
	if(alpha!=0 && beta!=0 && gamma!=0)
	{
		std::cout << "ERROR: Der Kongruenzsatz WWW existiert nicht.";
		return(1);
	}
	
	if(alpha+beta+gamma>=PI)
	{
		std::cout << "ERROR: Die Winkelsumme \x81 \bbersteigt 180\xF8";
		return(1);
	}
	
	if(alpha!=0 && beta!=0 || alpha!=0 && gamma!=0 || beta!=0 && gamma!=0) //WSW
	{
		if(alpha==0)
		{
			alpha = PI-beta-gamma;
			b = a*sin(beta)/sin(alpha);
			c = a*sin(gamma)/sin(alpha);
		}
	
		if(beta==0)
		{
			beta = PI-alpha-gamma;
			a = b*sin(alpha)/sin(beta);
			c = b*sin(gamma)/sin(beta);
		}
	
		if(gamma=0)
		{
			gamma = PI-alpha-beta;
			a = c*sin(alpha)/sin(gamma);
			b = c*sin(beta)/sin(gamma);
		}
		
		if(alpha==beta && beta==gamma) //fängt den Sondefall eines gleichseitigen Dreiecks ab, welcher mit der obigen Methode nicht korrekt berechnet wird.
		{
			a = a+b+c;
			b = a;
			c = b;
		}
	}
	
	if(c==0 || b==0 || a==0) //SWS berechnet 3. Seite für SSS
	{
		if(a==0) a = sqrt(b*b+c*c-2*b*c*cos(alpha));
		if(b==0) b = sqrt(a*a+c*c-2*a*c*cos(beta));
		if(c==0) c = sqrt(a*a+b*b-2*a*b*cos(gamma));
	}
	
	if(alpha==0) alpha = acos((b*b+c*c-a*a)/(2*b*c)); //SSS
	if(beta==0) beta = acos((a*a+c*c-b*b)/(2*a*c));
	if(gamma==0) gamma = PI-alpha-beta;
	
	system("cls");
	
	std::cout << "a = " << a << ", b = " << b << ", c = " << c;
	std::cout << "\n\nWinkel			Bogenma\xE1	Gradma\xE1";
	std::cout << "\nalpha:			" << alpha/PI << " pi	" << alpha*180/PI << "\xF8";
	std::cout << "\nbeta:			" << beta/PI << " pi	" << beta*180/PI << "\xF8";
	std::cout << "\ngamma:			" << gamma/PI << " pi	" << gamma*180/PI << "\xF8";
	
	getchar();
	return(0);
}
