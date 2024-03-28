#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_N 10
#define DIR_CNT 4

int N, K, U, D;
int height[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
vector <pair<int,int>> city, selected_city;
int max_cnt = 0;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool inRange(int x, int y) {
    return x > 0 && x <= N && y > 0 && y <= N;
}

bool canGo(int x, int y, int prev_height) {
    int height_diff = abs(prev_height - height[x][y]);
    return inRange(x, y) && height_diff >= U && height_diff <= D && !visited[x][y];
}

void init() {
    for (int i = 1; i <= N; i++) {
        fill(visited[i] + 1, visited[i] + N + 1, false);
    }
}

int countConnectedCity() {
    init();
    
    queue <pair<int,int>> q;
    int city_cnt = 0;

    for (int i = 0; i < selected_city.size(); i++) {
        auto [x_point, y_point] = selected_city[i];
        visited[x_point][y_point] = true;
        q.push(make_pair(x_point, y_point));
    }

    while(!q.empty()) {
        auto [curr_x, curr_y] = q.front();
        q.pop();

        city_cnt++;

        for (int dir = 0; dir < DIR_CNT; dir++) {
            int next_x = curr_x + dx[dir];
            int next_y = curr_y + dy[dir];

            if (!canGo(next_x, next_y, height[curr_x][curr_y]))
                continue;
            
            visited[next_x][next_y] = true;
            q.push(make_pair(next_x, next_y));
        }
    }

    return city_cnt;
}

void chooseCity(int curr_idx, int curr_cnt) {
    if (curr_cnt == K) {
        max_cnt = max(max_cnt, countConnectedCity());
        return;
    }

    if (curr_idx == city.size()) {
        return;
    }

    auto [x_point, y_point] = city[curr_idx];

    selected_city.push_back(make_pair(x_point, y_point));
    chooseCity(curr_idx + 1, curr_cnt + 1);

    selected_city.pop_back();
    chooseCity(curr_idx + 1, curr_cnt);
}

int main() {
    cin >> N >> K >> U >> D;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> height[i][j];
            city.push_back(make_pair(i, j));
        }
    }

    chooseCity(0, 0);

    cout << max_cnt;

    return 0;
}