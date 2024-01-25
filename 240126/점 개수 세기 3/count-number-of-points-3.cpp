#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    int n, q;
    vector <int> v;
    unordered_map <int,int> mapper;
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        mapper[v[i]] = i;
    }
    
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << mapper[b] - mapper[a] + 1 << "\n";
    }

    return 0;
}