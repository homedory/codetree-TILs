#include <iostream>
#include <string>
using namespace std;

struct Node {
    string str;
    Node *prev, *next;

    Node(string str) : str(str), prev(nullptr), next(nullptr) {}
};

void InsertPrev(Node *cur, Node *u) {
    u->prev = cur->prev;
    u->next = cur;

    if (u->prev != nullptr)
        u->prev->next = u;
    if (u->next != nullptr)
        u->next->prev = u;
}

void InsertNext(Node *cur, Node *u) {
    u->prev = cur;
    u->next = cur->next;
    
    if (u->prev != nullptr)
        u->prev->next = u;
    if (u->next != nullptr)
        u->next->prev = u;
}

void PrintNodes(Node *cur) {
    if (cur->prev != nullptr) {
        cout << cur->prev->str << " ";
    }
    else {
        cout << "(Null) ";
    }

    cout << cur->str << " ";

    if (cur->next != nullptr) {
        cout << cur->next->str << "\n";
    }
    else {
        cout << "(Null)\n";
    }
}

int main() {
    string str;
    int n;

    cin >> str;
    Node *cur = new Node(str);
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a == 1) {
            cin >> str;
            Node *u = new Node(str);
            InsertPrev(cur, u);
            PrintNodes(cur);
        }
        else if (a == 2) {
            cin >> str;
            Node *u = new Node(str);
            InsertNext(cur, u);
            PrintNodes(cur);
        }
        else if (a == 3) {
            if (cur->prev != nullptr) {
                cur = cur->prev;
            }
            PrintNodes(cur);
        }
        else if (a == 4) {
            if (cur->next != nullptr) {
                cur = cur->next;
            }
            PrintNodes(cur);
        }
    }

    
    return 0;
}