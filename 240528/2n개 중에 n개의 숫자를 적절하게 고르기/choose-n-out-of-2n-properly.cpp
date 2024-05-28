#include <iostream>
using namespace std;

int N, sum = 0;
int num[25];
int minDiff;


void choose(int idx, int cnt, int cur_sum) {
    if(cnt == N) {
        minDiff = min(minDiff, abs((sum - cur_sum) - cur_sum));
        return;
    }

    if(idx == 2*N)
        return;

    choose(idx + 1, cnt + 1, cur_sum + num[idx]);

    choose(idx + 1, cnt, cur_sum);
}

int main() {

    cin >> N;
    for (int i = 0; i < 2*N; i++) {
        cin >> num[i];
        sum += num[i];
    }

    minDiff = sum;

    choose(0, 0, 0);

    cout << minDiff;

    return 0;
}