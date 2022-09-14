#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <numeric>

using namespace std;
vector<int> make_set(int);
int find_set(int, vector<int>&);
void union_sets(int, int, vector<int>&);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, e, d;
	cin >> n >> e >> d;
	bool flag = false;
	vector<int> my_set = make_set(n);
	for (size_t i = 0; i < e; ++i) {
		int a;
		int b;
		cin >> a >> b;
		union_sets(a, b, my_set);
	}
	for (size_t i = 0; i < d; ++i) {
		int a;
		int b;
		cin >> a >> b;
		if (find_set(a, my_set) == find_set(b, my_set)) {
			cout << 0 << "\n";
			flag = true;
			break;
		}
	}
	if (!flag) {
		cout << 1 << "\n";
	}
	
	return 0;
}

vector<int> make_set(int n) {
	vector<int> v1(n + 1);
	iota(v1.begin(), v1.end(), 0);
	return v1;
}
int find_set(int x, vector<int>& v1) {
	while (x != v1[x]) {
		x = v1[x];
	}
	return x;
}

void union_sets(int x, int y, vector<int>& v1) {
	/*int a = find_set(x, v1);
	int b = find_set(y, v1);*/
	if (x != y) {
		v1[y] = x;
	}

}