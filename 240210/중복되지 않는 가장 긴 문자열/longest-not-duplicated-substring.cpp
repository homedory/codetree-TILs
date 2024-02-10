#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int main() {
    string str;
    unordered_set <char> s;
    int ans = 0;

    cin >> str;

    int j = -1;
    for (int i = 0; i < str.length(); i++) {
        while(j + 1 < str.length() && s.find(str[j + 1]) == s.end()) {
            j++;
            s.insert(str[j]);
        }
        ans = max(ans, j - i + 1);

        s.erase(str[i]);
    }

    cout << ans;

    
    return 0;
}