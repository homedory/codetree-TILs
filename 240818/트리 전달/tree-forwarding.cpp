#include <iostream>
#include <vector>
using namespace std;

int parent[100005];
vector <int> child[100005];
int points[100005];

void traversal(int node) {
    points[node] += points[parent[node]];

    for (auto child_node : child[node]) {
        traversal(child_node);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        int p;
        cin >> p;
        if (p == -1)
            continue;

        parent[i] = p;
        child[p].push_back(i);
    }

    for (int i = 0; i < m; i++) {
        int num, point;
        cin >> num >> point;
        points[num] = point;
    }

    traversal(1);

    for (int i = 1; i <= n; i++) {
        cout << points[i] << " ";
    }


    return 0;
}