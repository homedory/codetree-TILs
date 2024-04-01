#include <iostream>
using namespace std;

#define MAX_N 13
#define MAX_K 4

int dist[MAX_N];
int pieces_dist[MAX_K];
int N, M, K;
int max_score = 0;


void calcScore(int turn_cnt) {
    if (turn_cnt == N) {
        int score = 0;
        for (int i = 0; i < K; i++) {
            if (pieces_dist[i] >= M)
                score++;
        }
        max_score = max(max_score, score);
        return;
    }

    for (int i = 0; i < K; i++) {
        pieces_dist[i] += dist[turn_cnt];
        calcScore(turn_cnt + 1);
        pieces_dist[i] -= dist[turn_cnt];
    }
}

int main() {
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        cin >> dist[i];
    }

    for (int i = 0; i < K; i++) {
        pieces_dist[i] = 1;
    }

    calcScore(0);

    cout << max_score;

    return 0;
}