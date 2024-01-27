#include <iostream>
#include <tuple>
#include <algorithm>
using namespace std;

#define MAX_N 100005


int main() {
    int N;
    pair<int,int> line[MAX_N];
    int L[MAX_N], R[MAX_N];

    cin >> N;

    for (int i = 0; i < N; i++) {
        int x1, x2;
        cin >> x1 >> x2;
        line[i].first = x1;
        line[i].second = x2;
    }

    sort(line, line + N);

    int max_num = -1000000;
    for (int i = 0; i < N; i++) {
        max_num = max(max_num, line[i].second);
        L[i] = max_num;
    }

    int min_num = 1000000;
    for (int i = N - 1; i >= 0; i--) {
        min_num = min(min_num, line[i].second);
        R[i] = min_num;
    }

    int ans = 0;

    if (N == 1) {
        cout << 1;
        return 0;
    }

    if (line[0].second < R[1])
        ans++;

    if (line[N - 1].second > L[N - 2])
        ans++;
    
    for (int i = 1; i < N - 1; i++) {
        if (L[i - 1] < line[i].second && line[i].second < R[i + 1])
            ans++;
    }
    
    cout << ans;

    
    return 0;
}