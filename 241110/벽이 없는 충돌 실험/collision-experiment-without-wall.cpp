#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_N 105

int N, T;
tuple<int, int, char> bead[MAX_N];
int weight[MAX_N];
bool removed[MAX_N];

bool isOpposite(char dir1, char dir2) {
    return (dir1 == 'U' && dir2 == 'D') || (dir1 == 'D' && dir2 == 'U') ||
           (dir1 == 'R' && dir2 == 'L') || (dir1 == 'L' && dir2 == 'R');
}

int calcTime(int start, int end, char direction) {
    int x_1, y_1, x_2, y_2;
    tie(x_1, y_1, ignore) = bead[start];
    tie(x_2, y_2, ignore) = bead[end];
    
    int end_time;
    switch(direction) {
        case 'R':
            end_time = (x_2-x_1) * 2;
            break;
        case 'L':
            end_time = (x_1-x_2) * 2;
            break;
        case 'U':
            end_time = (y_2-y_1) * 2;
            break;
        case 'D':
            end_time = (y_1-y_2) * 2;
            break;
    }

    return end_time;
}

int getCollisonTime(int bead_1, int bead_2) {
    int direction_1, direction_2;

    tie(ignore, ignore, direction_1) = bead[bead_1];
    tie(ignore, ignore, direction_2) = bead[bead_2];

    int time_1 = calcTime(bead_1, bead_2, direction_1);
    int time_2 = calcTime(bead_2, bead_1, direction_2);

    if (time_1 < 0 || time_2 < 0) {
        return 0;
    }

    if (isOpposite(direction_1, direction_2) && time_1 == time_2) {
        return time_1 / 2;
    }
    
    if (time_1 == time_2) {
        return time_1;
    }

    return 0;
}

void initialize() {
    for (int i = 1; i <= N; i++) 
        removed[i] = false;
}



int main() {
    cin >> T;

    while(T--) {
        cin >> N;

        initialize();

        for (int i = 1; i <= N; i++) {
            int r, c, w;
            char d;
            cin >> r >> c >> w >> d;
            bead[i] = make_tuple(r, c, d);
            weight[i] = w;
        }

        vector <tuple<int,int,int>> collision_info;
        for (int i = 1; i <= N; i++) {
            for (int j = i + 1; j <= N; j++) {
                int collsion_time  = getCollisonTime(i, j);

                if (collsion_time > 0) {
                    collision_info.push_back(make_tuple(collsion_time, i, j));
                }
            }
        }

        sort(collision_info.begin(), collision_info.end());

        int last_collison_time = -1;
        for (auto info : collision_info) {
            int bead_1, bead_2, collsion_time;
            tie(collsion_time, bead_1, bead_2) = info;

            if (removed[bead_1] || removed[bead_2])
                continue;
            
            int removed_bead = (weight[bead_1] <= weight[bead_2]) ? bead_1 : bead_2;

            removed[removed_bead] = true;
            last_collison_time = collsion_time;
        }

        cout << last_collison_time << "\n";
    }


    return 0;
}