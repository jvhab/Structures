#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct heap {
	vector<int> v1;
	int counts{};
	vector<int> result;
	heap(vector<int> temp) : v1(temp) {}

	void shift_down(int i) {
		while (i * 2 + 1 < v1.size()) {
			int right = i * 2 + 2;
			int left = i * 2 + 1;
			int temp = left;
			if (right < v1.size() && v1[right] < v1[left]) {
				temp = right;
			}
			if (v1[i] <= v1[temp]) {
				break;
			}
			counts++;
			result.push_back(i);
			result.push_back(temp);
			swap(v1[temp], v1[i]);
			i = temp;
		}
	}
	void build_heap() {
		for (int i = (v1.size() - 1) / 2; i >= 0; --i) {
			shift_down(i);
		}
	}
	void print() {
		for (auto i : v1)
			cout << i << " ";
	}
	void print_result() {
		cout << counts << "\n";
		for (size_t i = 0; i < result.size(); i += 2) {
			cout << result[i] << " " << result[i + 1] << "\n";
		}
	}
};


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> v1(n);
	for (auto& i : v1) {
		cin >> i;
	}
	heap res{ v1 };
	res.build_heap();
	res.print_result();
	return 0;
}