#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 100005

int main() {
    int n;
    int arr[MAX_N], L[MAX_N], R[MAX_N];
    long long total_sum = 0;
    vector <int> v;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        total_sum += arr[i];
    }

    long long s = 0;
    for (int i = 1; i <= n; i++) {
        s += arr[i];
        if (s == total_sum / 2)
            v.push_back(i);
    }

    s = 0;
    L[0] = 0;
    for (int i = 1; i <= n; i++) {
        s += arr[i];
        L[i] = L[i - 1];
        if (s == total_sum / 4)
            L[i]++;
    }

    s = 0;
    R[n + 1] = 0;
    for (int i = n; i >= 1; i--) {
        s += arr[i];
        R[i] = R[i + 1];
        if (s == total_sum / 4)
            R[i]++;
    }


    if (total_sum == 0) {
        cout << (n - 1) * (n - 2) * (n - 3) / 6;
        return 0;
    }

    long long ans = 0;
    for (int i = 0; i < v.size(); i++) {
        int idx = v[i];
        if (idx == n)
            continue;
        ans += L[idx] * R[idx + 1];
    }

    cout << ans;


    return 0;
}