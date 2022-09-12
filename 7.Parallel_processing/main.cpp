#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void shift_down(vector<pair<int, long long>>& proc, long long time_task) {
	proc[0].second += time_task;
	long long temp = 0;
	while (temp * 2 + 1 < proc.size()) {
		long long left = 2 * temp + 1;
		long long right = 2 * temp + 2;
		long long i = left;
		if (right < proc.size() && proc[right].second < proc[left].second) {
			i = right;
		}
		else if (right < proc.size() && proc[right].second == proc[left].second && proc[right].first < proc[left].first) {
			i = right;
		}
		if (proc[i].second > proc[temp].second) {
			break;
		}
		else if (proc[i].second == proc[temp].second && proc[i].first > proc[temp].first) {
			break;
		}
		swap(proc[temp], proc[i]);
		temp = i;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<pair<int, long long>> proc;
	vector<long long> task(m);
	for (auto& i : task) {
		cin >> i;
	}
	for (int i = 0; i < n; ++i) {
		proc.push_back({ i, 0 });
	}
	for (size_t i = 0; i < m; ++i) {
		cout << proc[0].first << " " << proc[0].second << "\n";
		long long time_task = task[i];
		shift_down(proc, time_task);
	}
	return 0;
}