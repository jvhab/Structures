#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <set>
using namespace std;

void print_max(int& max1, int max2) {
	max1 = max(max1, max2);
	cout << max1 << "\n";
}

int find_set(int x, vector<pair<int, int>>& v1) {
	if (v1[x].first == x) {
		return x;
	}
	return v1[x].first = find_set(v1[x].first, v1);
}

void union_sets(int x, int y, int& max1, vector<pair<int, int>>& v1) {
	int a = find_set(x, v1); //3
	int b = find_set(y, v1); //5
	if (a == b) {
		int cur_max = v1[a].second;
		print_max(max1, cur_max);
	}
	else {
		v1[a].second += v1[b].second;
		v1[b].second = 0;
		v1[b].first = a;
		int cur_max = v1[a].second;
		print_max(max1, cur_max);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int current_max{};
	vector<pair<int, int>> table(n + 1);
	vector<pair<int, int>> task(m);
	for (size_t i = 1; i <= n; ++i) {
		int a;
		cin >> a;
		table[i] = { i , a };
		if (current_max < a) {
			current_max = a;
		}
	}
	for (auto& i : task) {
		cin >> i.first >> i.second;
		union_sets(i.first, i.second, current_max, table);
	}


	return 0;
}