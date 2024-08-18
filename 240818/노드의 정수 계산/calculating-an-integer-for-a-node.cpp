#include <iostream>
#include <vector>
using namespace std;

vector <int> child[100005];
int num[100005];

int traversal(int node) {
    int sum = num[node];
    for (int i = 0; i < child[node].size(); i++) {
        int next_node = child[node][i];
        sum += traversal(next_node);
    }

    if (sum > 0) 
        return sum;
    else
        return 0;
}

int main() {
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int t, a, p;
        cin >> t >> a >> p;

        num[i] = (t == 1) ? a : -a;
        child[p].push_back(i);
    }

    int ans = traversal(1);
    cout << ans;

    return 0;
}