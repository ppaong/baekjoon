#include <iostream>
#include <algorithm>
using namespace std;

bool rangeT(const long long& TD,const long long& D) {
	if ((long long)0 < TD)
		return (TD <= D);
	else if (TD < (long long)0)
		return (D <= TD);
	return true;//TD==0
}
//Px0,Py0 =0
bool isCrossing(const int& Px1, const int& Py1, const int& Px2, const int& Py2, const int& Px3, const int& Py3) {
	long long D = (long long)(Px3 - Px2) * (long long)Py1 - (long long)(Py3 - Py2) * (long long)Px1;
	if (D != 0) {
		if (!rangeT(((long long)Px3 * (long long)Py2 - (long long)Py3 * (long long)Px2), D))
			return false;
		return rangeT(((long long)Px1 * (long long)Py2 - (long long)Py1 * (long long)Px2), D);
	}
	else {
		D = (long long)Px2 * (long long)Py3 - (long long)Py2 * (long long)Px3;
		if (D == 0) {
			if (0 != Px1 && (max(0, Px1) < min(Px2, Px3) || max(Px2, Px3) < min(0, Px1)))
				return false;
			else if (0 != Py1 && (max(0, Py1) < min(Py2, Py3) || max(Py2, Py3) < min(0, Py1)))
				return false;
			return true;
		}
		return false;
	}
}
int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int A, B, C, D, E, F, G, H;
	cin >> A >> B >> C >> D >> E >> F >> G >> H;
	cout << isCrossing((C - A), (D - B), (E - A), (F - B), (G - A), (H - B));
}



//first solution

/*
#include <iostream>
using namespace std;

long long outerProduct(long long AX, long long AY, long long BX, long long BY) {
	return AX * BY - BX * AY;
}
int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	long long X[4], Y[4];
	cin >> X[0] >> Y[0] >> X[1] >> Y[1] >> X[2] >> Y[2] >> X[3] >> Y[3];
	//A:P0->P1 / B:P2->P3
	long long AX = X[0] - X[1];
	long long AY = Y[0] - Y[1];
	long long BX = X[2] - X[3];
	long long BY = Y[2] - Y[3];

	//P0->P1->P2,P3
	long long A_B0 = outerProduct(AX, AY, X[2] - X[1], Y[2] - Y[1]);
	long long A_B1 = outerProduct(AX, AY, X[3] - X[1], Y[3] - Y[1]);
	//cout << "A_B0,A_B1 " << A_B0 << "," << A_B1 << "\n";
	
	//P2->P3->P0,P1
	long long B_A0 = outerProduct(BX, BY, X[0] - X[3], Y[0] - Y[3]);
	long long B_A1 = outerProduct(BX, BY, X[1] - X[3], Y[1] - Y[3]);
	//cout << "B_A0,B_A1 " << B_A0 << "," << B_A1 << "\n";

	bool AtoB = ((A_B0 > 0 && A_B1 < 0) || (A_B0 < 0 && A_B1 > 0));
	bool BtoA = ((B_A0 > 0 && B_A1 < 0) || (B_A0 < 0 && B_A1 > 0));

	if (A_B0 == 0 || A_B1 == 0)
		AtoB = true;
	if (B_A0 == 0 || B_A1 == 0)
		BtoA = true;

	if (A_B0 == 0 && A_B1 == 0 && B_A0 == 0 && B_A1 == 0) {
		long long P0 = (X[0] > X[1] ? X[1] : X[0]);
		long long P1 = (X[0] > X[1] ? X[0] : X[1]);
		bool Xaxis = (!(X[2] < P0 && X[3] < P0) && !(P1 < X[2] && P1 < X[3]));
		long long Q0 = (Y[0] > Y[1] ? Y[1] : Y[0]);
		long long Q1 = (Y[0] > Y[1] ? Y[0] : Y[1]);
		bool Yaxis = (!(Y[2] < Q0 && Y[3] < Q0) && !(Q1 < Y[2] && Q1 < Y[3]));
		cout << (Xaxis && Yaxis);
	}
	else
		cout << (AtoB && BtoA);
}
*/