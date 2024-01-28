#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    vector <pair<int,int>> v;

    cin >> N >> K;

    int end = 0;
    for (int i = 0; i < N; i++) {
        int m;
        char c;
        cin >> m >> c;
        if (c == 'R') {
            v.push_back(make_pair(end, 1));
            v.push_back(make_pair(end + m, -1));
            end += m;
        }
        else if (c == 'L') {
            v.push_back(make_pair(end - m, 1));
            v.push_back(make_pair(end, -1));
            end -= m;
        }
    }

    sort(v.begin(), v.end());

    int sum = 0, ans = 0, start_point = 0;
    bool started = false;
    for (int i = 0; i < v.size(); i++) {
        sum += v[i].second;
        if (sum == K && !started) {
            start_point = v[i].first;
            started = true;
        }
        else if (sum < K && started) {
            ans += v[i].first - start_point;
            started = false;
        }
    }

    cout << ans;


    return 0;
}