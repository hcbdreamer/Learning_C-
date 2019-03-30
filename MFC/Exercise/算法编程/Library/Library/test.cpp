#include<iostream>
#include<string>
#include<stdlib.h>
#include <iomanip>
using namespace std;
struct Book
{
	string book_name;
	string book_category;
	float book_num;
	string book_publish;
	float book_price;
};
void printBook(Book &b);
void printBookList(Book bookList[], int n);
void getBooksHigerThanX(Book bookList[], int n, float X);
void getBooksInCategory(Book bookList[], int n, string X);
void getBooksBeforeX(Book bookList[], int n, string X);
void getBooksByName(Book bookList[], int n, string X);
void printBook(Book &b)
{
	cout << setw(22) << b.book_name;
	cout << setw(22) << b.book_category;
	cout << setw(22) << b.book_num;
	cout << setw(22) << b.book_publish;
	cout << setw(22) << b.book_price << endl;
}
//implement function printBookList
void printBookList(Book bookList[], int n){
	//implement function getBooksHigerThanX
	for (int i = 0; i < n; i++)
	{
		printBook(bookList[i]);

	}
}
	void getBooksHigerThanX(Book bookList[], int n, float X){
		for (int i = 0; i < n; i++)
		{
			if (bookList[i].book_price > X)
			{
				printBook(bookList[i]);
			}
		}
	}
	//implement function getBooksInCategory
	void getBooksInCategory(Book bookList[], int n, string X){
		for (int i = 0; i < n; i++)
		{
			if (X == bookList[i].book_category)
			{
				printBook(bookList[i]);
			}
		}
	}
	//implement function getBooksBeforeX
	void getBooksBeforeX(Book bookList[], int n, float X){
		for (int i = 0; i < n; i++)
		{
			string a;
			float year=0;
			int index=1;
			int len = bookList[i].book_publish.size();
			for (int j = 0; j < len; j++)
			{
				
				if(bookList[i].book_publish[j] == '-')
				{
					index++;
				}
				if (index == 1)
				{
					a += bookList[i].book_publish[j];
				}
				
			}
			year = stof(a);

			if (year < X)
			{
				printBook(bookList[i]);
			}
			
		}
	}
	//implement function getBooksByName
	void getBooksByName(Book bookList[], int n, string X){
		for (int i = 0; i < n; i++)
		{
			int found = bookList[i].book_name.find(X);
			if (found != std::string::npos)
			{
				printBook(bookList[i]);
			}
		}
	}
	int main()
	{
		Book s[10];
		//cout << "name\tcategory\tnum\tpublish\tprice" << endl;
		int i = 0;
		/*TODO
		implement the input for struct array s
		
		*/
		s[0].book_category = "science";
		s[0].book_name = "math";
		s[0].book_num = 23;
		s[0].book_price = 69;
		s[0].book_publish = "2001-1-7";
        s[1].book_category = "novel";
		s[1].book_name = "Pacing-back-and-forth";
		s[1].book_num = 9;
		s[1].book_price = 29;
		s[1].book_publish = "1990-2-7";
		s[2].book_category = "science";
		s[2].book_name = "physics";
		s[2].book_num = 63;
		s[2].book_price = 89;
		s[2].book_publish = "2002-1-7";
		s[3].book_category = "science";
		s[3].book_name = "chemistry";
		s[3].book_num = 43;
		s[3].book_price = 69;
		s[3].book_publish = "2003-1-7";
		s[4].book_category = "history";
		s[4].book_name = "The-revolution-of-1911";
		s[4].book_num = 23;
		s[4].book_price = 129;
		s[4].book_publish = "2004-1-7";
		s[5].book_category = "novel";
		s[5].book_name = "gone-with-wind";
		s[5].book_num = 45;
		s[5].book_price = 82;
		s[5].book_publish = "2005-1-7";
		s[6].book_category = "novel";
		s[6].book_name = "god-father";
		s[6].book_num = 67;
		s[6].book_price = 69;
		s[6].book_publish = " 2006-1-7";
		s[7].book_category = "sport";
		s[7].book_name = "gymnastics";
		s[7].book_num = 23;
		s[7].book_price = 12;
		s[7].book_publish = " 2007-1-7";
		s[8].book_category = "Science";
		s[8].book_name = "skiing ";
		s[8].book_num = 34;
		s[8].book_price = 65;
		s[8].book_publish = " 2017-1-7";
		s[9].book_category = "Science";
		s[9].book_name = "skating";
		s[9].book_num = 19;
		s[9].book_price = 73;
		s[9].book_publish = "2018-1-7";

		cout << "=============show data=======" << endl;
		int flag = 1;
		while (flag)
		{
			cout << "=============1.输出所有图书============================" << endl;
			cout << "=============2.查询价格高于X的图书=====================" << endl;
			cout << "=============3.查询某X类的图书=========================" << endl;
			cout << "=============4.查询出版年限在X年之前图书===============" << endl;
			cout << "=============5.查询图书名字包含关键字X的图书信息=======" << endl;
			cout << "=============6.输入0退出系统=======" << endl;
			cout << "code=";
			cin >> flag;
			switch (flag){
				//TODO implement the main procedure switch to perfect book system

			case 1:
				// note:you may do something before call function printBookList
				printBookList(s, 10);
				break;
			case 2:
				// note:you may do something before call function getBooksHigerThanX
			{
				float X = 30;
				getBooksHigerThanX(s, 10, X);
				break;
			}
			case 3:
				// note:you may do something before call function getBooksInCategory
			{
				string X1 = "science";
				getBooksInCategory(s, 10, X1);
				break;
			}
			case 4:
				// note:you may do something before call function getBooksBeforeX

			{
				float year1 = 2009;
				getBooksBeforeX(s, 10, year1);
				break;
			}
			case 5:
				// note:you may do something before call function getBooksByName
			{
				string X2="with";
				getBooksByName(s, 10, X2);
				break;
			}
			default:
				break;

			}

		}
		return 0;
	}
