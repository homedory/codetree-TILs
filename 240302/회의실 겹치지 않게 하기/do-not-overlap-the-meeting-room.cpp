#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 100005

int main() {
    int n;
    pair<int,int> meetings[MAX_N];

    cin >> n;

    for (int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;
        meetings[i] = make_pair(e, s);
    }

    sort(meetings, meetings + n);

    int cnt = 0;
    int t = 0;
    for (int i = 0; i < n; i++) {
        if (meetings[i].second >= t) {
            cnt++;
            t = meetings[i].first;
        }
    }

    cout << n - cnt;

    return 0;
}