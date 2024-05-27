#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector <int> v;
int maxResult = 0;
int inputNum[21];

void calculateMax() {
    int result = v[0];
    for (int i = 1; i < v.size(); i++) {
        result ^= v[i];
    }
    maxResult = max(maxResult, result);
}

void choose(int idx, int cnt) {
    if (cnt == m) {
        calculateMax();
        return;
    }
    if (idx == n)
        return;

    v.push_back(inputNum[idx]);
    choose(idx + 1, cnt + 1);
    v.pop_back();

    choose(idx + 1, cnt);

    return;
}

int main() {
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> inputNum[i];
    }

    choose(0, 0);

    cout << maxResult;

    return 0;
}