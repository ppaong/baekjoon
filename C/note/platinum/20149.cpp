#include <iostream>
#include <algorithm>
using namespace std;

long long outerProduct(long long PX, long long PY, long long QX, long long QY) {
	return PX * QY - QX * PY;
}
long long dotProduct(long long PX, long long PY, long long QX, long long QY) {
	return PX * QX + PY * QY;
}
long long det(long long A, long long B, long long C, long long D) {
	return A * D - B * C;
}
int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	long long X[4], Y[4]; //point[0]!=point[1], point[2]!=point[3] 
	cin >> X[0] >> Y[0] >> X[1] >> Y[1] >> X[2] >> Y[2] >> X[3] >> Y[3];
	//A:P0->P1 / B:P2->P3
	long long AX = X[0] - X[1];
	long long AY = Y[0] - Y[1];
	long long BX = X[2] - X[3];
	long long BY = Y[2] - Y[3];

	long long D = det(AX, -BX, AY, -BY);

	if (D == 0) {//parallel
		D = det(X[2] - X[0], Y[2] - Y[0], X[3] - X[0], Y[3] - Y[0]);
		if (D == 0) {//collinear
			if (X[0] != X[1] && (max(X[0], X[1]) < min(X[2], X[3]) || max(X[2], X[3]) < min(X[0], X[1])))
				cout << "0\n";
			else if (Y[0] != Y[1] && (max(Y[0], Y[1]) < min(Y[2], Y[3]) || max(Y[2], Y[3]) < min(Y[0], Y[1])))
				cout << "0\n";
			else {
				cout << "1\n";
				int AminP = (X[0] != X[1] ? X[0] < X[1] ? 0 : 1 : Y[0] < Y[1] ? 0 : 1);
				int AmaxP = (X[0] != X[1] ? X[0] < X[1] ? 1 : 0 : Y[0] < Y[1] ? 1 : 0);
				int BminP = (X[2] != X[3] ? X[2] < X[3] ? 2 : 3 : Y[2] < Y[3] ? 2 : 3);
				int BmaxP = (X[2] != X[3] ? X[2] < X[3] ? 3 : 2 : Y[2] < Y[3] ? 3 : 2);
				if ((X[BmaxP] == X[AminP]) && (Y[BmaxP] == Y[AminP]))
					cout << X[AminP] << " " << Y[AminP];
				else if ((X[AmaxP] == X[BminP]) && (Y[AmaxP] == Y[BminP]))
					cout << X[AmaxP] << " " << Y[AmaxP];
			}
		}
		else
			cout << "0\n";
	}
	else {//if there is cross point, it is unique (using det)
		//CCW,CW check : P0->P1->P2, P0->P1->P3
		long long A_B0 = outerProduct(AX, AY, X[2] - X[1], Y[2] - Y[1]);
		long long A_B1 = outerProduct(AX, AY, X[3] - X[1], Y[3] - Y[1]);
		//CCW,CW check : P2->P3->P0, P2->P3->P1
		long long B_A0 = outerProduct(BX, BY, X[0] - X[3], Y[0] - Y[3]);
		long long B_A1 = outerProduct(BX, BY, X[1] - X[3], Y[1] - Y[3]);

		bool AtoB = ((A_B0 > 0 && A_B1 < 0) || (A_B0 < 0 && A_B1 > 0));
		bool BtoA = ((B_A0 > 0 && B_A1 < 0) || (B_A0 < 0 && B_A1 > 0));

		if (A_B0 == 0 || A_B1 == 0)
			AtoB = true;
		if (B_A0 == 0 || B_A1 == 0)
			BtoA = true;

		cout << (AtoB && BtoA) << "\n";
		if (AtoB && BtoA) {//cross point (x,y) = (AX,AY)*T0 + (X[0],Y[0]) = (BX,BY)*T1 + (X[2],Y[2]) 
			long long T0 = dotProduct(-BY, BX, X[2] - X[0], Y[2] - Y[0]);
			//long long T1 = dotProduct(-AY, AX, X[2] - X[0], Y[2] - Y[0]);//FAKER
			cout.setf(ios::fixed);
			cout.precision(10);
			cout << (AX * T0) / (long double)D + X[0] << " " << (AY * T0) / (long double)D + Y[0];
		}
	}
}