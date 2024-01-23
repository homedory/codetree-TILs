#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int N, K, B;
    unordered_set <int> missing_num;

    cin >> N >> K >> B;
    for (int i = 0; i < B; i++) {
        int a;
        cin >> a;
        missing_num.insert(a);
    }

    int sum = 0;
    for (int i = 1; i <= K; i++) {
        if (missing_num.find(i) != missing_num.end())
            sum++;
    }

    int ans = sum;

    for (int i = 1; i + K <= N; i++) {
        if (missing_num.find(i) != missing_num.end()) {
            sum--;
        }

        if (missing_num.find(i + K) != missing_num.end()) {
            sum++;
        }

        ans = min(ans, sum);
    }

    cout << ans;
    return 0;
}