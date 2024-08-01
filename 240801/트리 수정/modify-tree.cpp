#include <iostream>
#include <vector>
using namespace std;

int n;
vector <pair<int,int>> edge[2005];
bool visited[2005];
int max_dist, max_dist_node;
bool removed[2005][2005];
bool checked[2005][2005];

void init() {
    max_dist = -1;
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

        if (visited[next_node] || removed[curr_node][next_node] || removed[next_node][curr_node])
            continue;

        traversal(next_node, curr_dist + next_dist);
    }
}

int calcDiameter(int node) {
    init();
    traversal(node, 0);
    int start_node = max_dist_node;
    
    init();
    traversal(start_node, 0);
    
    return max_dist;
}


int main() {
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int node1, node2, dist;
        cin >> node1 >> node2 >> dist;
        edge[node1].push_back(make_pair(node2, dist));
        edge[node2].push_back(make_pair(node1, dist));
    }    

    int ans= 0;
    for (int node1 = 0; node1 < n; node1++) {
        for (int i = 0; i < edge[node1].size(); i++) {
            int node2 = edge[node1][i].first;
            int dist = edge[node1][i].second;
            if (checked[node2][node1])
                continue;
            
            checked[node1][node2] = true;

            removed[node1][node2] = true;
            removed[node2][node1] = true;
            
            int diameter1 = calcDiameter(node1);
            int diameter2 = calcDiameter(node2);

            ans = max(ans, diameter1 + diameter2 + dist);

            removed[node1][node2] = false;
            removed[node2][node1] = false;
        }
    }

    cout << ans;


    return 0;
}