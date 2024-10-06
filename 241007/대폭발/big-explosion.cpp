#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 105

int n, m, r, c;
int grid[MAX_N][MAX_N];
vector<pair<int,int>> bomb;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

bool inRange(int row, int column) {
    return row > 0 && row <= n && column > 0 && column <= n;
}

int main() {
    cin >> n >> m >> r >> c;

    grid[r][c] = 1;
    bomb.push_back(make_pair(r, c));
    
    int elapsed_time = 1;

    while(elapsed_time <= m) {
        int bomb_cnt = bomb.size();

        for (int i = 0; i < bomb_cnt; i++) {
            int row = bomb[i].first;
            int column = bomb[i].second;
            int dist = 1 << (elapsed_time-1);

            for (int dir = 0; dir < 4; dir++) {
                int next_row = row + dist*dr[dir];
                int next_column = column + dist*dc[dir];
                
                if (!inRange(next_row, next_column))
                    continue;
                
                if (grid[next_row][next_column] == 0) {
                    grid[next_row][next_column] = 1;
                    bomb.push_back(make_pair(next_row, next_column));
                }
            }
        }
        elapsed_time++;
    }

    cout << bomb.size();


    return 0;
}