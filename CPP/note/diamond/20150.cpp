//still solving
//dividing lines into groups seem to be essential
//tag : 스위핑 set map

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
//Px0,Py0 = 0
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

	int N;
	cin >> N;
	int** L = new int* [N];
	for (int i = 0;i < N;i++) {
		L[i] = new int[4];
		cin >> L[i][0] >> L[i][1] >> L[i][2] >> L[i][3];
	}
	for(int i = 0;i < N;i++) {
		for (int j = i + 1;j < N;j++) {
			if (isCrossing(L[i][2] - L[i][0], L[i][3] - L[i][1], L[j][0] - L[i][0], L[j][1] - L[i][1], L[j][2] - L[i][0], L[j][3] - L[i][1])) {
				cout << 1;
				return 0;
			}
		}
	}
	cout << 0;
	return 0;
}

/*
//first code
#include <iostream>
#include <algorithm>
using namespace std;

bool isCrossing(long long &Px0, long long &Py0, long long &Px1, long long &Py1, long long &Px2, long long &Py2, long long &Px3, long long &Py3) {
	// L1(x,y) :line P0(Px0,Py0) -> P1(Px1,Py1) <=> (P1-P0)*T1 + P0  in(0<=T1<=1)
	// L2(x,y) :line P2(Px2,Py2) -> P3(Px3,Py3) <=> (P3-P2)*T2 + P2  in(0<=T2<=1)
	// P1-P0 := A(Ax,Ay)
	// P3-P2 := B(Bx,Bx)
	//
	// L1=L2 <=> A*T1 + P0 = B*T2 + P2 <=> A*T1 - B*T2 = P2 - P0   (K := P2 - P0)
	//
	// [Ax -Bx] [T1] = [Kx]
	// [Ay -By] [T2]   [Ky]
	//
	// [T1] = [-By Bx] [Kx] / det  (D := det)
	// [T2]   [-Ay Ax] [Ky]

	long long Ax = Px1 - Px0;
	long long Ay = Py1 - Py0;
	long long Bx = Px3 - Px2;
	long long By = Py3 - Py2;
	long long D = Bx * Ay - Ax * By;// = det(Ax, -Bx, Ay, -By);

	if (D != 0) {
		long long Kx = Px2 - Px0;
		long long Ky = Py2 - Py0;

		bool rangeOfT1 = false;
		long long T1D = Bx * Ky - By * Kx;// = dotProduct(-By, Bx, Kx, Ky); // == T1*D   //FAKER
		if (0 <= T1D && 0 <= D) { // 0 <= T1*D <= D
			if (T1D <= D)
				rangeOfT1 = true;
		}
		else if ((D <= 0 && T1D <= 0)) { // D <= T1*D <= 0
			if (D <= T1D)
				rangeOfT1 = true;
		}

		if (!rangeOfT1)
			return false;

		bool rangeOfT2 = false;
		long long T2D = Ax * Ky - Ay * Kx;// = dotProduct(-Ay, Ax, Kx, Ky);
		if (0 <= T2D && 0 <= D) { // 0 <= T2*D <= D
			if (T2D <= D)
				rangeOfT2 =  true;
		}
		else if ((D <= 0 && T2D <= 0)) { // D <= T2*D <= 0
			if (D <= T2D)
				rangeOfT2 = true;
		}

		return rangeOfT2;
	}
	else {//parallel
		D = (Px2 - Px0) * (Py3 - Py0) - (Py2 - Py0) * (Px3 - Px0);// = det(Px2 - Px0, Py2 - Py0, Px3 - Px0, Py3 - Py0);//is P0->P2 and P0->P3 parallel?
		if (D == 0) {//collinear
			if (Px0 != Px1 && (max(Px0, Px1) < min(Px2, Px3) || max(Px2, Px3) < min(Px0, Px1))) {
				return false;
			}
			else if (Py0 != Py1 && (max(Py0, Py1) < min(Py2, Py3) || max(Py2, Py3) < min(Py0, Py1))) {
				return false;
			}
			else {
				return true;
			}
		}
	}
	return false;
}
int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	long long** L = new long long* [N];
	for (int i = 0;i < N;i++) {
		L[i] = new long long[4];
		cin >> L[i][0] >> L[i][1] >> L[i][2] >> L[i][3];
	}
	for(int i = 0;i < N;i++) {
		for (int j = i + 1;j < N;j++) {
			if (isCrossing(L[i][0], L[i][1], L[i][2], L[i][3], L[j][0], L[j][1], L[j][2], L[j][3])) {
				cout << 1;
				return 0;
			}
		}
	}
	cout << 0;
	return 0;
}
*/