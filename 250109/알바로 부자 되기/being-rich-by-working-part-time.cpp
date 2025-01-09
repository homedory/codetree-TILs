#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int s[1005], e[1005], p[1005];
int dp[1005];
vector<pair<int,int>> sorted;

int main() {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> s[i] >> e[i] >> p[i];
        sorted.push_back({e[i], i});
    }

    sort(sorted.begin(), sorted.end());

    int max_j = 0;
    int j = 0;
    
    for (int i = 1; i <= N; i++) {
        while (sorted[j].first < s[i]) {
            if (dp[max_j] < dp[sorted[j].second])
                max_j = sorted[j].second;
            j++;
        }

        dp[i] = max(dp[max_j] + p[i], dp[i]);
    }

    int ans = 0;
    for (int i = 0; i <= N; i++) {
        ans = max(ans, dp[i]);
    }

    cout << ans;

    return 0;
}
