#include <iostream>
#include <string>
using namespace std;

string integral(string &formula) {
	int K = 1, N = formula.size();
	for (int i = formula.size() - 1;i >= 0;i--) {
		if (formula[i] != 'x') {
			K = stoi(formula.substr(0, i + 1));
			N = formula.size() - 1 - i;
			break;
		}
	}
	N++;
	K /= N;

	string f = to_string(K);
	if (f == "1")
		f = "";
	for (int i = 0;i < N;i++)
		f.push_back('x');
	return f;
}
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string formula;
	cin >> formula;
	bool front_negative = false, back_negative = false;
	if (formula[0] == '-') {
		front_negative = true;
		formula.erase(0, 1);
	}

	if (formula == "0") {//ex
		cout << "W";
		return 0;
	}

	string front_formula, back_formula;
	for (int i = 0;i < formula.size();i++) {
		if (formula[i] == '+' || formula[i] == '-') {
			front_formula = formula.substr(0, i);
			back_formula = formula.substr(i + 1);
			if (back_formula == "0") {
				back_formula.clear();
				formula = front_formula;
			}
			if (formula[i] == '-')
				back_negative = true;
			break;
		}
	}
	if (back_formula.size() != 0)//2항
		cout << (front_negative ? "-" : "") << integral(front_formula) << (back_negative ? "-" : "+") << integral(back_formula) << "+W";
	else//단항
		cout << (front_negative ? "-" : "") << integral(formula) << "+W";
}