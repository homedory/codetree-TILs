#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_N 30

int board[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int n;

bool canGo(int x, int y) {
    if (x > 0 && x <= n && y > 0 && y <= n && board[x][y])
        return true;
    
    return false;
}

int dfs(int x, int y) {
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    int sum = 1;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (canGo(nx, ny) && !visited[nx][ny]) {
            visited[nx][ny] = true;
            sum += dfs(nx, ny);
        }
    }

    return sum;
}

int main() {
    vector <int> num_people;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (board[i][j] && !visited[i][j]) {
                visited[i][j] = true;
                num_people.push_back(dfs(i, j));
            }
        }
    }

    sort(num_people.begin(), num_people.end());

    cout << num_people.size() << "\n";
    for (int i = 0; i < num_people.size(); i++) {
        cout << num_people[i] << "\n";
    }

    return 0;
}