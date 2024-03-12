#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

#define MAX_N 505
#define INF 2e9

int main() {
    int N, M, X;
    vector <tuple<int,int,int>> edges[MAX_N];
    int time[MAX_N];

    cin >> N >> M >> X;
    for (int i = 0; i < M; i++) {
        int I, J, L, C;
        cin >> I >> J >> L >> C;
        edges[I].push_back(make_tuple(J, L, C));
        edges[J].push_back(make_tuple(I, L, C));
    }

    for (int i = 1; i <= N; i++) {
        time[i] = INF;
    }

    time[1] = 0;

    priority_queue<tuple<int,int,int>> pq;

    pq.push(make_tuple(-0, 1, INF));
    
    while(!pq.empty()) {
        int current_time, current_vertex, min_c;
        tie(current_time, current_vertex, min_c) = pq.top();
        current_time = -current_time;
        pq.pop();

        if (current_time != time[current_vertex])
            continue;

        for (int i = 0; i < edges[current_vertex].size(); i++) {
            int next_vertex, next_l, next_c;
            tie(next_vertex, next_l, next_c) = edges[current_vertex][i];

            int new_time;
            int new_c = min_c;
            if (next_c < min_c) {
                new_time = time[current_vertex] - (X / min_c) + (X / next_c) + next_l;
                new_c = next_c;
            }
            else {
                new_time = time[current_vertex] + next_l;
            }

            if (time[next_vertex] > new_time) {
                time[next_vertex] = new_time;
                pq.push(make_tuple(-new_time, next_vertex, new_c));
            }
        }
    }

    cout << time[N];

    return 0;
}