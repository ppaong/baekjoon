#include <iostream>
using namespace std;

long long max_size(int* a, int start,int end) {
	if (start == end)
		return a[start];

	int mid = (start + end) >> 1;

	long long L = max_size(a, start, mid);
	long long R = max_size(a, mid+1, end);

	long long h = min(a[mid], a[mid + 1]);
	long long M = h << 1;

	int i = mid - 1, j = mid + 2;
	for (int w = j - i; i >= start || j <= end; w++) {
		if (i < start) {
			if (a[j] < h)
				h = a[j];
			j++;
		}
		else if (j > end) {
			if (a[i] < h)
				h = a[i];
			i--;
		}
		else {
			if (a[i] >= a[j]) {
				if (a[i] < h)
					h = a[i];
				i--;
			}
			else {
				if (a[j] < h)
					h = a[j];
				j++;
			}

		}
		long long box = h * w;

		if (M < box)
			M = box;
	}
	if (M < L)
		M = L;
	if (M < R)
		M = R;

	return M;
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	int a[100001];
	for (;;) {
		cin >> N;
		if (N == 0)
			break;

		for (int i = 0;i < N;i++)
			cin >> a[i];

		cout << max_size(a, 0, N - 1) << "\n";
	}
}



/*
//time out
#include <iostream>
using namespace std;

void update(const int &e, const int &w, long long& h, long long& M) {
	if (e < h)
		h = e;
	M = max(M, h * w);
}

long long max_size(int* a, int start,int end) {
	if (start == end)
		return a[start];

	int mid = (start + end) / 2;

	long long L = max_size(a, start, mid);
	long long R = max_size(a, mid+1, end);


	//cout << "start : " << start << ",end : " << end << ",mid : " << mid << "\n";
	//cout << "L : " << L << ",R : " << R << "\n";
	long long h = min(a[mid], a[mid + 1]);
	long long M = h * 2;
	int i = mid - 1, j = mid + 2;
	for (;;) {
		if (i < start && j > end)
			break;

		int w = j - i;
		//cout << "w:" << w << ",h:" << h << ",M:" << M << "\n";
		if (i < 0) {
			//cout << "update on j:" << j << "\n";
			update(a[j], w, h, M);
			j++;
		}
		else if (j > end) {
			//cout << "update on i:" << i << "\n";
			update(a[i], w, h, M);
			i--;
		}
		else {
			if (a[i] >= a[j]) {
				//cout << "update on i:" << i << "\n";
				update(a[i], w, h, M);
				i--;
			}
			else {
				//cout << "update on j:" << j << "\n";
				update(a[j], w, h, M);
				j++;
			}
		}
		//cout << "M=>" << M << "\n";
	}
	M = max(L, M);
	M = max(M, R);
	//cout << "return: " << M << "\n";
	return M;
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	int a[100000];
	for (;;) {
		cin >> N;
		if (N == 0)
			break;

		for (int i = 0;i < N;i++)
			cin >> a[i];

		cout << max_size(a, 0, N - 1) << "\n";
	}
}
*/