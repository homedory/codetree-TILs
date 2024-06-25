#include <iostream>
using namespace std;

int num[105][105];
int m, n;

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> num[i][j];
        }
    }
    int ans = 0;
    
    for (int i = 0; i < n; i++) {
        int prev_num = num[i][0];
        int cnt = 1;
        
        if (cnt >= m) {
            ans++;
            continue;
        }
        for (int j = 1; j < n; j++) {
            if (prev_num == num[i][j])
                cnt++;
            else
                cnt = 1;
            
            prev_num = num[i][j];

            if (cnt >= m) {
                ans++;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        int prev_num = num[0][i];
        int cnt = 1;
        
        if (cnt >= m) {
            ans++;
            continue;
        }
        for (int j = 1; j < n; j++) {
            if (prev_num == num[j][i])
                cnt++;
            else
                cnt = 1;
            
            prev_num = num[j][i];

            if (cnt >= m) {
                ans++;
                break;
            }
        }
    }

    cout << ans;

    return 0;
}