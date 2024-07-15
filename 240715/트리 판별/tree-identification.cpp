#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int main() {
    int m;
    unordered_map <int,int> in_degree;
    vector <int> edges[10005];
    bool ans = true;
    
    cin >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);

        if (in_degree.find(b) != in_degree.end() && in_degree[b] > 0) {
            ans = false;
        }
        else
            in_degree[b] = 1;
        
        if (in_degree.find(a) == in_degree.end())
            in_degree[a] = 0;
    }

    if (in_degree.size() != m + 1)
        ans = false;
    
    if (ans == false) {
        cout << ans;
        return 0;
    }

    int root;
    for(unordered_map<int,int>::iterator it = in_degree.begin(); it != in_degree.end(); it++) {
        if(it->second == 0)
            root = it->first;
    }

    int connected_node_cnt = 0;
    queue <int> q;
    bool visited[10005];
    for (int i = 0; i < 10005; i++)
        visited[i] = false;

    q.push(root);
    visited[root] = true;
    while(!q.empty()) {
        connected_node_cnt++;
        int cur_node = q.front();
        q.pop();

        for (int i = 0; i < edges[cur_node].size(); i++) {
            int next_node = edges[cur_node][i];
            if (visited[next_node])
                continue;
            
            q.push(next_node);
            visited[next_node] = true;
        }
    }

    if (connected_node_cnt != m + 1)
        ans = false;

    cout << ans;


    return 0;
}