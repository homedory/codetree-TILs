#include <iostream>
using namespace std;

#define MAX_N 20
#define MAX_LEN 1005

int isSelected[MAX_LEN];
pair<int,int> line[MAX_N];
int n;
int max_cnt = 0;

bool isEmpty(int start, int end) {
    for (int i = start; i <= end; i++) {
        if (isSelected[i])
            return false;
    }

    return true;
}

void checkLine(int start, int end) {
    for (int i = start; i <= end; i++) {
        isSelected[i] = true;
    }
}

void restoreLine(int start, int end) {
    for (int i = start; i <= end; i++) {
        isSelected[i] = false;
    }
}

void chooseLine(int curr_idx, int curr_cnt) {
    auto [start, end] = line[curr_idx];

    if (curr_idx == n) {
        max_cnt = max(max_cnt, curr_cnt);
        return;
    }

    if (isEmpty(start, end)) {
        checkLine(start, end);
        chooseLine(curr_idx + 1, curr_cnt + 1);
        restoreLine(start, end);
    }

    chooseLine(curr_idx + 1, curr_cnt);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x1, x2;
        cin >> x1 >> x2;
        line[i] = make_pair(x1, x2);
    }

    chooseLine(0, 0);

    cout << max_cnt;
    
    return 0;
}