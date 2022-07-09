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
    int buffer, n;
    cin >> buffer >> n;
    int buf = buffer;
    if (n == 0)
        return 0;
    queue<int> arrival;
    queue<int> duration;
    queue<int> st;
    vector<int> res;
    for (size_t i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        arrival.push(a);
        duration.push(b);
    }
    int arr, dur;
    int ad{};
    while (n--) {
        arr = arrival.front();
        dur = duration.front();
        while (st.size() != 0 && st.front() <= arr) {
            st.pop();
        }
        if (ad < arr) {
            res.push_back(arr);
            ad = arr + dur;
            st.push(ad);
        }

        else if (st.size() < buffer) {
            res.push_back(ad);
            ad = ad + dur;
            st.push(ad);
        }
        else {
            res.push_back(-1);
        }
        arrival.pop();
        duration.pop();
    }


    for (auto i : res)
        cout << i << "\n";
    return 0;
}