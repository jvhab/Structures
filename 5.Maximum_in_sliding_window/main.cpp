#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin >> n;
    queue<long long> v1;
    for (size_t i = 0; i < n; ++i) {
        long long a;
        cin >> a;
        v1.push(a);
    }
    long long m;
    cin >> m;
    //vector<int> result;
    stack<pair<long long, long long>> stackIn;
    stack<pair<long long, long long>> stackOut;

    //Fill StackIn
    long long maxIn{};
    while (stackIn.size() != m) {
        if (v1.front() > maxIn) {
            stackIn.push({ v1.front(), v1.front() });
            maxIn = v1.front();
            v1.pop();
        }
        else {
            stackIn.push({ v1.front(), maxIn });
            v1.pop();
        }
    }

    //Fill StackOut
    long long maxOut{};
    while (stackOut.size() != m) {
        if (stackIn.top().first > maxOut) {
            stackOut.push({ stackIn.top().first, stackIn.top().first });
            maxOut = stackIn.top().first;
            stackIn.pop();
        }
        else {
            stackOut.push({ stackIn.top().first, maxOut });
            stackIn.pop();
        }
    }

    // Final
    while (stackOut.size() + stackIn.size() == m) {
        if (stackIn.size() == 0 && stackOut.size() != 0) {
            cout << stackOut.top().second << " ";
            stackOut.pop();
        }
        else if (stackIn.top().second >= stackOut.top().second && stackOut.size() != 0) {
            cout << stackIn.top().second << " ";
            stackOut.pop();
        }
        else if (stackIn.top().second < stackOut.top().second && stackOut.size() != 0) {
            cout << stackOut.top().second << " ";
            stackOut.pop();
        }
        if (v1.size() != 0) {
            if (stackIn.size() == 0) {
                stackIn.push({ v1.front(), v1.front() });
                v1.pop();
            }
            else {
                if (stackIn.top().second < v1.front()) {
                    stackIn.push({ v1.front(), v1.front() });
                    v1.pop();
                }
                else {
                    stackIn.push({ v1.front(), stackIn.top().second });
                    v1.pop();
                }
            }
        }
        if (stackIn.size() == m) {
            while (stackOut.size() != m) {
                if (stackOut.size() == 0) {
                    stackOut.push({ stackIn.top().first, stackIn.top().first });
                    stackIn.pop();
                }
                else {
                    if (stackOut.top().second < stackIn.top().first) {
                        stackOut.push({ stackIn.top().first, stackIn.top().first });
                        stackIn.pop();
                    }
                    else {
                        stackOut.push({ stackIn.top().first, stackOut.top().second });
                        stackIn.pop();
                    }
                }
            }
        }
    }
    return 0;
}