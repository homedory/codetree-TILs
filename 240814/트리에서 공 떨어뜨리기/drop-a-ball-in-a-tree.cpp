#include <iostream>
using namespace std;

int n, k;
pair<int,int> child[200005];

int traverse(int node, int order) {
    int child_cnt = 0;
    int next_node;

    if (child[node].first != -1) {
        child_cnt++;
        next_node = child[node].first;
    }
        
    if (child[node].second != -1) {
        child_cnt++;
        next_node = child[node].second;
    }

    switch (child_cnt) {
        case 2:
            if (order % 2 == 1) {
                return traverse(child[node].first, (order+1)/2);
            }
            else {
                return traverse(child[node].second, order/2);
            }
        case 1:
            return traverse(next_node, order);
        case 0:
            return node;
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int child_1, child_2;
        cin >> child_1 >> child_2;
        child[i] = make_pair(child_1, child_2);
    }
    cin >> k;

    int ans = traverse(1, k);

    cout << ans;


    return 0;
}