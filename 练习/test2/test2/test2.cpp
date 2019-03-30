#include <iostream>
using namespace std;

double Mary(int lines);
double Pam(int lines);
void estimate(int lines, double (*pt)(int));

void main()
{
	int code;
	cout << "How many lines do your code need" << endl;
	cin >> code;
	cout << "Here is Mary's estimate" << endl;
	estimate(code,Mary);
	cout << "Here is Pam's estimate" << endl;
	estimate(code, Pam);
}

double Mary(int lines)
{
	return 0.05 * lines;
}

double Pam(int lines)
{
	return 0.03*lines + 0.004*lines*lines;
}
void estimate(int lines, double (*pt)(int))
{
	cout << lines << " lines will take ";
	cout << (*pt)(lines) <<" hour(s) "<< endl;
}