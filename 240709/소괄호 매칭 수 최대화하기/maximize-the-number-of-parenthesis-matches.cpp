#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int calcPoint(string str) {
    int point = 0;
    vector <int> count_arr;

    int prev_cnt = 0;
    for (int i = str.length() - 1; i >= 0; i--) {
        if (str[i] == ')') {
            count_arr.push_back(++prev_cnt);
        }
        else {
            count_arr.push_back(prev_cnt);
        }
    }
    reverse(count_arr.begin(), count_arr.end());

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(')
            point += count_arr[i];
    }

    return point;
}

bool compare(string str1, string str2) {
    return calcPoint(str1+str2) > calcPoint(str2+str1);
}

int main() {
    int n;
    vector <string> string_arr;

    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        string_arr.push_back(str);
    }

    sort(string_arr.begin(), string_arr.end(), compare);

    string concatenated_str = "";
    for (int i = 0; i < string_arr.size(); i++) {
        concatenated_str += string_arr[i];
    }

    cout << calcPoint(concatenated_str);

    return 0;
}