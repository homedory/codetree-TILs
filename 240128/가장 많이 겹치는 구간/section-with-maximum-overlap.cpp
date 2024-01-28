#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    vector <pair<int,int>> v;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int x1, x2;
        cin >> x1 >> x2;
        v.push_back(make_pair(x1, 1));
        v.push_back(make_pair(x2, -1));
    }

    sort(v.begin(), v.end());

    int sum = 0, max_sum = 0, cnt = 0;

    for (int i = 0; i < v.size(); i++) {
        sum += v[i].second;
        if (sum > max_sum) {
            cnt = 1;
            max_sum = sum;
        }
        else if (sum == max_sum) {
            cnt++;
        }
    }

    cout << cnt;


    return 0;
}