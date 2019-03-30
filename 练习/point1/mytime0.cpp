#include<iostream>
using namespace std;
struct Point
{
	int x;
	int y;
};
void main()
{
	Point pt;
	pt.x = 5;
	pt.y = 5;
	cout << pt.x << endl << pt.y << endl;
}