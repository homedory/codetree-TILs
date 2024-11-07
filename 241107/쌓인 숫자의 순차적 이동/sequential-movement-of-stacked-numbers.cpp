#include <iostream>
#include <tuple>
using namespace std;

#define MAX_N 21
#define MAX_M 105

int dr[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dc[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

int N, M;
int grid[MAX_N][MAX_N][MAX_N*MAX_N];
int top_idx[MAX_N][MAX_N];
int max_val[MAX_N][MAX_N];
pair<int,int> position[MAX_N*MAX_N];


bool inRange(int row, int col) {
    return row > 0 && row <= N && col > 0 && col <= N;
}

int findNearMaxNum(int row, int col) {
    int max_num = 0;
    for (int dir = 0; dir < 8; dir++) {
        int next_row = row + dr[dir];
        int next_col = col + dc[dir];

        if (!inRange(next_row, next_col))
            continue;
        
        max_num = max(max_val[next_row][next_col], max_num);
    }

    return max_num;
}

void simulate(int target_number) {
    int dep_row, dep_col, dest_row, dest_col;
    tie(dep_row, dep_col) = position[target_number];

    int near_max_num = findNearMaxNum(dep_row, dep_col);
    
    if (near_max_num == 0)
        return;
    
    tie(dest_row, dest_col) = position[near_max_num];

    int max_val_candidate = 0;
    int target_idx = 0;
    for (int i = 0; i <= top_idx[dep_row][dep_col]; i++) {
        if (grid[dep_row][dep_col][i] == target_number) {
            target_idx = i;
            break;
        }
        max_val_candidate = max(max_val_candidate, grid[dep_row][dep_col][i]);
    }

    max_val[dep_row][dep_col] = max_val_candidate;

    int end_idx = top_idx[dep_row][dep_col];
    top_idx[dep_row][dep_col] = target_idx - 1;


    // move numbers to destination
    int dest_idx = top_idx[dest_row][dest_col] + 1;
    max_val_candidate = 0;

    for (int i = target_idx; i <= end_idx; i++) {
        int num = grid[dep_row][dep_col][i];
        max_val_candidate = max(max_val_candidate, num);
        position[num] = {dest_row, dest_col};

        grid[dest_row][dest_col][dest_idx] = num;
        dest_idx++;
    }

    top_idx[dest_row][dest_col] = dest_idx - 1;
    max_val[dest_row][dest_col] = max(max_val[dest_row][dest_col], max_val_candidate);
}
    

int main() {
    cin >> N >> M;
    for (int row = 1; row <= N; row++) {
        for (int col = 1; col <= N; col++) {
            int num;
            cin >> num;
        
            grid[row][col][0] = num;
            max_val[row][col] = num;
            position[num] = {row, col};
        }
    }

    for (int i = 0; i < M; i++) {
        int target_num;
        cin >> target_num;
        simulate(target_num);
    }

    for (int row = 1; row <= N; row++) {
        for (int col = 1; col <= N; col++) {
            if (top_idx[row][col] < 0) 
                cout << "None";
            
            for (int i = top_idx[row][col]; i >= 0; i--) {
                cout << grid[row][col][i] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}