#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_N 100005

long long prefix_sum[MAX_N];

int main() {
    int N, K;
    int cnt, pos;

    vector <pair<int,int> > v;

    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> cnt >> pos;
        v.push_back(make_pair(pos, cnt));
    }

    v.push_back(make_pair(0,0));

    sort(v.begin(), v.end());


    for (int i = 1; i <= N; i++) {
        prefix_sum[i] = prefix_sum[i-1] + v[i].second;
    }

    int j = 1;
    long long ans = 0;

    for (int i = 1; i <= N; i++) {
        while(j + 1 <= N && v[j + 1].first - v[i].first <= 2 * K) {
            j++;
        }

        ans = max(ans, prefix_sum[j] - prefix_sum[i - 1]);
    }

    cout << ans;


    return 0;
}