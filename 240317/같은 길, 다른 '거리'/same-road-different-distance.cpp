#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX_N 10005
#define INF 2e9

int N, M;
vector <pair<int,int>> edges[2][MAX_N], rev_edges[2][MAX_N];
int alarm_cnt[MAX_N], rev_dist[2][MAX_N];

void Rev_Dijkstra(int type, int start) {
    for (int i = 0; i <= N; i++) {
        rev_dist[type][i] = INF;
    }

    rev_dist[type][start] = 0;

    priority_queue<pair<int,int>> pq;

    pq.push(make_pair(-0, start));
    while(!pq.empty()) {
        int current_dist = -pq.top().first;
        int current_vertex = pq.top().second;
        pq.pop();

        if (rev_dist[type][current_vertex] != current_dist)
            continue;
        
        for (int i = 0; i < rev_edges[type][current_vertex].size(); i++) {
            int next_vertex = rev_edges[type][current_vertex][i].first;
            int new_dist = current_dist + rev_edges[type][current_vertex][i].second;

            if (rev_dist[type][next_vertex] <= new_dist)
                continue;

            rev_dist[type][next_vertex] = new_dist;
            pq.push(make_pair(-new_dist, next_vertex));
        }
    }
}

void Alarm_Dijkstra(int start) {
    for (int i = 0; i <= N; i++) {
        alarm_cnt[i] = INF;
    }

    alarm_cnt[start] = 0;

    priority_queue<pair<int,int>> pq;

    pq.push(make_pair(-0, start));

    while(!pq.empty()) {
        int currnet_cnt = -pq.top().first;
        int current_vertex = pq.top().second;
        pq.pop();

        if (alarm_cnt[current_vertex] != currnet_cnt)
            continue;

        for (int i = 0; i < edges[0][current_vertex].size(); i++) {
            int next_vertex = edges[0][current_vertex][i].first;
            int a_dist = edges[0][current_vertex][i].second;
            int b_dist = edges[1][current_vertex][i].second;
            int cnt = 0;

            if (rev_dist[0][current_vertex] != rev_dist[0][next_vertex] + a_dist)
                cnt++;
            
            if (rev_dist[1][current_vertex] != rev_dist[1][next_vertex] + b_dist)
                cnt++;
            
            if (alarm_cnt[next_vertex] <= currnet_cnt + cnt)
                continue;

            alarm_cnt[next_vertex] = currnet_cnt + cnt;
            pq.push(make_pair(-(currnet_cnt + cnt), next_vertex));
        }
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int start, end, a_distance, b_distance;

        cin >> start >> end >> a_distance >> b_distance;
        edges[0][start].push_back(make_pair(end, a_distance));
        edges[1][start].push_back(make_pair(end, b_distance));
        rev_edges[0][end].push_back(make_pair(start, a_distance));
        rev_edges[1][end].push_back(make_pair(start, b_distance));
    }
    

    Rev_Dijkstra(0, N);
    Rev_Dijkstra(1, N);

    Alarm_Dijkstra(1);
    
    cout << alarm_cnt[N];

    return 0;
}