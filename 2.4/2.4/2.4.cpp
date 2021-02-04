//#include <iostream>
//using namespace std;
//
//class Date
//{
//public:
//	Date(int y = 1, int m = 1, int d = 1){
//		_y = y;
//		_m = m;
//		_d = d;
//		cout << "Date(int y = 1, int m = 1, int d = 1)" << endl;
//	}
//	Date(const Date& d){
//		_y = d._y;
//		_m = d._m;
//		_d = d._d;
//		cout << "Date(const Date& d)" << endl;
//	}
//	bool isEqual(const Date& d){
//		return _y == d._y
//			&& _m == d._m
//			&& _d == d._d;
//	}
//	bool operator==(const Date& d){
//		return _y == d._y
//			&& _m == d._m
//			&& _d == d._d;
//	}
//	//如果需要进行连续赋值，则返回值类型不能为空,需要为当前类类型
//	Date& operator=(const Date& d){
//		//判断对象是否是同一个对象:通过指针判断
//		if (this != &d){
//			_y = d._y;
//			_m = d._m;
//			_d = d._d;
//			cout << "Date& operator=(const Date& d)" << endl;
//		}
//		return *this;
//	}
//private:
//	int _y;
//	int _m;
//	int _d;
//};
//
////bool operator==(const Date& d1, const Date& d2){
////
////}
//
//void test(){
//	Date d1(2021, 2, 4);
//	Date d2(2020, 2, 4);
//	Date d3(2020, 1, 1);
//	d1 = d2 = d3;
//	//完整形式
//	//d1.operator=(d2.operator=(d3));
//	//if (d1.operator==(d2)){
//	if (d1 == d2 && d2 == d3){
//		cout << "equal" << endl;
//	}
//	else{
//		cout << "not equal" << endl;
//	}
//	//不是赋值。赋值是修改已经存在的对象内容。这里是拷贝构造
//	Date d4 = d1;
//}
//
//int main(){
//
//	test();
//
//	system("pause");
//	return 0;
//}