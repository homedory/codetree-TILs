#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

struct Node {
    Node *prev, *next;
    string name;

    Node(string str) : name(str), prev(nullptr), next(nullptr) {};
};

void connect(Node *node_a, Node *node_b) {
    if (node_a != nullptr)
        node_a->next = node_b;
    if (node_b != nullptr)
        node_b->prev = node_a;
}

void removeNode(Node *node) {
    connect(node->prev, node->next);
    node->prev = nullptr;
    node->next = nullptr;
}

void insertFront(Node *node_a, Node *node_b) {
    connect(node_a->prev, node_a->next);
    connect(node_b->prev, node_a);
    connect(node_a, node_b);
}

void insertFrontRange(Node *node_a, Node *node_b, Node *node_c) {
    connect(node_a->prev, node_b->next);
    connect(node_c->prev, node_a);
    connect(node_b, node_c);
}

void printLine(Node *start_point) {
    Node *node = start_point->next;

    if (node == nullptr) {
        cout <<-1 << "\n";
        return;
    }

    while(node != nullptr) {
        cout << node->name << " ";
        node = node->next;
    }
    cout << "\n";
}

int main() {
    int N, M, Q;
    unordered_map <string, Node*> person;
    Node* line[11];

    cin >> N >> M >> Q;
    int X = N / M;
    for (int i = 1; i <= M; i++) {
        line[i] = new Node("line_start");

        Node *prev_node = line[i];
        for (int j = 0; j < X; j++) {
            string str;
            cin >> str;

            Node *new_node = new Node(str);
            person[str] = new_node;
            connect(prev_node, new_node);
            prev_node = new_node;
        }
    }

    for (int i = 0; i < Q; i++) {
        int command;
        string str_a, str_b, str_c;
        cin >> command;

        switch(command) {
            case 1:
                cin >> str_a >> str_b;
                insertFront(person[str_a], person[str_b]);
                break;
            case 2:
                cin >> str_a;
                removeNode(person[str_a]);
                break;
            case 3:
                cin >> str_a >> str_b >> str_c;
                insertFrontRange(person[str_a], person[str_b], person[str_b]);
                break;
        }
    }

    for (int i = 1; i <= M; i++) {
        printLine(line[i]);
    }

    return 0;
}