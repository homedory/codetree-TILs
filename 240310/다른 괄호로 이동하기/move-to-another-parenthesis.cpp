#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX_N 35
#define MAX_M 950
#define INF 2e9

char board[MAX_N][MAX_N];

int N;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};


int GetIndex(int i, int j) {
    return i * N + j;
}

int main() {
    int A, B;
    vector <pair<int,int>> edge[MAX_M];

    cin >> N >> A >> B;
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                    edge[GetIndex(i, j)].push_back(make_pair(GetIndex(nx, ny), (board[i][j] == board[nx][ny]) ? A : B));
                }
            }
        }
    }

    int ans = 0;

    for (int i = 0; i < N * N; i++) {
        int time[MAX_M];
        for (int j = 0; j < N * N; j++) {
            time[j] = INF;
        }

        time[i] = 0;

        priority_queue<pair<int,int>> pq;

        pq.push(make_pair(-0, i));
        while(!pq.empty()) {
            int current_time = -pq.top().first;
            int current_vertex = pq.top().second;
            pq.pop();

            if (time[current_vertex] != current_time)
                continue;

            for (int j = 0; j < edge[current_vertex].size(); j++) {
                int next_vertex = edge[current_vertex][j].first;
                int new_time = current_time + edge[current_vertex][j].second;

                if (time[next_vertex] > new_time) {
                    time[next_vertex] = new_time;
                    pq.push(make_pair(-new_time, next_vertex));
                }
            }
        }

        for (int j = 0; j < N * N; j++) {
            ans = max(ans, time[j]);
        }

    }


    cout << ans;

    return 0;
}