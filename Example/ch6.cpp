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

	class tube : protected Circle
	{
	private:
		double height;
		Circle InCircle;
	public:
		tube(double H, double R1, double R2 = 0, int X = 0, int Y = 0) :InCircle(R2, X, Y), Circle(R1, X, Y)
		{
			height = H;
			cout << "tube constructing, height:" << H << endl;
		}
		~tube()
		{
			cout << "tube destructing, height:" << height << endl;
		}
	};

	void P6_3()
	{
		tube TU(100, 20, 5);
	}
}

//P6_4
namespace P6_4
{
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

	class Circle :public Point
	{
	protected:
		double radius;
	public:
		Circle(int X, int Y, double R) :Point(X, Y)
		{
			radius = R;
		}
		void ShowCircle()
		{
			cout << "Center of Circle:";
			ShowXY();
			cout << "radius:" << radius << endl;
		}
	};

	class Cylinder :public Circle
	{
	private:
		double height;
	public:
		Cylinder(int X, int Y, double R, double H) :Circle(X, Y, R)
		{
			height = H;
		}
		void ShowCylinder()
		{
			ShowCircle();
			cout << "height of cylinder:" << height << endl;
		}
	};

	void P6_4()
	{
		Point P(1, 1);
		Circle Cir(20, 20, 15.5);
		Cylinder CY(300, 300, 15.5, 50);
		Point* Pp;
		Pp = &P;
		Pp->ShowXY();
		Pp = &Cir;
		Pp->ShowXY();
		Pp = &CY;
		Pp->ShowXY();
		Circle& RC = CY;
		RC.ShowXY();
		P = Cir;
		P.ShowXY();
	}
}

//P6_5
namespace P6_5
{
	class Car
	{
	private:
		int power;
		int seat;
	public:
		Car(int power, int seat)
		{
			this->power = power, this->seat = seat;
		}
		void show()
		{
			cout << "car power:" << power << " seat:" << seat << endl;
		}
	};

	class Wagon
	{
	private:
		int power;
		int load;
	public:
		Wagon(int power, int load)
		{
			this->power = power, this->load = load;
		}
		void show()
		{
			cout << "wagon power:" << power << " load:" << load << endl;
		}
	};

	class StationWagon :public Car, public Wagon
	{
	public:
		StationWagon(int power, int seat, int load) :Wagon(power, load), Car(power, seat)
		{
		}

		void ShowSW()
		{
			cout << "StationWagon:" << endl;
			Car::show();
			Wagon::show();
		}
	};

	void P6_5()
	{
		StationWagon SW(105, 3, 8);
		//SW.show();                     //错误，出现二义性
		SW.ShowSW();
	}
}

//P6_6
namespace P6_6
{
	class Automobile
	{
	private:
		int power;
	public:
		Automobile(int power)
		{
			this->power = power;
		}
		void show()
		{
			cout << " power:" << power;
		}

	};

	class Car :public Automobile
	{
	private:
		int seat;
	public:
		Car(int power, int seat) :Automobile(power)
		{
			this->seat = seat;
		}
		void show()
		{
			cout << "car:";
			Automobile::show();
			cout << " seat:" << seat << endl;
		}
	};

	class Wagon :public Automobile
	{
	private:
		int load;
	public:
		Wagon(int power, int load) :Automobile(power)
		{
			this->load = load;
		}
		void show()
		{
			cout << "wagon:";
			Automobile::show();
			cout << " load:" << load << endl;
		}
	};

	class StationWagon :public Car, public Wagon
	{
	public:
		StationWagon(int CPower, int WPower, int seat, int load) :Car(CPower, seat), Wagon(WPower, load)
		{
		}

		void show()
		{
			cout << "StationWagon:" << endl;
			Car::show();
			Wagon::show();
		}
	};

	void P6_6()
	{
		StationWagon SW(105, 108, 3, 8);
		SW.show();
	}
}

//P6_7
namespace P6_7
{
	class Automobile
	{
	private:
		int power;
	public:
		Automobile(int power)
		{
			this->power = power;
			cout << "Automobile constructing..." << endl;
		}
		void show()
		{
			cout << " power:" << power;
		}

	};

	class Car :virtual public Automobile
	{
	private:
		int seat;
	public:
		Car(int power, int seat) :Automobile(power)
		{
			this->seat = seat;
			cout << "Car constructing..." << endl;
		}
		void show()
		{
			cout << "car:";
			Automobile::show();
			cout << " seat:" << seat << endl;
		}
	};

	class Wagon :virtual public Automobile
	{
	private:
		int load;
	public:
		Wagon(int power, int load) :Automobile(power)
		{
			this->load = load;
			cout << "Wagon constructing..." << endl;
		}
		void show()
		{
			cout << "wagon:";
			Automobile::show();
			cout << " load:" << load << endl;
		}
	};

	class StationWagon :public Car, public Wagon
	{
	public:
		StationWagon(int CPower, int WPower, int seat, int load) :Automobile(CPower), Car(WPower, seat), Wagon(CPower, load)
		{
			cout << "StationWagon constructing..." << endl;
		}

		void show()
		{
			cout << "StationWagon:" << endl;
			Car::show();
			Wagon::show();
		}
	};

	void P6_7()
	{
		StationWagon SW(105, 108, 3, 8);
		SW.show();
	}
}