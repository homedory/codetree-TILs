#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <climits>
using namespace std;

int n, d;
bool visited[50005];
int dist[50005];
vector <pair<int,int>> edge[50005];
    unordered_set <int> end_node;

int max_cnt;
int min_dist = INT_MAX;

void init() {
    for (int i = 1; i <= n; i++)
        visited[i] = false;
    max_cnt = 0;
}

void traversal(int node, int node_cnt) {
    visited[node] = true;
    dist[node] = node_cnt;

    if (node_cnt > max_cnt) {
        max_cnt = node_cnt;
    }

    for (int i = 0; i < edge[node].size(); i++) {
        int next_node = edge[node][i].first;

        if (visited[next_node])
            continue;
        
        traversal(next_node, node_cnt + 1);
    }
}

void traversal_with_dist(int node, int start, int dist) {
    visited[node] = true;

    if (end_node.find(node) != end_node.end() && node != start) {
        min_dist = min(min_dist, dist);
    }

    for (int i = 0; i < edge[node].size(); i++) {
        int next_node = edge[node][i].first;
        int next_dist = edge[node][i].second;

        if (visited[next_node])
            continue;
        
        traversal_with_dist(next_node, start, dist + next_dist);
    }
}

int main() {
    cin >> n >> d;
    for (int i = 0; i < n - 1; i++) {
        int node1, node2, dist;
        cin >> node1 >> node2 >> dist;
        edge[node1].push_back(make_pair(node2, dist));
        edge[node2].push_back(make_pair(node1, dist));
    }

    init();
    dist[1] = 0;
    traversal(1, 1);
    vector <int> start_node;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == max_cnt)
            start_node.push_back(i);
    }

    init();
    dist[start_node[0]] = 0;
    traversal(start_node[0], 1);
    for (int i = 1; i <= n; i++) {
        if (dist[i] == max_cnt) 
            end_node.insert(i);
    }

    for (int i = 0; i < start_node.size(); i++) {
        init();
        traversal_with_dist(start_node[i], start_node[i], 0);
    }

    int ans = (min_dist % d == 0) ? min_dist / d : min_dist / d + 1;

    cout << ans;

    return 0;
}