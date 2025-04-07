#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Query {
    int t;
    int cmd;
    int x;
    int n;
    string name;

    Query(int t, int cmd, int x, int n, string name) {
        this->t = t;
        this->cmd = cmd;
        this->x = x;
        this->n = n;
        this->name = name;
    }
};

bool cmp(Query q1, Query q2) {
    if (q1.t == q2.t) {
        return q1.cmd < q2.cmd;
    }
    return q1.t < q2.t;
}

set<string> names;
unordered_map<string, int> entry_time;
unordered_map<string, int> exit_time;
unordered_map<string, int> seat_position;
unordered_map<string, vector<Query>> sushi;
vector<Query> queries;

int main() {
    int L, Q;
    
    cin >> L >> Q;
    for (int i = 0; i < Q; ++i) {
        int cmd;
        int t; 
        int x = -1, n = -1;
        string name;

        cin >> cmd;
        if (cmd == 100) {
            cin >> t >> x >> name;
            sushi[name].emplace_back(Query(t, cmd, x, n, name));
        }
        else if (cmd == 200) {
            cin >> t >> x >> name >> n;
            entry_time[name] = t;
            seat_position[name] = x;
            names.emplace(name);
        }
        else if (cmd == 300) {
            cin >> t;
        }

        queries.emplace_back(Query(t, cmd, x, n, name));
    }

    for (auto name : names) {
        int enter = entry_time[name];
        int seat = seat_position[name];

        int end_time = 0;
        for (auto s : sushi[name]) {
            if (s.t < enter) {
                int pos = (s.x + (enter - s.t)) % L;
                int waiting_time = ((L + seat) - pos) % L;
                queries.emplace_back(Query(enter + waiting_time, 201, -1, -1, name));
                end_time = max(end_time, enter + waiting_time);
            }
            else {
                int waiting_time = ((L + seat) - s.x) % L;
                queries.emplace_back(Query(s.t + waiting_time, 201, -1, -1, name));
                end_time = max(end_time, s.t + waiting_time);
            }
        }
        exit_time[name] = end_time;
        queries.emplace_back(Query(end_time, 202, -1, -1, name));
    }


    sort(queries.begin(), queries.end(), cmp);

    int sushi_cnt = 0;
    int person_cnt = 0;
    for (auto q : queries) {
        if (q.cmd == 100) {
            ++sushi_cnt;
        }
        else if (q.cmd == 200) {
            ++person_cnt;
        }
        else if (q.cmd == 201) {
            --sushi_cnt;
        }
        else if (q.cmd == 202) {
            --person_cnt;
        }
        else {
            cout << person_cnt << " " << sushi_cnt << "\n";
        }
    }
    

    return 0;
}