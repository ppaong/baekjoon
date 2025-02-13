#include <iostream>
using namespace std;

//same solution with 17386

bool rangeT(const long long& TD, const long long& D) {
	if ((long long)0 < TD)
		return (TD < D);
	else if (TD < (long long)0)
		return (D < TD);
	return false;
}
void isCrossing(const int& Px1, const int& Py1, const int& Px2, const int& Py2, const int& Px3, const int& Py3) {
	long long D = (long long)(Px3 - Px2) * (long long)Py1 - (long long)(Py3 - Py2) * (long long)Px1;
	if (D != 0) {
		if (!rangeT(((long long)Px3 * (long long)Py2 - (long long)Py3 * (long long)Px2), D))
			cout << "0";
		else
			cout << rangeT(((long long)Px1 * (long long)Py2 - (long long)Py1 * (long long)Px2), D);
	}
	else
		cout << "0";
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int P[8];
	for (int i = 0;i < 8;i++)
		cin >> P[i];
	isCrossing(P[2]-P[0], P[3] - P[1], P[4] - P[0], P[5] - P[1], P[6] - P[0], P[7] - P[1]);
}
