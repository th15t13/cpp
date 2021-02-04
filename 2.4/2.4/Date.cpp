#include <iostream>
using namespace std;

class Date {
public:
	Date(int y = 1, int m = 1, int d = 1){
		if (y < 0 || m <= 0 || m > 12
			|| d <= 0 || d > getDay(y, m)){
			_y = 1;
			_m = 1;
			_d = 1;
			cout << "日期无效，设为默认值" << endl;
		}
		else{
			_y = y;
			_m = m;
			_d = d;
		}
	}
	int getDay(int y, int m){
		static int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = days[m];
		if (m == 2
			&& ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)){
			day += 1;
		}
		return day;
	}

	//日期运算
	//date += int
	Date& operator+=(int day){
		_d += day;
		while (_d > getDay(_y, _m)){
			_d -= getDay(_y, _m);
			++_m;
			if (_m == 13){
				_y++;
				_m = 1;
			}
		}
		return *this;
	}
	Date operator+(int day){
		Date copy(*this);
		copy += day;
		return copy;
	}
	Date& operator++(){
		return *this += 1;
	}
	Date& operator++(int){
		Date copy(*this);
		*this += 1;
		return copy;
	}
private:
	int _y;
	int _m;
	int _d;
};

void test(){
	Date d1(2020, 2, 4);
	Date d2(2020, 2, 4);
	Date d3(2020, 2, 4);
	Date d4(2020, 2, 4);

	d1 += 1;
	d2 += 30;
	d3 += 90;
	d4 += 360;

	d4 = d1 + 90;
	
	d4 = ++d3;
	d4 = d3++;
}

int main(){

	test();
	//system("pause");
	return 0;
}