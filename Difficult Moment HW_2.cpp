
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Timer.h"

using namespace std;

using namespace std;



void swap(int* a, int* b) {
	int c = *a;
	*a = *b;
	*b = c;
}

void lesson_1(){

	int a(2);	
	int b(6);

	swap(&a, &b);

	cout << a << ' ' << b << endl;
}


void SortPointers(vector<int*> &v)
{
	sort(v.begin(), v.end(), [](const auto &v1, const auto &v2)
		{
			return *v1 < *v2;
		});
}

void lesson_2()
{
	int length = 3;
	vector<int*> v;
	for (int i = 0; i < length; ++i)
	{
		int *a = new int;
		*a = rand() % 5;
		v.push_back(a);
	}
	for (int i = 0; i < length; ++i)
	{
		cout << *v[i] << ' ';
	}
	SortPointers(v);

	for (int i = 0; i < length; ++i)
	{
		cout << *v[i] << ' ';
	}
	cout << endl;
}



class Count
{
public:
	 const string vowels{ "AEIOUaeiou" };

	 
	 void method_1(const string_view& s)
	{
		Timer timer("Count vowels [method 1]");
		size_t count = count_if(s.begin(), s.end(), [&](const auto& p)
		{
			return vowels.find(p) != string::npos;
		});
		cout << count << endl;
		timer.print();
	}

	 void method_2(const string_view& s)
	{
		Timer timer("Count vowels [method 2]");
		size_t count = count_if(s.begin(), s.end(), [&](const auto& p)
			{
				for (size_t i = 0; i < vowels.size(); ++i)
				{
					if (vowels[i] == p)
						return true;
				}
				return false;
			});
		cout << count << endl;
		timer.print();
	}
	void method_3(const string_view& p)
	{
		size_t count = 0;
		Timer timer("Count vowels [method 3]");
		for (size_t i = 0; i < p.size(); ++i)
		{
			if (vowels.find(p[i]) != string::npos)
			{
				++count;
			}
		}
		cout << count << endl;
		timer.print();
	}
	 void method_4(const string_view& p)
	{
		size_t count = 0;
		Timer timer("Count vowels [method 3]");
		for (size_t i = 0; i < p.size(); ++i)
		{
			for (size_t j = 0; j < vowels.size(); ++j)
			{
				if (vowels[j] == p[i])
					++count;
			}
		}
		cout << count << endl;
		timer.print();
	}
};




int main()
{

	lesson_1();
	lesson_2();


	ifstream file("WarAndPeace.txt");

	file.seekg(0, ios::end);
	size_t size = file.tellg();
	file.seekg(0);
	string p(size, ' ');
	file.read(&p[0], size);

	Count j;
	j.method_1(p);
	j.method_2(p);
	j.method_3(p);
	j.method_4(p);
	return 0;
}
