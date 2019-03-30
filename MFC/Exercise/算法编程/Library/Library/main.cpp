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
void printBookList(Book bookList[],int n);
void getBooksHigerThanX(Book bookList[],int n,float X);
void getBooksInCategory(Book bookList[],int n,string X);
void getBooksBeforeX(Book bookList[],int n, string X);
void getBooksByName(Book bookList[],int n,string X);
void printBook(Book &b)
{
    cout<<setw(22)<<b.book_name;
    cout<<setw(22)<<b.book_category;
    cout<<setw(22)<<b.book_num;
    cout<<setw(22)<<b.book_publish;
    cout<<setw(22)<<b.book_price<<endl;
}
//implement function printBookList
void printBookList(Book bookList[],int n){
//implement function getBooksHigerThanX
void getBooksHigerThanX(Book bookList[],int n,float X){
}
//implement function getBooksInCategory
void getBooksInCategory(Book bookList[],int n,string X){
}
//implement function getBooksBeforeX
void getBooksBeforeX(Book bookList[],int n,float X){
}
//implement function getBooksByName
void getBooksByName(Book bookList[],int n,string X){
}
int main()
{
    Book s[10];
    cout<<"name\tcategory\tnum\tpublish\tprice"<<endl;
    int i=0;
    /*TODO
    implement the input for struct array s

    */
    cout<<"=============show data======="<<endl;
    int flag=1;
    while(flag)
    {
        cout<<"=============1.输出所有图书============================"<<endl;
        cout<<"=============2.查询价格高于X的图书====================="<<endl;
        cout<<"=============3.查询某X类的图书========================="<<endl;
        cout<<"=============4.查询出版年限在X年之前图书==============="<<endl;
        cout<<"=============5.查询图书名字包含关键字X的图书信息======="<<endl;
        cout<<"=============6.输入0退出系统======="<<endl;
        cout<<"code=";
        cin>>flag;
        switch(flag){
            //TODO implement the main procedure switch to perfect book system

    case 1:
    // note:you may do something before call function printBookList
        break;
    case 2:
    // note:you may do something before call function getBooksHigerThanX
        break;
    case 3:
    // note:you may do something before call function getBooksInCategory
        break;
    case 4:
    // note:you may do something before call function getBooksBeforeX
        break;
    case 5:
    // note:you may do something before call function getBooksByName
        break;
    default:
        break;

        }

    }
    return 0;
}
