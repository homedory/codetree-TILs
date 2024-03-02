#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M = 0;
    vector <pair<int,int>> v;

    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(y, x));
        M += x;
    }

    sort(v.begin(), v.end());

    int s = 0;
    int idx, r;
    for (int i = 0; i < N; i++) {
        int x = v[i].second;
        if (s < M / 2 && s + x >= M / 2) {
            idx = i;
            r = M / 2 - s;
            break;
        }
        s += x;
    }

    vector<pair<int,int>> A, B;
    for (int i = 0; i < idx; i++) {
        A.push_back(make_pair(v[i].second, v[i].first));
    }

    if (r > 0) {
        A.push_back(make_pair(r, v[idx].first));
    }

    if (v[idx].second - r > 0) {
        B.push_back(make_pair(v[idx].second - r, v[idx].first));
    }

    for (int i = idx + 1; i < N; i++) {
        B.push_back(make_pair(v[i].second, v[i].first));
    }

    int a_idx = 0, b_idx = B.size() - 1;
    int a_sum = A[a_idx].first, b_sum = B[b_idx].first;
    int ans = 0;

    while(a_idx < A.size() && b_idx >= 0) {
        ans = max(ans, A[a_idx].second + B[b_idx].second);

        if (a_sum == b_sum) {
            a_sum += A[a_idx].first;
            b_sum += B[b_idx].first;
            a_idx++;
            b_idx--;
        } 
        else if (a_sum > b_sum) {
            b_sum += B[b_idx].first;
            b_idx--;
        }
        else {
            a_sum += A[a_idx].first;
            a_idx++;
        }
    }

    cout << ans;

    return 0;
}