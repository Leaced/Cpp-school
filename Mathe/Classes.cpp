#include<iostream>
#include<string>
#include<sstream>
#include<math.h>

class Point
{
	public:
		double X, Y;
		
		void setX(double x)
		{
			X = x;
		}
		
		void setY(double y)
		{
			Y = y;
		}
		
		Point(double x = 0, double y = 0)
		{
			X = x;
			Y = y;
		}
		
		void print()
		{
			std::cout << "(" << X << "," << Y << ")";
		}
};

class Line
{
	public:
		Point P, Q;
		double b, m;
		
		void setPoint(bool p, Point point)
		{
			if(p==0)
			{
				Q.setX(point.X);
				Q.setY(point.Y);
			}
			else
			{
				P.setX(point.X);
				P.setY(point.Y);
			}
		}
		
		void distance()
		{
			std::cout << sqrt((P.X-Q.X)*(P.X-Q.X)+(P.Y-Q.Y)*(P.Y-Q.Y));
		}
		
		void gradient()
		{
			m = (P.Y-Q.Y)/(P.X-Q.X);
		}
		
		void nullPointX()
		{
			b = (-P.X)*(P.Y-Q.Y)/(P.X-Q.X)+(P.Y);
			std::cout << b;
		}
		
		void nullPointY()
		{
			std::cout << (P.X)*(P.Y-Q.Y)/(P.X-Q.X)/((P.Y-Q.Y)/(P.X-Q.X));
		}
		
		void print()
		{
			gradient();
			
			std::cout << m <<"*x + ";
			
			nullPointX();
		}
};

int main()
{
	Point P(3,5), Q(5,3);
	Line g;
	g.setPoint(0, Q);
	g.setPoint(1, P);
	g.print();
	getchar();
}
