#include<iostream>

long double round(long double number, long long digitsAfterDecimalPoint, bool mathematical)
{	
	short loop = digitsAfterDecimalPoint;
	
	while(loop>0) number *= 10, loop--;
	while(loop<0) number /= 10, loop++;
	
	if(number-(long long)number>0.5 || number-(long long)number==0.5 && ((long long)number%2!=0 || mathematical==false)) number++;
	
	number = (long long)number;
	
	while(digitsAfterDecimalPoint>0) number /= 10, digitsAfterDecimalPoint--;
	while(digitsAfterDecimalPoint<0) number *= 10, digitsAfterDecimalPoint++;
	
	return(number);
}
