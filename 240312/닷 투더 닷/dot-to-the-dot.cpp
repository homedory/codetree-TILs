#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <set>
using namespace std;

#define MAX_N 505
#define INF 2e9

int N, M, X;
vector <tuple<int,int,int>> edges[MAX_N];

int Dijkstra(int min_c) {
    int time[MAX_N];

    for (int i = 1; i <= N; i++) {
        time[i] = INF;
    }
    time[1] = 0;

    priority_queue<pair<int,int>> pq;

    pq.push(make_pair(-0, 1));

    while(!pq.empty()) {
        int current_time = -pq.top().first;
        int current_vertex = pq.top().second;
        pq.pop();

        if (time[current_vertex] != current_time) {
            continue;
        }

        for (int i = 0; i < edges[current_vertex].size(); i++) {
            int next_vertex, next_l, next_c;
            tie(next_vertex, next_l, next_c) = edges[current_vertex][i];

            if (next_c < min_c)
                continue;
            
            int new_time = current_time + next_l;
            if (time[next_vertex] > new_time) {
                time[next_vertex] = new_time;
                pq.push(make_pair(-new_time, next_vertex));
            }
        }
    }

    return time[N] + (X / min_c);
}

int main() {
    set<int> all_c;
    cin >> N >> M >> X;
    for (int i = 0; i < M; i++) {
        int I, J, L, C;
        cin >> I >> J >> L >> C;
        all_c.insert(C);
        edges[I].push_back(make_tuple(J, L, C));
        edges[J].push_back(make_tuple(I, L, C));
    }

    int ans = INF;
    for (set<int>::iterator it = all_c.begin(); it != all_c.end(); it++) {
        int t = Dijkstra(*it);
        ans = min(ans, t);
    }

    cout << ans;

    return 0;
}