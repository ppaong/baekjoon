#include <iostream>
#include <deque>
using namespace std;

struct balloon
{
	int num;
	int value;
};

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	deque<balloon> S;
	int N;
	cin >> N;
	int term;

	for (int i = 1;i <= N;i++) {
		cin >> term;
		S.push_back({ i,term });
	}

	bool dir = true;//rotation dir : f=L(to front),t=R(to back)
	int dist = 0;
	for (;;dist--) {
		if (dist <= 0) {
			cout << S.front().num << " ";
			dist = S.front().value;
			S.pop_front();
			if (S.empty())
				break;
			if (dist < 0) {
				dist = -dist;
				dir = false;
				S.push_front(S.back());
				S.pop_back();
			}
			else {
				dir = true;
			}
		}
		else if (dir) {
			S.push_back(S.front());
			S.pop_front();
		}
		else {
			S.push_front(S.back());
			S.pop_back();
		}
	}
}