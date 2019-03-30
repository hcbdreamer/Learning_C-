#include<iostream>
#include"mytime0.h"


int main()
{
	using std::cout;
	using std::endl;
	Time planning;
	Time coding(2, 40);
	Time fixing(5, 55);
	Time Total;

	cout << "The planning time is ";
	planning.show();
	cout << endl;

	cout << "The coding time is ";
	coding.show();
	cout << endl;

	cout << "The fixing time is ";
	fixing.show();
	cout << endl;

	cout << "The total time is ";
	Total = coding.Sum(fixing);
	cout << "coding.Sum(fixing) = ";
	Total.show();
	cout << endl;
	return 0;
}