#include <iostream>
using namespace std;

#define MAX_N 10

int jump_len[MAX_N];
int n;

int calculate_step_cnt(int curr, int step_cnt) {
    if (curr == 0) {
        return step_cnt;
    }

    for (int i = 0; i < curr; i++) {
        if (jump_len[i] >= curr - i) {
            return calculate_step_cnt(i, step_cnt + 1);
        }
    }

    return -1;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> jump_len[i];
    }

    int ans = calculate_step_cnt(n - 1, 0);

    cout << ans;

    return 0;
}