#pragma pack(1)
#include <iostream>
#include <assert.h>
using namespace std;

//union A {	//���ϱ�ʾ������������һ���ڴ�λ��, �ڲ�ͬ��ʱ�䱣�治ͬ���������ͺͲ�ͬ���ȵı���
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
//	//	cout << "С��" << endl;
//	//else
//	//	cout << "���" << endl;
//
//	A objA;
//	objA.a = 1;
//	if (objA.b)
//		cout << "С��" << endl;
//	else
//		cout << "���" << endl;
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
	// 1.�޲ι��캯������һ��Ĭ�Ϲ���
	//Date()
	//{}
	//��û����ʽ�����κ�һ�����캯����ϵͳ���Զ������޲ι���
	//���У��򲻱�д�޲ι�����޷��ֶ������޲ι���

	// 2.���ι��캯��
	/*Date(int year, int month, int day, int num)
	{
		_year = year;
		_month = month;
		_day = day;
	}*/
	//ȫȱʡҲ��һ��Ĭ�Ϲ��죬Ĭ�Ϲ���ֻ����һ����һ���һ��ȫȱʡ
	Date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int, int, int)" << endl;
	}
	//�������캯����������&��ֱ�Ӵ�ֵ�����޵ݹ鿽���β�
	//�������ʽ���忽�����죬���������Զ����ɿ�������
	Date(const Date& d){
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	void Display()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	//����ʽ�������������������Զ�����Ĭ�ϵ���������
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
	//�����������ͷ���Դ�ռ�
	//�������ٵ�ʱ�򣬱������Զ����������������Դ����
	~SeqList()
	{
		if (_pData)
		{
			free(_pData); // �ͷŶ��ϵĿռ�
			_pData = NULL; // ��ָ����Ϊ��
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
	//������ʽ���ù��캯��
	//d.Date(2021, 2, 3);

	//d1.SetDate(2018, 5, 1);
	//d1.Display();

	//Date d2;
	//d2.SetDate(2018, 7, 1);
	//d2.Display();

	system("pause");
	return 0;
}

