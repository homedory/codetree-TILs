#include <iostream>
#include <unordered_set>
using namespace std;

#define MAX_N 200005

int main() {
    int N, K;
    int arr[MAX_N];
    unordered_set <int> s;

    int ans = -1;

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < K; i++) {
        if (s.find(arr[i]) != s.end()) {
            ans = max(ans, arr[i]);
        }
        else {
            s.insert(arr[i]);
        }
    }

    for (int i = K; i < N; i++) {
        if (s.find(arr[i]) != s.end()) {
            ans = max(ans, arr[i]);
        }
        s.erase(arr[i - K]);
        s.insert(arr[i]);
    }

    cout << ans;

    
    return 0;
}