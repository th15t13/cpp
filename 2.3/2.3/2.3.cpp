#pragma pack(1)
#include <iostream>
#include <assert.h>
using namespace std;

//union A {	//联合表示几个变量公用一个内存位置, 在不同的时间保存不同的数据类型和不同长度的变量
//	int a;
//	char b;
//};

//struct A {
//	int a;
//	int b;
//	double d;
//	int e;
//};

//struct B{
//	char a;
//	double d;
//	A objA;
//};

//struct C{
//	char c;
//	int b;
//};

//void test(){
//	//cout << sizeof(A) << endl;
//	//cout << sizeof(B) << endl;
//	//A a;
//	//cout << (char*)&a.d - (char*)&a << endl;
//
//	//int a = 1;
//	//char* pa = (char*)&a;
//	//if (*pa)
//	//	cout << "小端" << endl;
//	//else
//	//	cout << "大端" << endl;
//
//	A objA;
//	objA.a = 1;
//	if (objA.b)
//		cout << "小端" << endl;
//	else
//		cout << "大端" << endl;
//}

//int main(){
//
//	test();
//	system("pause");
//	return 0;
//}

//class A{
//public:
//	int _a;
//	A(int a = 10){
//		_a = a;
//		cout << "A()" << endl;
//	}
//};

class Date
{
//public:
//	void SetDate(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Display()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;

public:
	// 1.无参构造函数，是一种默认构造
	//Date()
	//{}
	//若没有显式定义任何一个构造函数，系统会自动生成无参构造
	//若有，则不编写无参构造就无法手动调用无参构造

	// 2.带参构造函数
	/*Date(int year, int month, int day, int num)
	{
		_year = year;
		_month = month;
		_day = day;
	}*/
	//全缺省也是一种默认构造，默认构造只能有一个，一般给一个全缺省
	Date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int, int, int)" << endl;
	}
	//拷贝构造函数，必须用&，直接传值会无限递归拷贝形参
	//如果不显式定义拷贝构造，编译器会自动生成拷贝构造
	Date(const Date& d){
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	void Display()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	//不显式定义析构，编译器会自动生成默认的析构函数
	~Date()
	{}
private:
	int _year;
	int _month;
	int _day;

	//A _a;
};

void test(){
	Date d(2021, 2, 3);
	Date copy(d);
}

typedef int DataType;
class SeqList
{
public:
	SeqList(int capacity = 10)
	{
		_pData = (DataType*)malloc(capacity * sizeof(DataType));
		assert(_pData);

		_size = 0;
		_capacity = capacity;
	}
	//析构函数，释放资源空间
	//对象销毁的时候，编译器自动调用析构，完成资源清理
	~SeqList()
	{
		if (_pData)
		{
			free(_pData); // 释放堆上的空间
			_pData = NULL; // 将指针置为空
			_capacity = 0;
			_size = 0;
		}
	}

private:
	int* _pData;
	size_t _size;
	size_t _capacity;
};

int main()
{
	test();
	//Date d(2021, 2, 3);
	//不能显式调用构造函数
	//d.Date(2021, 2, 3);

	//d1.SetDate(2018, 5, 1);
	//d1.Display();

	//Date d2;
	//d2.SetDate(2018, 7, 1);
	//d2.Display();

	system("pause");
	return 0;
}

