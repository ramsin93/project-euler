/*

You are given the following information, but you may prefer to do some research for yourself.

    1 Jan 1900 was a Monday.
    Thirty days has September,
    April, June and November.
    All the rest have thirty-one,
    Saving February alone,
    Which has twenty-eight, rain or shine.
    And on leap years, twenty-nine.
    A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

*/

#include <iostream>
using namespace std;

bool is_leap(unsigned int);
unsigned int sd(short, short, unsigned int);
int main() {
	cout << sd(31, 12, 2000)-sd(31, 12, 1900) << endl;
	return 0;
}

bool is_leap(unsigned int y) {
	if(y%400 == 0) return true;
	else if(y%100==0) return false;
	else if(y%4==0) return true;
	else return false;
}

unsigned int sd(short d, short m, unsigned int y) {
	short _d=1, _m=1;
	unsigned int _y=1900, _n=1, _s=0;
	
	while(true) {
		if(_n%7+1==1 && _d==1) ++_s;
		if(_d==30 && (_m==4 || _m==6 || _m==9 || _m==11)) {
			++_m;
			_d = 1;
			++_n;
			continue;
		} else if(_m==2) {
			if(!is_leap(_y) && _d==28) {
				++_m;
				_d = 1;
				++_n;
				continue;
			}
			else if(is_leap(_y) && _d==29) {
				++_m;
				_d = 1;
				++_n;
				continue;
			}
		} else if(_d==31) {
			if(_m!=12) {
				++_m;
			} else {
				_m=1;
				++_y;
				if(_y>y) break;
			}
			
			_d = 1;
			++_n;
			continue;
		}
		
		if(_d==d && _m==m && _y==y) break; 
		++_d;
		++_n;
	}
	
	return _s;
}
