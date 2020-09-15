//============================================================================
// Name        : stepik.cpp
// Description : calculate polynomial derivative
//============================================================================

#include <iostream>
#include <string>
#include <regex>
#include <map>
#include <vector>
using namespace std;

int main() {
	string poly = "2*x^100+95*x^4-26*x^4";
	map<int, int> power_coef;

	regex r("([\+-]?)([[:d:]]*)\\*?(x?)\\^?([[:d:]]*)");
	sregex_iterator idx(poly.cbegin(),poly.cend(),r);
	sregex_iterator end;
	for(; idx!=end; idx++)    {
		int power=1;
		int coef=0;
		bool sign=1;
		if(idx->str(4) != "") power = stoi(idx->str(4));
		if(idx->str(3) != "x") power = 0;
		if(idx->str(1) == "-") sign = 0;
		if(idx->str(2) != "") coef = sign ? (stoi(idx->str(2))) : (-stoi(idx->str(2)));
		else if(idx->str(3) == "x") coef = sign ? 1 : -1;
		else coef = 0;
		power_coef[power] += coef;
	}

	for (auto i : power_coef) {
		cout << i.first << " " << i.second << endl;
	}

	return 0;
}
