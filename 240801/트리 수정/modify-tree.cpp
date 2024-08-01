#include <iostream>
#include <vector>
using namespace std;

int n;
vector <pair<int,int>> edge[2005];
bool visited[2005];
int prev_node[2005];
bool path_included[2005];
int max_dist, max_dist_node;


void init() {
    max_dist = 0;
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
}

void traversal(int curr_node, int curr_dist) {
    visited[curr_node] = true;

    if (curr_dist > max_dist) {
        max_dist = curr_dist;
        max_dist_node = curr_node;
    }

    for (int i = 0; i < edge[curr_node].size(); i++) {
        int next_node = edge[curr_node][i].first;
        int next_dist = edge[curr_node][i].second;

        if (visited[next_node] || path_included[next_node])
            continue;

        prev_node[next_node] = curr_node;
        traversal(next_node, curr_dist + next_dist);
    }
}

void checkPathNode(int start_node) {
    int curr_node = start_node;
    path_included[start_node] = true;

    while(prev_node[curr_node] != -1) {
        curr_node = prev_node[curr_node];
        path_included[curr_node] = true;
    }
}

int find_max_dist_edge() {
    int max_value = 0;

    for (int node1 = 0; node1 < n; node1++) {
        for (int i = 0; i < edge[node1].size(); i++) {
            int node2 = edge[node1][i].first;

            if (path_included[node1] && path_included[node2])
                continue;
            
            max_value = max(max_value, edge[node1][i].second);
        }
    }

    return max_value;
}

int main() {
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int node1, node2, dist;
        cin >> node1 >> node2 >> dist;
        edge[node1].push_back(make_pair(node2, dist));
        edge[node2].push_back(make_pair(node1, dist));
    }    

    init();
    traversal(0, 0);
    int start_node = max_dist_node;

    init();
    traversal(start_node, 0);
    int end_node = max_dist_node;
    int diameter = max_dist;

    prev_node[start_node] = -1; 
    checkPathNode(end_node);

    int new_path_dist = 0;
    for (int node = 0; node < n; node++) {
        init();
        traversal(node, 0);
        new_path_dist = max(new_path_dist, max_dist);
    }

    int answer = diameter + new_path_dist;

    cout << answer;

    return 0;
}