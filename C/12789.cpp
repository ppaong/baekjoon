#include <iostream>
#include <stack>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	stack<int> line;
	stack<int> space;
	int N;
	cin >> N;
	int term;
	for (int i = 0;i < N;i++) {
		cin >> term;
		space.push(term);
	}
	for (int i = 0;i < N;i++) {
		line.push(space.top());
		space.pop();
	}

	bool L, S;
	for (int i = 1;i <= N;i++) {
		L = line.empty();
		S = space.empty();
		//cout << "line , space : " << (L ? 0 : line.top()) << " , " << (S ? 0 : space.top()) << "\n";
		if (L && !S) {
			if (space.top() == i)
				space.pop();
			else
				break;
		}
		else if (!L && !S) {
			if (line.top() == i)
				line.pop();
			else if (space.top() == i)
				space.pop();
			else {
				space.push(line.top());
				line.pop();
				i--;
			}
		}
		else {
			if (line.top() == i)
				line.pop();
			else {
				space.push(line.top());
				line.pop();
				i--;
			}
		}
	}
	cout << (space.empty() ? "Nice" : "Sad");
}