#include <iostream>
using namespace std;

class A{
public:
	//原则：读写权限够不够
	//int setI(A* const this, int i)
	int setI(int i){
		_i = i;
		//非const成员函数中，可以调用const成员函数
		getI();	//const * = *
	}
	//const修饰this指针，this指针指向的对象内容不能变
	//如下写法的const只能修饰成员函数
	//int getI(const A* const this)
	int getI() const{//const this: const A* const
		//_i = 100;
		//this->_i = 100;
		//const成员函数中，不能调用非const成员函数
		//setI(10);	//* = const *
		return _i;
	}
	// this: A* const
	A* operator&(){
		return this;
	}
	// this: const A* const 构成重载
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
//	//指向和内容都可以变
//	int* pa = &a;
//	//指向不能变，内容可以变
//	int* const cpa = &a;
//	//指向和内容都不能变
//	const int* const ccpa = &a;
//}

//void test(){
//	A a;
//	//非const对象 可以 调用const成员函数
//	a.setI(10);
//	a.getI();
//
//	const A b;
//	//const对象 不能 调用非const成员函数
//	//b.setI(10);
//	b.getI();
//}
//普通函数不能用const修饰
//void fun(int a)const{
//	a = 100;
//}