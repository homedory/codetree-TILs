#include <iostream>
#include <string>
using namespace std;

string str;

int encodingLength() {
    int total_len = 0;
    char current_char = str[0];

    for (int i = 1; i < str.length(); i++) {
        if (str[i] == current_char)
            continue;
        
        total_len += 2;
        current_char = str[i];
    }
    total_len += 2;

    return total_len;
}

int main() {
    int str_len;
    int min_len = 20;

    cin >> str;
    str_len = str.length();
    for (int i = 0; i < str_len; i++) {
        min_len = min(min_len, encodingLength());
        // right shift
        char temp = str[str_len-1];
        for (int j = str_len - 1; j > 0; j--) {
            str[j] = str[j-1];
        }
        str[0] = temp;
    }

    cout << min_len;

    return 0;
}