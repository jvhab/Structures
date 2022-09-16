#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

class Phone_book {
private:
	unordered_map<string, string> book;
public:
	Phone_book() = default;
	void add_number(string number, string name) {
		book[number] = name;
	}
	void del_number(string number) {
		book.erase(number);
	}
	void find_number(string number) {
		if (book.find(number) == book.end()) {
			cout << "not found" << "\n";
		}
		else {
			cout << book[number] << "\n";
		}
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Phone_book book;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string command;
		cin >> command;
		if (command == "add") {
			string num;
			string name;
			cin >> num >> name;
			book.add_number(num, name);
		}
		else if (command == "find") {
			string num;
			cin >> num;
			book.find_number(num);
		}
		else if (command == "del") {
			string num;
			cin >> num;
			book.del_number(num);
		}
	}
	return 0;
}