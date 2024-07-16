#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K, L;
vector <int> c_vector;

bool isPossible(int h_index) {
    long long total_num = (long long) K * L;
    int idx = N - 1;

    int cnt = 0;
    while(idx >= 0) {
        if (h_index <= c_vector[idx]) {
            idx--;
            cnt++;
            continue;
        }

        if (h_index - c_vector[idx] <= K && h_index - c_vector[idx] <= total_num) {
            total_num -= h_index - c_vector[idx];
            idx--;
            cnt++;
        }
        else {
            break;
        }
    }

    return h_index <= cnt;
}

int main() {
    

    cin >> N >> K >> L;
    for (int i = 0; i < N; i++) {
        int c;
        cin >> c;
        c_vector.push_back(c);
    }

    sort(c_vector.begin(), c_vector.end());

    int left = 1;
    int right = N;
    int ans = 1;

    while(left <= right) {
        int mid = (left + right) / 2;
        if (isPossible(mid)) {
            left = mid + 1;
            ans = mid;
        }
        else {
            right = mid - 1;
        }
    }

    cout << ans;

    return 0;
}