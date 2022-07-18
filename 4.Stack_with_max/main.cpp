#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin >> q;
	stack<int> st;
	vector<int> v1;
	for (size_t i = 0; i < q; ++i) {
		string s;
		cin >> s;
		if (s == "push") {
			long num;
			cin >> num;
			st.push(num);
			if (v1.size() == 0) {
				v1.push_back(num);
			}
			else {
				if (num > v1[v1.size() - 1]) {
					v1.push_back(num);
				}
				else {
					v1.push_back(num);
					swap(v1[v1.size() - 1], v1[v1.size() - 2]);
				}
			}
		}
		else if (s == "pop") {
			int a = st.top();
			if (a == v1[v1.size() - 1]) {
				v1.pop_back();
			}
			else {
				swap(v1[v1.size() - 1], v1[v1.size() - 2]);
				v1.pop_back();
			}
			st.pop();

		}
		else if (s == "max") {
			if (st.size() == 0) {
				cout << 0 << "\n";
			}
			else {
				cout << v1[v1.size() - 1] << "\n";
			}
		}
	}

	return 0;
}