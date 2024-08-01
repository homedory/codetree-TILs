#include <iostream>
#include <vector>
using namespace std;

int n;
vector <pair<int,int>> edge[100005];
bool visited[100005];
int max_dist, max_dist_node;

void init() {
    max_dist = 0;
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }
}

void traversal(int curr_node, int removed_node, int curr_dist) {
    visited[curr_node] = true;

    if (max_dist < curr_dist) {
        max_dist = curr_dist;
        max_dist_node = curr_node;
    }

    for (int i = 0; i < edge[curr_node].size(); i++) {
        int next_node = edge[curr_node][i].first;
        int next_dist = edge[curr_node][i].second;

        if (visited[next_node] || next_node == removed_node)
            continue;
        
        traversal(next_node, removed_node, curr_dist + next_dist);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int node1, node2, dist;
        cin >> node1 >> node2 >> dist;
        edge[node1].push_back(make_pair(node2, dist));
        edge[node2].push_back(make_pair(node1, dist));
    }
    // find tree diameter
    init();
    traversal(1, 0, 0);
    int max_start_node = max_dist_node;

    init();
    traversal(max_start_node, 0, 0);
    int max_end_node = max_dist_node;

    // remove start_node and find tree diameter
    init();
    int temp_start_node = (max_start_node == 1) ? 2 : 1;
    traversal(temp_start_node, max_start_node, 0);
    int start_node1 = max_dist_node;

    init();
    traversal(start_node1, max_start_node, 0);
    int answer_candidate1 = max_dist;

    // remove end_node and find tree diameter
    init();
    temp_start_node = (max_end_node == 1) ? 2 : 1;
    traversal(temp_start_node, max_end_node, 0);
    int start_node2 = max_dist_node;

    init();
    traversal(start_node2, max_end_node, 0);
    int answer_candidate2 = max_dist;

    int answer = max(answer_candidate1, answer_candidate2);

    cout << answer;

    return 0;
}