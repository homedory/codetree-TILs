#include <iostream>
using namespace std;

#define MAX_N 100005

int main() {
    int N, x, y;
    
    pair<int,int> checkpoints[MAX_N];
    int L[MAX_N], R[MAX_N];

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> x >> y;
        checkpoints[i].first = x;
        checkpoints[i].second = y;
    }

    L[1] = 0;
    for (int i = 2; i <= N; i++) {
        L[i] = L[i-1] + abs(checkpoints[i].first - checkpoints[i-1].first) + abs(checkpoints[i].second - checkpoints[i-1].second);
    }

    R[N] = 0;
    for (int i = N-1; i >= 1; i--) {
        R[i] = R[i+1] + abs(checkpoints[i].first - checkpoints[i+1].first) + abs(checkpoints[i].second - checkpoints[i+1].second);
    }

    int ans = 2000000000;

    for (int i = 2; i < N; i++) {
        ans = min(ans, L[i-1] + R[i+1] + abs(checkpoints[i-1].first - checkpoints[i+1].first) + abs(checkpoints[i-1].second - checkpoints[i+1].second));
    }

    cout << ans;

    return 0;
}