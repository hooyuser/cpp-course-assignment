#pragma warning(disable:4996)
#include<iostream>

using namespace std;

//P5_1_A
namespace P5_1_A
{
	struct Clock
	{
		int H, M, S;
	};
	Clock MyClock;

	void SetTime(int H, int M, int S)
	{
		MyClock.H = (H >= 0 && H < 24) ? H : 0;
		MyClock.M = (M >= 0 && M < 60) ? M : 0;
		MyClock.S = (S >= 0 && S < 60) ? S : 0;
	}

	void ShowTime()
	{
		cout << MyClock.H << ":";
		cout << MyClock.M << ":";
		cout << MyClock.S << endl;
	}

	void P5_1_A()
	{
		ShowTime();
		SetTime(8, 30, 30);
		ShowTime();
	}
}

//P5_1_B
namespace P5_1_B
{
	class Clock
	{
	private:
		int H, M, S;
	public:
		void SetTime(int H, int M, int S)
		{
			H = (H >= 0 && H < 24) ? H : 0;
			M = (M >= 0 && M < 60) ? M : 0;
			S = (S >= 0 && S < 60) ? S : 0;
		}
		void ShowTime()
		{
			cout << H << ":" << M << ":" << S << endl;
		}
	};

	void P5_1_B()
	{
		Clock MyClock;
		MyClock.ShowTime();
		MyClock.SetTime(8, 30, 30);
		MyClock.ShowTime();
	}
}

//P5_2
namespace P5_2
{
	class Clock
	{
	private:
		int H, M, S;
	public:
		Clock(int h = 0, int m = 0, int s = 0)
		{
			H = h, M = m, S = s;
			cout << "constructor:" << H << ":" << M << ":" << S << endl;
		}
		~Clock()
		{
			cout << "destructor:" << H << ":" << M << ":" << S << endl;
		}
	};

	Clock C1(8, 0, 0);
	Clock C2(9, 0, 0);

	void P5_2()
	{
		Clock C3(10, 0, 0);
		Clock C4(11, 0, 0);
	}
}

//P5_3
namespace P5_3
{
	class String
	{
	private:
		char* Str;
		int len;
	public:
		void ShowStr()
		{
			cout << "string:" << Str << ",length:" << len << endl;
		}
		String()
		{
			len = 0;
			Str = NULL;
		}
		String(const char* p)
		{
			len = strlen(p);
			Str = new char[len + 1];
			strcpy(Str, p);
		}
		~String()
		{
			if (Str != NULL)
			{
				delete[] Str;
				Str = NULL;
			}
		}
	};

	void P5_3()
	{
		char s[] = "ABCDE";
		String s1(s);
		String s2("123456");
		s1.ShowStr();
		s2.ShowStr();
	}
}

//P5_4
namespace P5_4
{
	class Clock
	{
	private:
		int H, M, S;
	public:
		Clock(int h = 0, int m = 0, int s = 0)
		{
			H = h, M = m, S = s;
			cout << "constructor:" << H << ":" << M << ":" << S << endl;
		}
		~Clock()
		{
			cout << "destructor:" << H << ":" << M << ":" << S << endl;
		}
		Clock(Clock& p)
		{
			cout << "copy constructor,before call:" << H << ":" << M << ":" << S << endl;
			H = p.H;
			M = p.M;
			S = p.S;
		}
		void ShowTime()
		{
			cout << H << ":" << M << ":" << S << endl;
		}
	};

	Clock fun(Clock C)
	{
		return C;
	}

	void P5_4()
	{
		Clock C1(8, 0, 0);
		Clock C2(9, 0, 0);
		Clock C3(C1);
		fun(C2);
		Clock C4;
		C4 = C2;
	}
}


//P5_5
namespace P5_5
{
	class String
	{
	private:
		char* Str;
		int len;
	public:
		void ShowStr()
		{
			cout << "string:" << Str << ",length:" << len << endl;
		}
		String()
		{
			len = 0;
			Str = NULL;
		}
		String(const char* p)
		{
			len = strlen(p);
			Str = new char[len + 1];
			strcpy(Str, p);
		}
		String(String& r)
		{
			len = r.len;
			if (len != 0)
			{
				Str = new char[len + 1];
				strcpy(Str, r.Str);
			}
		}
		~String()
		{
			if (Str != NULL)
			{
				delete[] Str;
				Str = NULL;
			}
		}
	};

	void P5_5()
	{
		String s1("123456");
		String s2 = s1;
		s1.ShowStr();
		s2.ShowStr();
	}
}


//P5_6
namespace P5_6
{
	class Clock
	{
	private:
		int H, M, S;
	public:
		void SetTime(int h, int m, int s)
		{
			H = h, M = m, S = s;
		}
		void ShowTime()
		{
			cout << H << ":" << M << ":" << S << endl;
		}
		Clock(int h = 0, int m = 0, int s = 0)
		{
			H = h, M = m, S = s;
		}
		Clock(Clock& p)
		{
			H = p.H, M = p.M, S = p.S;
		}
		void TimeAdd(Clock* Cp);
		void TimeAdd(int h, int m, int s);
		void TimeAdd(int s);
	};

	void Clock::TimeAdd(Clock* Cp)
	{
		H = (Cp->H + H + (Cp->M + M + (Cp->S + S) / 60) / 60) % 24;
		M = (Cp->M + M + (Cp->S + S) / 60) % 60;
		S = (Cp->S + S) % 60;
	}

	void Clock::TimeAdd(int h, int m, int s)
	{
		H = (h + H + (m + M + (s + S) / 60) / 60) % 24;
		M = (m + M + (s + S) / 60) % 60;
		S = (s + S) % 60;
	}

	void Clock::TimeAdd(int s)
	{
		H = (H + (M + (s + S) / 60) / 60) % 24;
		M = (M + (s + S) / 60) % 60;
		S = (s + S) % 60;
	}

	void P5_6()
	{
		Clock C1;
		Clock C2(8, 20, 20);
		C1.TimeAdd(4000);
		C1.ShowTime();
		C2.TimeAdd(&C1);
		C2.ShowTime();
	}
}

//P5_7
namespace P5_7
{
	const int MaxN = 100;
	const double Rate = 0.6;

	class Score
	{
	private:
		long No;
		const char* Name;
		int Usual;
		int Final;
		int Total;

	public:
		Score(long no = 0, const char* name = NULL, int usual = 0, int final = 0, int total = 0);
		void Count();
		void ShowScore();
	};

	Score::Score(long no, const char* name, int usual, int final, int total)
	{
		No = no;
		Name = name;
		Usual = usual;
		Final = final;
		Total = total;
	}

	void Score::Count()
	{
		Total = Usual * Rate + Final * (1 - Rate) + 0.5;
	}

	void Score::ShowScore()
	{
		cout << No << "\t" << Name << "\t" << Usual << "\t" << Final << "\t" << Total << endl;
	}

	void P5_7()
	{
		Score ClassScore1[3];
		Score ClassScore2[3] =
		{
			Score(201407001,"Ye Xiaolu", 88, 79),
			Score(201407002,"Luo Zhangxing", 90, 85),
			Score(201407003,"Wu Weixue", 70, 55)
		};
		for (int i = 0; i < 3; i++)
			ClassScore2[i].Count();
		for (int i = 0; i < 3; i++)
			ClassScore2[i].ShowScore();
	}
}

//P5_8
namespace P5_8
{
	class Clock
	{
	private:
		int H, M, S;
	public:
		void SetTime(int h, int m, int s)
		{
			H = h, M = m, S = s;
		}
		void ShowTime()
		{
			cout << H << ":" << M << ":" << S << endl;
		}
		Clock(int h = 0, int m = 0, int s = 0)
		{
			H = h, M = m, S = s;
		}
		int GetH()
		{
			return H;
		}
		int GetM()
		{
			return M;
		}
		int GetS()
		{
			return S;
		}
	};

	class TrainTrip
	{
	private:
		const char* TrainNo;
		Clock StartTime;
		Clock EndTime;
	public:
		TrainTrip(const char* TrainNo, Clock S, Clock E)
		{
			this->TrainNo = TrainNo;
			StartTime = S;
			EndTime = E;
		}
		Clock TripTime()
		{
			int tH, tM, tS;
			int carry = 0;
			Clock tTime;
			(tS = EndTime.GetS() - StartTime.GetS()) > 0 ? carry = 0 : (tS += 60, carry = 1);
			(tM = EndTime.GetM() - StartTime.GetM() - carry) > 0 ? carry = 0 : (tM += 60, carry = 1);
			(tH = EndTime.GetH() - StartTime.GetH() - carry) > 0 ? carry = 0 : tH += 24;
			tTime.SetTime(tH, tM, tS);
			return tTime;
		}
	};

	void P5_8()
	{
		Clock C1(8, 10, 10), C2(6, 1, 2);
		Clock C3;
		TrainTrip T1("K16", C1, C2);
		C3 = T1.TripTime();
		C3.ShowTime();
	}
}

//P5_9
namespace P5_9
{
	class Student
	{
	private:
		char* Name;
		int No;
		static int countS;
	public:
		static int GetCount()
		{
			return countS;
		}
		Student(const char* = "", int = 0);
		Student(Student&);
		~Student();
	};

	Student::Student(const char* Name, int No)
	{
		this->Name = new char[strlen(Name) + 1];
		strcpy(this->Name, Name);
		this->No = No;
		++countS;
		cout << "constructing:" << Name << endl;
	}

	Student::Student(Student& r)
	{
		Name = new char[strlen(r.Name) + 1];
		strcpy(Name, r.Name);
		No = r.No;
		++countS;
		cout << "copy constructing:" << r.Name << endl;
	}

	Student::~Student()
	{
		cout << "destructing:" << Name << endl;
		delete[] Name;
		--countS;
	}

	int Student::countS = 0;

	void P5_9()
	{
		cout << Student::GetCount() << endl;
		Student s1("Antony");
		cout << s1.GetCount() << endl;
		Student s2(s1);
		cout << s1.GetCount() << endl;
		Student S3[2];
		cout << Student::GetCount() << endl;
		Student* s4 = new Student[3];
		cout << Student::GetCount() << endl;
		delete[] s4;
		cout << Student::GetCount() << endl;
	}
}

//P5_10 
namespace P5_10  //友元函数
{
	class Clock
	{
	private:
		int H, M, S;
	public:
		void ShowTime()
		{
			cout << H << ":" << M << ":" << S << endl;
		}
		void SetTime(int h = 0, int m = 0, int s = 0)
		{
			H = h, M = m, S = s;
		}
		Clock(int h = 0, int m = 0, int s = 0)
		{
			H = h, M = m, S = s;
		}
		friend Clock TripTime(Clock& StartTime, Clock& EndTime);
	};

	Clock TripTime(Clock& StartTime, Clock& EndTime)
	{
		int tH, tM, tS;
		int carry = 0;
		Clock tTime;
		(tS = EndTime.S - StartTime.S) > 0 ? carry = 0 : (tS += 60, carry = 1);
		(tM = EndTime.M - StartTime.M - carry) > 0 ? carry = 0 : (tM += 60, carry = 1);
		(tH = EndTime.H - StartTime.H - carry) > 0 ? carry = 0 : tH += 24;
		tTime.SetTime(tH, tM, tS);
		return tTime;
	}

	void P5_10()
	{
		Clock C1(8, 10, 10), C2(6, 1, 2);
		Clock C3;
		C3 = TripTime(C1, C2);
		C3.ShowTime();
	}
}

//P5_11
namespace P5_11  //友元类
{
	class Clock
	{
	private:
		int H, M, S;
	public:
		void ShowTime()
		{
			cout << H << ":" << M << ":" << S << endl;
		}
		void SetTime(int h = 0, int m = 0, int s = 0)
		{
			H = h, M = m, S = s;
		}
		Clock(int h = 0, int m = 0, int s = 0)
		{
			H = h, M = m, S = s;
		}
		friend class TrainTrip;
	};

	class TrainTrip
	{
	private:
		const char* TrainNo;
		Clock StartTime;
		Clock EndTime;
	public:
		TrainTrip(const char* TrainNo, Clock S, Clock E)
		{
			this->TrainNo = TrainNo;
			StartTime = S;
			EndTime = E;
		}
		Clock TripTime()
		{
			int tH, tM, tS;
			int carry = 0;
			Clock tTime;
			(tS = EndTime.S - StartTime.S) > 0 ? carry = 0 : (tS += 60, carry = 1);
			(tM = EndTime.M - StartTime.M - carry) > 0 ? carry = 0 : (tM += 60, carry = 1);
			(tH = EndTime.H - StartTime.H - carry) > 0 ? carry = 0 : tH += 24;
			tTime.SetTime(tH, tM, tS);
			return tTime;
		}
	};

	void P5_11()
	{
		Clock C1(8, 10, 10), C2(6, 1, 2);
		Clock C3;
		TrainTrip T1("K16", C1, C2);
		C3 = T1.TripTime();
		C3.ShowTime();
	}
}

//P5_12
namespace P5_12
{
	class A
	{
	private:
		const int& r;
		const int a;
		static const int b;
	public:
		A(int i) :a(i), r(a)
		{
			cout << "constructor!" << endl;
		}
		void display()
		{
			cout << a << "," << b << "," << r << endl;
		}
	};

	const int A::b = 3;

	void P5_12()
	{
		A a1(1);
		a1.display();
		A a2(2);
		a2.display();
	}
}
