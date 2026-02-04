#include<stdio.h>
#include<iostream>
using namespace std;
template <typename T>
class limitvalue
{
public:
	T current_value;
	T min_value;
	T max_value;
	
	void check()
	{
		if (current_value < min_value)
		{
			current_value = min_value;
		}
		if (current_value > max_value)
		{
			current_value = max_value;
		}
	}

	limitvalue(T a,T b,T c )
	{
	current_value = a;
	min_value = b;
	max_value = c;
		check();
	}
	
	void operator= (T b)
	{
		current_value = b;
		check();
	}
	void operator+= (T b)
	{
		current_value += b;
		check();
	}
	
	void val()
	{
		cout << "当前值为：" << current_value << endl;
	}
};

int main()
{
	limitvalue<float> v(5,0,100);
	v = 55;
	v+=22;
	v.val();
	v += 200;
	v.val();
	return 0;
}