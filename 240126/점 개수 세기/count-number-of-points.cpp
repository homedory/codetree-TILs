#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector <int> v;
unordered_map <int,int> mapper;

int GetLowerBound(int x) {
    vector<int>::iterator it = lower_bound(v.begin(), v.end(), x);
    if (it == v.end()) {
        return mapper.size() + 1;
    }
    return mapper[*it];
}

int GetUpperBound(int x) {
    vector<int>::iterator it = upper_bound(v.begin(), v.end(), x);
    if (it == v.begin()) {
        return 0;
    }
    it--;
    return mapper[*it];
}

int main() {
    int n, q;

    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        mapper[v[i]] = i + 1;
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << GetUpperBound(b) - GetLowerBound(a) + 1 << "\n";
    }
    return 0;
}