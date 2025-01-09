#include <iostream>

using namespace std;

int n;
int sequence[1000];
int increasing_seq[1000];
int decreasing_seq[1000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (sequence[i] <= sequence[j])
                continue;

            increasing_seq[i] = max(increasing_seq[i], increasing_seq[j] + 1);
        }
    }
    
    for (int i = n-1; i >= 0; i--) {
        for (int j = n-1; j >= 0; j--) {
            if (sequence[i] <= sequence[j])
                continue;
            
            decreasing_seq[i] = max(decreasing_seq[i], decreasing_seq[j] + 1);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(increasing_seq[i] + decreasing_seq[i] + 1, ans);
    }

    cout << ans;
    
    return 0;
}
