#include <iostream>
using namespace std;

#define INF 1300000000

int dist[105][105];
bool red_included[105][105];
int N, M, P, Q;


int main() {
    cin >> N >> M >> P >> Q;

    // initialize
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dist[i][j] = INF;
        }
    }
    for (int i = 1; i <= N; i++) {
        dist[i][i] = 0;
    }
    for (int i = 1; i <= P; i++) {
        red_included[i][i] = true;
    }

    // edge input
    for (int i = 0; i < M; i++) {
        int start, end, cost;
        cin >> start >> end >> cost;
        dist[start][end] = cost;
        if (start <= P || end <= P)
            red_included[start][end] = true;
    }

    // solution
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (dist[i][j] >= dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];

                    if (red_included[i][k] || red_included[k][j])
                        red_included[i][j] = true;
                    else
                        red_included[i][j] = false;
                }
            }
        }
    }
    
    long long sum = 0;
    int count = 0;

    for (int i = 0; i < Q; i++) {
        int start, end;
        cin >> start >> end;

        if (dist[start][end] == INF)
            continue;

        if (red_included[start][end]) {
            sum += dist[start][end];
            count++;
        }
        else {
            int new_dist = INF;
            for (int k = 1; k <= N; k++) {
                if (red_included[start][k] == false && red_included[k][end] == false)
                    continue;
                if (dist[start][k] == INF || dist[k][end] == INF)
                    continue;
                
                new_dist = min(new_dist, dist[start][k] + dist[k][end]);
            }

            if (new_dist == INF)
                continue;
            
            sum += new_dist;
            count++;

        }
    }

    cout << count << "\n";
    cout << sum;

    return 0;
}