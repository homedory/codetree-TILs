#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int n;
vector<pair<int,int>> line;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x1, x2;
        cin >> x1 >> x2;
        line.push_back({x2,x1});
    }

    sort(line.begin(), line.end());

    int count = 0;
    int end = 0;
    for (int i = 0; i < line.size(); i++) {
        int x1, x2;
        tie(x2, x1) = line[i];

        if (x1 > end) {
            count++;
            end = x2;
        }
    }

    cout << count;

    return 0;
}
