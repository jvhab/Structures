#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	stack<char> st;
	stack<int> pos;
	bool flag = false;
	for (size_t i = 0; i < s.size(); ++i) {
		if ((s[i] == ')' || s[i] == ']' || s[i] == '}') && st.empty()) {
			cout << i + 1 << "\n";
			flag = true;
			break;
		}
		else if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
			st.push(s[i]);
			pos.push(i + 1);
		}
		else if (s[i] == ')' && st.top() == '(') {
			st.pop();
			pos.pop();
		}
		else if (s[i] == ']' && st.top() == '[') {
			st.pop();
			pos.pop();
		}
		else if (s[i] == '}' && st.top() == '{') {
			st.pop();
			pos.pop();
		}
		else if (s[i] == ')' && st.top() != '(') {
			cout << i + 1 << "\n";
			flag = true;
			break;
		}
		else if (s[i] == ']' && st.top() != '[') {
			cout << i + 1 << "\n";
			flag = true;
			break;
		}
		else if (s[i] == '}' && st.top() != '{') {
			cout << i + 1 << "\n";
			flag = true;
			break;
		}


	}
	if (!flag && st.empty())
		cout << "Success" << "\n";
	else if (!flag && !st.empty())
		cout << pos.top() << "\n";
	return 0;
}