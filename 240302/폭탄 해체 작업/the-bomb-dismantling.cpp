#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_N 10005

int N;
int parent[MAX_N];

void init() {
    for (int i = 0; i <= 10000; i++) {
        parent[i] = i;
    }
}

int find(int a) {
    if (parent[a] == a) {
        return a;
    }
    return parent[a] = find(parent[a]);
}

void join(int a, int b) {

    parent[b] = find(a);
}

int main() {
    cin >> N;
    vector<pair<int,int>> v;
    for (int i = 0; i < N; i++) {
        int score, time;
        cin >> score >> time;
        v.push_back(make_pair(score, time));
    }

    init();
    sort(v.begin(), v.end(), greater<pair<int,int>>());

    int ans = 0;
    for (int i = 0; i < N; i++) {
        int s = v[i].first;
        int t = v[i].second;

        int x = find(t);
        if (x > 0) {
            ans += s;
            join(x - 1, x);
        }
    }

    cout << ans;

    return 0;
}