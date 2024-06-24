#include <iostream>
#include <climits>
using namespace std;

int n;
bool selelcted_column[11];
int value[11][11];
int ans = 0;

void search(int row, int min_val) {
    if (row == n) {
        ans = max(ans, min_val);
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (selelcted_column[i])
            continue;
        
        selelcted_column[i] = true;
        search(row + 1, min(min_val, value[row + 1][i]));
        selelcted_column[i] = false;
    }
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> value[i][j];
        }
    }

    search(0, INT_MAX);

    cout << ans;


    return 0;
}