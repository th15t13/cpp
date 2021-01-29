#include <iostream>
#include <time.h>
using namespace std;

//extern "C" int add(int a, int b);
//
//char add(char a, char b);

struct A {
	int a[10000];
};

A globalA;

A func1(){
	return globalA;
}

A& func2(){
	return globalA;
}

void test1(){
	int n;
	cout << "Ñ­»·´ÎÊý" << endl;
	cin >> n;

	size_t begin = clock();
	for (int i = 0; i < n; i++){
		func1();
	}
	size_t end = clock();
	cout << "time:" << end - begin << endl;

	begin = clock();
	for (int i = 0; i < n; i++){
		func2();
	}
	end = clock();
	cout << "time:" << end - begin << endl;
}

void test(){
	int a = 10;
	int& ra1 = a;
	int& ra2 = a;
	a = 5;
	ra1 = 10;
	ra2 = 20;
	a = 30;
}

int& add(int& a, int& b){
	return a += b;
}

int main(){

	//int a = add(10, 20);
	//char b = add('a', 'b');

	//test();

	//double d = 2.5;
	//int c = 0;
	//c = d;
	//const int& ra = d;
	//int a = 2;

	//int& ra1 = add(c, a);
	int a = 0;
	int* pa = &a;

	test1();

	system("pause");
	return 0;
}