#include <iostream>
using namespace std;

int N, M, Q;
int building[105][105];

bool propagationPossible(int row1, int row2) {
    for (int i = 1; i <= M; i++) {
        if (building[row1][i] == building[row2][i])
            return true;
    }

    return false;
}

void shift(int row, char direction) {
    if (direction == 'L') {
        int tmp = building[row][M];
        for (int i = M - 1; i > 0; i--) {
            building[row][i + 1] = building[row][i]; 
        }
        building[row][1] = tmp;
    }
    else {
        int tmp = building[row][1];
        for (int i = 1; i < M; i++) {
            building[row][i] = building[row][i + 1];
        }
        building[row][M] = tmp;
    }
}



int main() {
    cin >> N >> M >> Q;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> building[i][j];
        }
    }

    while(Q--) {
        int r;
        char d;
        cin >> r >> d;

        shift(r, d);

        // upper direction
        int row = r + 1;
        int direction = (d == 'L') ? 'R' : 'L';
        while(row <= N && propagationPossible(row-1, row)) {
            shift(row, direction);
            row++;
            direction = (direction == 'L') ? 'R' : 'L';
        }

        // lower direction
        row = r - 1;
        direction = (d == 'L') ? 'R' : 'L';
        while(row > 0 && propagationPossible(row+1, row)) {
            shift(row, direction);
            row--;
            direction = (direction == 'L') ? 'R' : 'L';
        }
    }

    // answer
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cout << building[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}