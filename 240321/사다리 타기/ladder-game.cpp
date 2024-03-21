#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector <pair<int,int>> line;
vector <int> selected;
int min_cnt = 15;

bool possible() {
    int arr1[12], arr2[12];

    for (int i = 1; i <= n; i++) {
        arr1[i] = arr2[i] = i;
    }

    for (int i = 0; i < m; i++) {
        auto [order, start] = line[i];
        swap(arr1[start], arr1[start + 1]);
    }

    for (int i = 0; i < selected.size(); i++) {
        int start = selected[i];
        swap(arr2[start], arr2[start + 1]);
    }

    for (int i = 1; i <= n; i++) {
        if (arr1[i] != arr2[i])
            return false;
    }

    return true;
}

void findMinLine(int curr_cnt) {
    if (curr_cnt == m) {
        if (possible()) {
            min_cnt = min(min_cnt, (int) selected.size());
        }
        return;
    }

    selected.push_back(line[curr_cnt].second);
    findMinLine(curr_cnt + 1);
    selected.pop_back();
    findMinLine(curr_cnt + 1);
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        line.push_back(make_pair(b, a));
    }
    
    sort(line.begin(), line.end());

    findMinLine(0);

    cout << min_cnt;

    return 0;
}