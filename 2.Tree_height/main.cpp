#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v1(n);
    for (auto& i : v1)
        cin >> i;
    map<int, vector<int>> tree;
    map<int, int> countTree;
    int depth{ 1 };
    int root{};
    for (size_t i = 0; i < n; ++i) {
        if (v1[i] != -1) {
            tree[v1[i]].push_back(i);
        }
        else {
            root = i;
        }
    }
    queue<int> q1;
    queue<int> q2;
    for (size_t i = 0; i < tree[root].size(); ++i) {
        q1.push(tree[root][i]);
    }
    while (true) {
        if (q1.size() == 0) {
            break;
        }
        else {
            depth++;
            while (q1.size() != 0) {
                vector<int> temp;
                temp = tree[q1.front()];
                for (auto i : temp) {
                    q2.push(i);
                }
                q1.pop();
            }
            if (q2.size() == 0)
                break;
            else {
                depth++;
                while (q2.size() != 0) {
                    vector<int> temp2;
                    temp2 = tree[q2.front()];
                    for (auto i : temp2) {
                        q1.push(i);
                    }
                    q2.pop();
                }
            }
        }
    }
    cout << depth << "\n";
    return 0;
}