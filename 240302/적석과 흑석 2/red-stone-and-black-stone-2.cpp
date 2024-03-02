#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int C, N;
    vector<int> red;
    vector<pair<int,int>> black;

    cin >> C >> N;

    for (int i = 0; i < C; i++) {
        int T;
        cin >> T;
        red.push_back(T);
    }

    for (int i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;
        black.push_back(make_pair(B, A));
    }

    sort(red.begin(), red.end());
    sort(black.begin(), black.end());

    int ans = 0;
    int j = 0;
    for (int i = 0; i < C; i++) {
        if (j == N) {
            break;
        }
        if (red[i] >= black[j].second && red[i] <= black[j].first) {
            ans++;
            j++;
            continue;
        }

        while(j < N - 1 && black[j].first < red[i]) {
            j++;
        }
    }

    cout << ans;

    return 0;
}