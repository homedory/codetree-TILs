#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

#define MAX_N 100005

int N, Q;
int auth[MAX_N];
int on[MAX_N];
int parent[MAX_N];
vector <int> child[MAX_N];

void swap_parent(int c1, int c2) {
    int p1 = parent[c1];
    int p2 = parent[c2];


    if (child[p1][0] == c1) {
        child[p1][0] = c2;
    }
    else {
        child[p1][1] = c2;
    }

    if (child[p2][0] == c2) {
        child[p2][0] = c1;
    }
    else {
        child[p2][1] = c1;
    }

    swap(parent[c1], parent[c2]);
}

int countChatRoom(int c) {
    queue<pair<int,int>> q;
    
    int cnt = 0;

    q.emplace(c, 0);
    while(!q.empty()) {
        int cur_node = q.front().first;
        int depth = q.front().second;
        q.pop();

        for (auto c : child[cur_node]) {
            if (on[c] == 0)
                continue;
            
            if (auth[c] > depth)
                ++cnt;
            
            q.emplace(c, depth + 1);
        }
    }

    return cnt;
}

int main() {
    cin >> N >> Q;

    memset(on, 1, sizeof(on));
    int cmd;
    int p, c, power, c1, c2;
    for (int i = 0; i < Q; ++i) {
        cin >> cmd;
        if (cmd == 100) {
            for (int j = 1; j <= N; ++j) {
                cin >> p;
                child[p].emplace_back(j);
                parent[j] = p;
            }

            for (int j = 1; j <= N; ++j) {
                cin >> auth[j];                
            }
        }
        else if (cmd == 200) {
            cin >> c;
            on[c] = (on[c] ? 0 : 1);
        }
        else if (cmd == 300) {
            cin >> c >> power;
            auth[c] = power;
        }
        else if (cmd == 400) {
            cin >> c1 >> c2;
            swap_parent(c1, c2);
        }
        else if (cmd == 500) {
            cin >> c;
            cout << countChatRoom(c) << "\n";
        }
    }

    return 0;
}