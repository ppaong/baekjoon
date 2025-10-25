#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	priority_queue<int> inf; //max heap +
	priority_queue<int> sup; //min heap -
	inf.push(-10000);
	int count_inf = 0, count_sup = 0;
	int N;
	cin >> N;

	int given;
	for (int i = 0;i < N;i++) {
		cin >> given;
		if (given < inf.top()) {
			inf.push(given);
			count_inf++;
		}
		else {
			sup.push(-given);
			count_sup++;
		}
			
		if (count_inf < count_sup) {
			inf.push(-sup.top());
			count_inf++;
			sup.pop();
			count_sup--;
		}
		if (count_inf > count_sup+1) {
			sup.push(-inf.top());
			count_sup++;
			inf.pop();
			count_inf--;
		}

		cout << inf.top() << "\n";
	}
}