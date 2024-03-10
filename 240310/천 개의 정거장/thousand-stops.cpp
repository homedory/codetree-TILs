#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

#define MAX_N 1005
#define INF 2e12

pair<long long, int> edge[MAX_N][MAX_N];

int main() {
    int N, A, B;
    vector <tuple<int,long long,int>> edges[MAX_N];
    long long cost[MAX_N];
    int time[MAX_N];

    cin >> A >> B >> N;

    for (int i = 0; i < N; i++) {
        long long fair;
        int num_stops;
        vector <int> route;

        cin >> fair >> num_stops;
        for (int j = 0; j < num_stops; j++) {
            int stop;
            cin >> stop;
            route.push_back(stop);
        }

        for (int j = 0; j < num_stops; j++) {
            for (int k = j + 1; k < num_stops; k++) {
                if (edge[route[j]][route[k]] == make_pair((long long) 0, (int) 0)) {
                    edge[route[j]][route[k]] = make_pair(fair, k - j);
                }
                else {
                    edge[route[j]][route[k]] = min(edge[route[j]][route[k]], make_pair(fair, k - j));
                }
            }
        }
    }

    for (int i = 1; i <= 1000; i++) {
        cost[i] = INF;
        time[i] = 1e9;
    }

    cost[A] = 0;
    time[A] = 0;

    priority_queue<tuple<long long, int>> pq;

    pq.push(make_tuple(-0, A));

    while(!pq.empty()) {
        long long current_cost;
        int current_vertex, current_time;
        tie(current_cost, current_vertex) = pq.top();
        current_cost = -current_cost;
        pq.pop();

        if (cost[current_vertex] != current_cost) {
            continue;
        }

        for (int i = 1; i <= 1000; i++) {
            long long next_cost = edge[current_vertex][i].first;
            int next_time = edge[current_vertex][i].second;

            if (next_cost == 0)
                continue;

            long long new_cost = current_cost + next_cost;
            int new_time = time[current_vertex] + next_time;
            if (cost[i] > new_cost) {
                cost[i] = new_cost;
                time[i] = new_time;
                pq.push(make_tuple(-new_cost, i));
            }
            else if (cost[i] == new_cost && time[i] > new_time) {
                time[i] = new_time;
            }
        }
    }

    if (cost[B] == INF) {
        cout << "-1 -1";
    }
    else {
        cout << cost[B] << " " << time[B];
    }
    
    return 0;
}