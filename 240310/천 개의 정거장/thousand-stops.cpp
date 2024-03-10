#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

#define MAX_N 1005
#define INF 2e12

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
                edges[route[j]].push_back(make_tuple(route[k], fair, k - j));
            }
        }
    }

    for (int i = 1; i <= 1000; i++) {
        cost[i] = INF;
        time[i] = 1e9;
    }

    cost[A] = 0;
    time[A] = 0;

    priority_queue<tuple<long long, int, int>> pq;

    pq.push(make_tuple(-0, 0, A));

    while(!pq.empty()) {
        long long current_cost;
        int current_vertex, current_time;
        tie(current_cost, current_time, current_vertex) = pq.top();
        current_cost = -current_cost;
        pq.pop();

        if (cost[current_vertex] != current_cost) {
            continue;
        }

        time[current_vertex] = min(time[current_vertex], current_time);

        for (int i = 0; i < edges[current_vertex].size(); i++) {
            int next_vertex, next_time;
            long long next_cost;
            tie(next_vertex, next_cost, next_time) = edges[current_vertex][i];

            long long new_cost = current_cost + next_cost;
            if (cost[next_vertex] > new_cost) {
                cost[next_vertex] = new_cost;
                pq.push(make_tuple(-new_cost,time[current_vertex] + next_time, next_vertex));
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