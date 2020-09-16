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
	string poly = "x+x+x+x+x+x+x+x+x+x";
	map<int, int, greater<int>> power_coef;
	int d_power, d_coef;
	string str_coef, str_power;
	regex r("([\+-]?)([[:d:]]*)\\*?(x?)\\^?([[:d:]]*)");
	sregex_iterator idx(poly.cbegin(),poly.cend(),r);
	sregex_iterator end;
	for(; idx!=end; idx++)    {
		int power = 1;
		int coef = 0;
		bool sign = 1;
		if (idx->str(4) != "")
			power = stoi(idx->str(4));
		if (idx->str(3) != "x")
			power = 0;
		if (idx->str(1) == "-")
			sign = 0;
		if (idx->str(2) != "")
			coef = sign ? (stoi(idx->str(2))) : (-stoi(idx->str(2)));
		else if (idx->str(3) == "x")
			coef = sign ? 1 : -1;
		else
			coef = 0;
		power_coef[power] += coef;
	}

	power_coef.erase(0);

	for (auto i : power_coef) {
		d_coef = i.first * i.second;
		d_power = i.first - 1;
		if (d_coef > 0)
			str_coef = "+" + to_string(d_coef);
		else
			str_coef = to_string(d_coef);
		if (d_power == 1)
			str_power = "*x";
		else if (d_power == 0)
			str_power = "";
		else
			str_power = "*x^" + to_string(d_power);
		cout << str_coef << str_power;
	}

	return 0;
}
