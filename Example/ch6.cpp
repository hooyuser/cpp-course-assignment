#pragma warning(disable:4996)
#include<iostream>

using namespace std;

//P6_1
namespace P6_1
{
	const double PI = 3.14159;

	class Point
	{
	private:
		int X, Y;
	public:
		Point(int X = 0, int Y = 0)
		{
			this->X = X, this->Y = Y;
		}
		void move(int OffX, int OffY)
		{
			X += OffX, Y += OffY;
		}
		void ShowXY()
		{
			cout << "(" << X << "," << Y << ")" << endl;
		}
	};

	class Circle :public Point
	{
	private:
		double radius;
	public:
		Circle(double R, int X, int Y) :Point(X, Y)
		{
			radius = R;
		}
		double area()
		{
			return PI * radius*radius;
		}
		void ShowCircle()
		{
			cout << "Center of Circle:";
			ShowXY();
			cout << "radius:" << radius << endl;
		}
	};

	void P6_1()
	{
		Circle Cirl(10, 100, 200);
		Cirl.ShowCircle();
		cout << "area is:" << Cirl.area() << endl;
		Cirl.move(10, 20);
		Cirl.ShowXY();
	}
}

//P6_2
namespace P6_2
{
	const double PI = 3.14159;

	class Point
	{
	protected:
		int X, Y;
	public:
		Point(int X = 0, int Y = 0)
		{
			this->X = X, this->Y = Y;
		}
		void move(int OffX, int OffY)
		{
			X += OffX, Y += OffY;
		}
		void ShowXY()
		{
			cout << "(" << X << "," << Y << ")" << endl;
		}
	};

	class Circle :protected Point
	{
	protected:
		double radius;
	public:
		Circle(double R, int X, int Y) :Point(X, Y)
		{
			radius = R;
		}
		double area()
		{
			return PI * radius*radius;
		}
		void ShowCircle()
		{
			cout << "Center of Circle:";
			ShowXY();
			cout << "radius:" << radius << endl;
		}
	};

	class Cylinder :protected Circle
	{
	private:
		double height;
	public:
		Cylinder(int X, int Y, double R, double H) :Circle(R, X, Y)
		{
			height = H;
		}
		double area()
		{
			return 2 * Circle::area() + 2 * PI * radius * height;
		}
		double volume()
		{
			return Circle::area() * height;
		}
		void ShowCylinder()
		{
			ShowCircle();
			cout << "height of cylinder:" << height << endl;
		}
	};

	void P6_2()
	{
		Cylinder CY(100, 200, 10, 50);
		CY.ShowCylinder();
		cout << "total area:" << CY.area() << endl;
		cout << "volume:" << CY.volume() << endl;
	}
}


//P6_3
namespace P6_3
{
	class Point
	{
	protected:
		int X, Y;
	public:
		Point(int X = 0, int Y = 0)
		{
			this->X = X, this->Y = Y;
			cout << "point(" << X << "," << Y << ") constructing..." << endl;
		}
		~Point()
		{
			this->X = X, this->Y = Y;
			cout << "point(" << X << "," << Y << ") destructing..." << endl;
		}
	};

	class Circle :protected Point
	{
	protected:
		double radius;
	public:
		Circle(double R, int X, int Y) :Point(X, Y)
		{
			radius = R;
			cout << "circle constructing, radius:" << R << endl;
		}
		~Circle()
		{
			cout << "circle destructing, radius:" << radius << endl;
		}
	};

}