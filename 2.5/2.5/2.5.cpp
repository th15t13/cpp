#include <iostream>
using namespace std;

class A{
public:
	//ԭ�򣺶�дȨ�޹�����
	//int setI(A* const this, int i)
	int setI(int i){
		_i = i;
		//��const��Ա�����У����Ե���const��Ա����
		getI();	//const * = *
	}
	//const����thisָ�룬thisָ��ָ��Ķ������ݲ��ܱ�
	//����д����constֻ�����γ�Ա����
	//int getI(const A* const this)
	int getI() const{//const this: const A* const
		//_i = 100;
		//this->_i = 100;
		//const��Ա�����У����ܵ��÷�const��Ա����
		//setI(10);	//* = const *
		return _i;
	}
	// this: A* const
	A* operator&(){
		return this;
	}
	// this: const A* const ��������
	const A* operator&() const{
		return this;
	}
private:
	int _i;
};

void test(){
	A obja;
	A* pa = &obja;

	const A objb;
	const A* pb = &objb;
}

//void test(){
//	int a = 10;
//	//ָ������ݶ����Ա�
//	int* pa = &a;
//	//ָ���ܱ䣬���ݿ��Ա�
//	int* const cpa = &a;
//	//ָ������ݶ����ܱ�
//	const int* const ccpa = &a;
//}

//void test(){
//	A a;
//	//��const���� ���� ����const��Ա����
//	a.setI(10);
//	a.getI();
//
//	const A b;
//	//const���� ���� ���÷�const��Ա����
//	//b.setI(10);
//	b.getI();
//}
//��ͨ����������const����
//void fun(int a)const{
//	a = 100;
//}