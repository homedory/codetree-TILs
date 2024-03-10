#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

#define MAX_N 1005
#define INF 2e12

pair<long long, int> edge[MAX_N][MAX_N];
bool visited[MAX_N];

int main() {
    int N, A, B;
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

    for (int i = 0; i <= 1000; i++) {
        cost[i] = INF;
        time[i] = 1e9;
    }

    cost[A] = 0;
    time[A] = 0;

    for (int i = 1; i <= 1000; i++) {
        int min_idx = 0;
        for (int j = 1; j <= 1000; j++) {
            if (visited[j])
                continue;
            
            if (cost[min_idx] > cost[j]) {
                min_idx = j;
                break;
            }
        }

        visited[min_idx] = true;

        for (int j = 1; j <= 1000; j++) {
            if (edge[min_idx][j] == make_pair((long long) 0, (int) 0)) 
                continue;

            long long new_cost = cost[min_idx] + edge[min_idx][j].first;
            int new_time = time[min_idx] + edge[min_idx][j].second;

            if (cost[j] > new_cost) {
                cost[j] = new_cost;
                time[j] = new_time;
            }
            else if (cost[j] == new_cost && time[j] > new_time) {
                time[j] = new_time;
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