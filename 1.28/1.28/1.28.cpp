#include <iostream>
using namespace std;

void func(int a, int b = 20, int c = 30){
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
}

void func(char a, int b = 20, int c = 30){
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
}

int main(){
	int b, c, d, e;
	cin >> b >> c >> d >> e;
	cout << b << c << d << e << endl;
	func(10);
	func('a');

	system("pause");
	return 0;
}