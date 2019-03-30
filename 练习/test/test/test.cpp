#include<iostream>
#include<climits>
#include<string>
using namespace std;

unsigned long left(unsigned long num, unsigned ct);
char* left(const char* str, int n=1);


void main()
{
	/*int n_int = INT_MAX;
	short n_short = SHRT_MIN;
	char ch;
	cin >> ch;
	int i = ch;
	cout << "int is " << sizeof n_int << " bytes" << endl;
	cout << "unsigned int is " << sizeof(unsigned int) << " bytes" << endl;
	cout << "short is " << sizeof n_short << " bytes" << endl;
	cout << "char is " << sizeof CHAR_BIT << " bytes" << endl;
	cout << "Maximum values of int is " << n_int << endl;
	cout << "Minimum values of int is " << INT_MIN << endl;
	cout << "Minimum values of short is " << n_short << endl;
	cout << "Maximum values of char is " <<CHAR_MAX << endl;
	cout << "Minimum values of char is " << CHAR_MIN << endl;
	cout << "The ASCII of " << ch << " is" << i<<endl;
	ch = ch + 1;
	i = ch;
	cout << "The ASCII of " << ch << " is" << i;*/

	/*int yams[3];
	yams[0] = 8;
	yams[1] = 9;
	yams[2] = 6;
	int yamcosts[3] = { 20, 15, 16 };
	cout << "Total yam = ";
	cout << yams[0] + yams[1] + yams[2] << endl;
	cout << "The package with " << yams[1] << " yams cost ";
	cout << yamcosts[1] << " cents per yam.\n";
	cout << "\nSize of yams array = " << sizeof yams[0] << " bytes.\n";
	cout << "Size of yamcosts array = " << sizeof yamcosts << " bytes.\n";*/

	/*const int A = 20;
	char name[A];
	char dessert[A];
	cout << "Enter your name : \n";
	cin.getline(name, A);
	cout << "Enter your favorite dessert : " << endl;
	cin.getline(dessert, A);
	cout << "I have some delicious " << dessert << " for you , " << name << endl;*/

	/*double stage[3] = { 10, 20, 30 };
	int stacks[3] = { 1, 4, 3 };

	double *pt = stage;
	int *ps = &stacks[0];

	cout << *(pt+1) << endl;
	cout << pt << endl;
	cout << *ps+1 << endl;
	cout << ps << endl;
	cout << &stage << endl;*/

	/*const int Arsize = 16;
	long long factorials[Arsize];
	factorials[0] = factorials[1] = 1;
	for (int i = 2; i < Arsize; i++)
	{
		factorials[i] = i*factorials[i - 1];
	}
	for (int i = 0; i < Arsize; i++)
	{
		cout << i << " ! = " << factorials[i] << endl;
		}*/

	/*int a=1, b=10;
	cout << a++ << endl;
	cout << ++b << endl;*/

	/*const int Fave = 27;
	int n;
	cout << "Enter a number in the range 1-100 to find ";
	cout << "my favorite number: ";
	do
	{
		cin >> n;
		if (n < Fave)
			cout << "Too low -- guess again: ";
		else if (n>Fave)
			cout << "Too high -- guess again: ";
		else
			cout << Fave << " is right!\n";
	} while (n != Fave);*/


	char * trip = "Hawaii!!";
	unsigned long n = 12345678;
	int i;
	char* temp;

	for (i = 1; i < 10; i++)
	{
		cout << left(n, i) << endl;
		temp = left(trip, i);
		cout << temp << endl;
		delete [] temp;

	}

}

unsigned long left(unsigned long num, unsigned ct)
{
	unsigned digits = 1;
	unsigned long n = num;

	if (ct == 0 || num == 0)
	{
		return 0;
	}
	while (n /= 10)
		digits++;
	if (digits > ct)
	{
		ct = digits - ct;
		while (ct--)
			num /= 10;
		return num;
	}
	else
		return num;
}

char* left(const char* str, int n)
{
	if (n < 0)
		n = 0;
	char* p = new char[n + 1];
	int i;
	for (i = 0; i < n&&str[i]; i++)
		p[i] = str[i];
	while (i < n)
		p[i++] = '\0';
	return p;
}