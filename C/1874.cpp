#include <iostream>
#include <stack>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	stack<int> origin, space;
	stack<bool> record;//T=+(push) F=-(pop)
	int N;
	cin >> N;
	int term;
	for (int i = 0;i < N;i++) {
		cin >> term;
		origin.push(term);
	}

	bool O, S;
	for (int i = N;i >= 1;i--) {
		O = origin.empty();
		S = space.empty();
		if (!S) {
			if (space.top() == i) {
				space.pop();
				record.push(true);
			}
			else {
				if (!O) {
					space.push(origin.top());
					origin.pop();
					record.push(false);
					i++;
				}
				else
					break;
			}
		}
		else {
			space.push(origin.top());
			origin.pop();
			record.push(false);
			i++;
		}
	}

	if (space.empty())
		for (;!record.empty();record.pop())
			cout << (record.top() ? "+\n" : "-\n");
	else
		cout << "NO";
}