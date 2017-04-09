#include<iostream>
#include<sstream>
#include<string>
#include<math.h>
#include<conio.h>

#define PI 3.14159

int main()
{
	std::string input;
	long double a, b, c, alpha, beta, gamma;
	
	std::cout << "F\x81ge deiner Eingabe \"\xF8\" hinzu um einen Winkel im Gradma\xE1 einzugeben.\n\nGib Seite a oder Winkel alpha ein: ";
	do
	{
		a = 0; alpha = 0;
		getline(std::cin, input);
		for(char cha : input) if(cha=='\xF8') a++;
		
		if(a==1)
		{
			a = 0;
			std::stringstream(input) >> alpha;
			alpha = alpha/180*PI;
			if(alpha>=PI || alpha<=0) std::cout << "ERROR: Mit dem eingegebenen Winkel l\x84sst sich kein Dreieck konstruieren. Gib alpha oder a erneut ein: ";
		}
		else
		{
			std::stringstream(input) >> a;
			if(a<=0) std::cout << "ERROR: a muss gr\x94\xE1 \ber als 0 sein. Gib a oder alpha erneut ein: ";
		}
	}while(alpha>=PI || a+alpha<=0);
	
	std::cout << "\nGib Seite b oder Winkel beta ein: ";
	do
	{
		b = 0; beta = 0;
		getline(std::cin, input);
		for(char cha : input) if(cha=='\xF8') b++;
		
		if(b!=0)
		{
			b = 0;
			std::stringstream(input) >> beta;
			beta = beta/180*PI;
			if(alpha+beta>=PI || beta<=0) std::cout << "ERROR: Mit den eingegebenen Winkeln l\x84sst sich kein Dreieck konstruieren. Gib beta oder b erneut ein: ";
		}
		else
		{
			std::stringstream(input) >> b;
			if(b<=0) std::cout << "ERROR: b muss gr\x94\xE1 \ber als 0 sein. Gib b oder beta erneut ein: ";
		}
	}while(alpha+beta>=PI || b+beta<=0);
	
	std::cout << "\nGib Seite c oder Winkel gamma ein: ";
	do
	{
		c = 0; gamma = 0;
		getline(std::cin, input);
		for(char cha : input) if(cha=='\xF8') c++;
		
		if(c!=0)
		{
			c = 0;
			if(alpha!=0 && beta!=0) std::cout << "ERROR: Der Kongruenzsatz WWW existiert nicht. Gib gamma oder c erneut ein: ";
			else
			{
				std::stringstream(input) >> gamma;
				gamma = gamma/180*PI;
				if(alpha+beta+gamma>=PI || gamma<=0) std::cout << "ERROR: Mit den eingegebenen Winkeln l\x84sst sich kein Dreieck konstruieren. Gib gamma oder c erneut ein: ";
			}
		}
		else
		{
			std::stringstream(input) >> c;
			if(c<=0) std::cout << "ERROR: c muss gr\x94\xE1 \ber als 0 sein. Gib c oder gamma erneut ein: ";
		}
	}while(alpha+beta+gamma>PI || c+gamma<=0);
	
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
		
		if(alpha==beta && beta==gamma) //fängt den Sondefall eines gleichseitigen Dreiecks ab, welcher mit der obigen Methode nicht exakt berechnet wird.
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
	
	getch();
	return(0);
}
