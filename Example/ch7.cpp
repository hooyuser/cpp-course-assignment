#pragma warning(disable:4996)
#include<iostream>

using namespace std;

//P7_1
namespace P7_1
{
	class Complex
	{
	private:
		double real;
		double image;
	public:
		Complex(double real = 0.0, double image = 0.0)
		{
			this->real = real, this->image = image;
		}
		void display()
		{
			cout << "(" << real << "," << image << ")" << endl;
		}
		friend Complex operator +(Complex A, Complex B)
		{
			return Complex(A.real + B.real, A.image + B.image);
		}
		friend Complex operator -(Complex A, Complex B);
		friend Complex operator -(Complex A);
		friend Complex operator ++(Complex& A);
		friend Complex operator ++(Complex& A, int);
	};

	Complex operator -(Complex A, Complex B)
	{
		return Complex(A.real - B.real, A.image - B.image);
	}
	Complex operator -(Complex A)
	{
		return Complex(-A.real, -A.image);
	}
	Complex operator ++(Complex& A)
	{
		return Complex(++A.real, A.image);
	}
	Complex operator ++(Complex& A, int)
	{
		return Complex(A.real++, A.image);
	}

	void P7_1()
	{
		Complex A(100.0, 200.0), B(-10.0, 20.0), C;
		cout << "A = ", A.display();
		cout << "B = ", B.display();
		C = A + B;
		cout << "C = A + B = ", C.display();
		C = A - B;
		cout << "C = A - B = ", C.display();
		C = -A + B;
		cout << "C = -A + B = ", C.display();
		C = A++;
		cout << "C = A++ = ", C.display();
		C = ++A;
		cout << "C = ++A = ", C.display();
		C = A + 5;
		cout << "C = A + 5 = ", C.display();
	}
}

//P7_2
namespace P7_2
{
	class Complex
	{
	private:
		double real;
		double image;
	public:
		Complex(double real = 0.0, double image = 0.0)
		{
			this->real = real, this->image = image;
		}
		void display()
		{
			cout << "(" << real << "," << image << ")" << endl;
		}
		Complex operator +(Complex B);
		Complex operator -(Complex B);
		Complex operator -();
		Complex operator ++();
		Complex operator ++(int);
	};

	Complex Complex::operator+(Complex B)
	{
		return Complex(real + B.real, image + B.image);
	}

	Complex Complex::operator -(Complex B)
	{
		return Complex(real - B.real, image - B.image);
	}
	Complex Complex::operator -()
	{
		return Complex(-real, -image);
	}
	Complex Complex::operator ++()
	{
		return Complex(++real, image);
	}
	Complex Complex::operator ++(int)
	{
		return Complex(real++, image);
	}

	void P7_2()
	{
		Complex A(100.0, 200.0), B(-10.0, 20.0), C;
		cout << "A = ", A.display();
		cout << "B = ", B.display();
		C = A + B;
		cout << "C = A + B = ", C.display();
		C = A - B;
		cout << "C = A - B = ", C.display();
		C = -A + B;
		cout << "C = -A + B = ", C.display();
		C = A++;
		cout << "C = A++ = ", C.display();
		C = ++A;
		cout << "C = ++A = ", C.display();
		C = A + 5;
		cout << "C = A + 5 = ", C.display();
	}
}

//P7_3
namespace P7_3
{
	class Complex
	{
	private:
		double real;
		double image;
	public:
		Complex(double real = 0.0, double image = 0.0)
		{
			this->real = real, this->image = image;
		}
		void display()
		{
			cout << "(" << real << "," << image << ")" << endl;
		}
		Complex operator +(Complex B);
		Complex operator =(Complex B);

	};

	Complex Complex::operator+(Complex B)
	{
		return Complex(real + B.real, image + B.image);
	}

	Complex Complex::operator =(Complex B)
	{
		real = B.real, image = B.image;
		cout << "operator = calling..." << endl;
		return *this;
	}


	void P7_3()
	{
		Complex A(100.0, 200.0), B(-10.0, 20.0), C;
		cout << "A = ", A.display();
		cout << "B = ", B.display();
		C = A + B;
		cout << "C = A + B = ", C.display();
		C = A;
		cout << "C = A = ", C.display();
	}
}

//P7_4
namespace P7_4
{
	class Complex
	{
	private:
		double real;
		double image;
	public:
		Complex(double real = 0.0, double image = 0.0)
		{
			this->real = real, this->image = image;
		}
		void display()
		{
			cout << "(" << real << "," << image << ")" << endl;
		}
	};

	class PComplex
	{
	private:
		Complex * PC;
	public:
		PComplex(Complex* PC = NULL)
		{
			this->PC = PC;
		}
		Complex* operator ->()
		{
			static Complex NullComplex(0, 0);  //避免指针为空
			if (PC == NULL)
			{
				return &NullComplex;
			}
			return PC;
		}

	};

	void P7_4()
	{
		PComplex P1;
		P1->display();
		Complex C1(100, 200);
		P1 = &C1;
		P1->display();

	}
}

//P7_5
namespace P7_5
{
	class String
	{
	private:
		char* Str;
		int len;
	public:
		void ShowStr()
		{
			cout << "string:" << Str << ",length: " << len << endl;
		}
		String(const char* p = NULL)
		{
			if (p)
			{
				len = strlen(p);
				Str = new char[len + 1];
				strcpy(Str, p);
			}
			else
			{
				len = 0;
				Str = NULL;
			}
		}
		~String()
		{
			if (Str != NULL)
			{
				delete[] Str;
			}
		}
		char& operator[](int n)
		{
			return *(Str + n);
		}
		const char& operator[](int n) const
		{
			return *(Str + n);
		}
	};

	void P7_5()
	{
		String S1("0123456789abcdef");
		S1.ShowStr();
		S1[10] = 'A';
		cout << "S1[10] = A" << endl;
		S1.ShowStr();
		const String S2("ABCDEFGHIJKLMN");
		cout << "S2[10] = " << S2[10] << endl;
	}
}



//P7_6
namespace P7_6
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
		double area()
		{
			return 0.0;
		}
	};
	const double PI = 3.14159;
	class Circle :public Point
	{
	protected:
		double radius;
	public:
		Circle(int X, int Y, double R) :Point(X, Y)
		{
			radius = R;
		}
		double area()
		{
			return PI * radius * radius;
		}
	};

	void P7_6()
	{
		Point P1(10, 10);
		cout << "P1.area() = " << P1.area() << endl;
		Circle C1(10, 10, 20);
		cout << "C1.area() = " << C1.area() << endl;
		Point* Pp;
		Pp = &C1;
		cout << "Pp->area() = " << Pp->area() << endl;
		Point& Rp = C1;
		cout << "Rp.area() = " << Rp.area() << endl;
	}
}

//P7_7
namespace P7_7
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
		virtual double area()
		{
			return 0.0;
		}
	};

	const double PI = 3.14159;

	class Circle :public Point
	{
	protected:
		double radius;
	public:
		Circle(int X, int Y, double R) :Point(X, Y)
		{
			radius = R;
		}
		double area()
		{
			return PI * radius * radius;
		}
	};

	void P7_7()
	{
		Point P1(10, 10);
		cout << "P1.area() = " << P1.area() << endl;
		Circle C1(10, 10, 20);
		cout << "C1.area() = " << C1.area() << endl;
		Point* Pp;
		Pp = &C1;
		cout << "Pp->area() = " << Pp->area() << endl;
		Point& Rp = C1;
		cout << "Rp.area() = " << Rp.area() << endl;
	}
}


//P7_8
namespace P7_8
{
	class A
	{
	public:
		virtual ~A()
		{
			cout << "A::~A() is called." << endl;
		}
		A()
		{
			cout << "A::A() is called." << endl;
		}
	};

	class B :public A
	{
	private:
		int* ip;
	public:
		B(int size = 0)
		{
			ip = new int[size];
			cout << "B::B() is called." << endl;
		}
		virtual ~B()
		{
			cout << "B::~B() is called." << endl;
			delete[] ip;
		}
	};

	void P7_8()
	{
		A* b = new B(10);
		delete b;
	}
}


//P7_9
namespace P7_9
{
	class Shape
	{
	public:
		virtual double area() const = 0;
		virtual void show() = 0;
	};

	class Point :public Shape
	{
	protected:
		int X, Y;
	public:
		Point(int X = 0, int Y = 0)
		{
			this->X = X, this->Y = Y;
		}
		double area() const
		{
			return 0.0;
		}
		void show()
		{
			cout << "(" << X << "," << Y << ")" << endl;
		}
	};

	const double PI = 3.14159;

	class Circle :public Point
	{
	protected:
		double radius;
	public:
		Circle(int X, int Y, double R) :Point(X, Y)
		{
			radius = R;
		}
		double area() const
		{
			return PI * radius * radius;
		}
		void show()
		{
			cout << "Center:" << "(" << X << "," << Y << ")" << endl;
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
		double area() const
		{
			return 2 * Circle::area() + 2 * PI * radius * height;
		}
		void show()
		{
			Circle::show();
			cout << "height of cylinder:" << height << endl;
		}
	};

	void P7_9()
	{
		Cylinder CY(100, 200, 10, 50);
		Shape* P;
		P = &CY;
		P->show();
		cout << "total area:" << P->area() << endl;
		Circle Cir(5, 10, 100);
		Shape& R = Cir;
		R.show();
	}
}



//P7_10
namespace P7_10
{
	class Person
	{
	protected:
		char name[20];
	public:
		Person(const char * iname) { strcpy(name, iname); }
		virtual void who_am_I() = 0;
		virtual ~Person()
		{
			cout << "~Person() called," << endl;
		}
	};

	class Student :public Person
	{
	private:
		char major[20]; //
	public:
		Student(const char * iname, const char * imajor) : Person(iname)
		{
			strcpy(major, imajor);
		}
		void who_am_I()
		{
			cout << "My name'is" << name << ", I major in" << major << endl;
		}
		~Student()
		{
			cout << "-Student() called!" << endl;
		}
	};

	class Teacher :public Person
	{
	private:
		char teach[20]; //iN B
	public:
		Teacher(const char * iname, const char * iteach) : Person(iname)
		{
			strcpy(teach, iteach);
		}
		void who_am_I()
		{
			cout << "My name is" << name << ", I teach" << teach << endl;
		}
		~Teacher()
		{
			cout << "~Teacher() called!" << endl;
		}
	};

	void P7_10()
	{
		Person* PersonArr[5];
		PersonArr[0] = new Student("Joe", "computer");
		PersonArr[1] = new Teacher("Mary", "mathmatics");
		PersonArr[2] = new Student("Jasmine", "physics");
		PersonArr[3] = new Teacher("Antony", "chemical");
		PersonArr[4] = new Student("Jayden", "biology");
		for (int i = 0; i < 5; i++)
		{
			PersonArr[i]->who_am_I();
		}
	}
}
