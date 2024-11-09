#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

#define MAX_N 51

int N, M, K, T;
int reamin_count;
pair<int,int> position[MAX_N*MAX_N];
char direction[MAX_N*MAX_N];
int velocity[MAX_N*MAX_N];
bool removed[MAX_N*MAX_N];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, 1, -1};

bool inRange(int idx) {
    return idx > 0 && idx <= N;
}


pair<int,int> move(int num) {
    int nr, nc;
    tie(nr, nc) = position[num];
    
    int dir_idx;
    switch(direction[num]) {
        case 'U':
            dir_idx = 0;        
            break;
        case 'D':
            dir_idx = 1;
            break;
        case 'R':
            dir_idx = 2;
            break;
        case 'L':
            dir_idx = 3;
            break;
    }
    nr += velocity[num] * dr[dir_idx];
    nc += velocity[num] * dc[dir_idx];

    if (nr < 0) {
        nr = ((-nr) - 1) % (2*N-2);
        if (nr < N-1) {
            direction[num] = 'D';
            nr += 1;
        }
        else {
            nr = (2*N-3) - nr;
        }
    }
    else if (nr >= N) {
        nr = nr % (2*N-2);
        if (nr >= N) {
            direction[num] = 'U';
            nr = N - 2 - (nr%N);
        }
        else {
            nr = nr % N;
        }
    }
    else if (nc < 0) {
        nc = ((-nc) - 1) % (2*N-2);
        if (nc < N-1) {
            direction[num] = 'R';
            nc += 1;
        }
        else {
            nc = (2*N-3) - nc;
        }
    }
    else if (nc >= N) {
        nc = nc % (2*N-2);
        if (nc >= N) {
            direction[num] = 'L';
            nc = N - 2 - (nc%N);
        }
        else {
            nc = nc % N;
        }
    }

    return {nr, nc};
}

void simulate() {
    // <velocity, numer>
    priority_queue<pair<int,int>>grid[MAX_N][MAX_N];

    for (int i = 1; i <= M; i++) {
        if (removed[i])
            continue;

        int nr, nc;

        tie(nr, nc) = move(i);
        position[i] = {nr, nc};
        grid[nr][nc].push({-velocity[i], -i});
    }
    
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            while(grid[r][c].size() > K) {
                int num;
                tie(ignore, num) = grid[r][c].top();
                grid[r][c].pop();
                num *= -1;
                
                removed[num] = true;
                reamin_count--;
            }
        }
    }
}

int main() {
    cin >> N >> M >> T >> K;

    for (int i = 1; i <= M; i++) {
        int r, c, v;
        char d;
        cin >> r >> c >> d >> v;

        position[i] = {r-1, c-1};
        direction[i] = d;
        velocity[i] = v;
    }

    reamin_count = M;
    for (int i = 0; i < T; i++) {
        simulate();
    }

    cout << reamin_count;

    return 0;
}