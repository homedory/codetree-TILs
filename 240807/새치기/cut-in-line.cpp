#include <iostream>
using namespace std;


struct Node {
    Node *prev, *next;
    int num;

    Node(int num): num(num), prev(nullptr), next(nullptr) {};
};

int N, M, Q;
Node* person[100005];

void remove(Node *node) {
    if (node->prev != nullptr)
        node->prev->next = node->next;
    if (node->next != nullptr)
        node->next->prev = node->prev;
}

void connect(Node *node1, Node *node2) {
    node1->next = node2;
    node2->prev = node1;
}

void insertFront(Node *node1, Node *node2) {
    remove(node1);
    connect(node2->prev, node1);
    connect(node1, node2);
}

void insertFrontRange(int a, int b, Node* node) {
    if (person[b]->next != nullptr) 
        connect(person[a]->prev, person[b]->next);
    else
        person[a]->prev->next = nullptr;
    
    connect(node->prev, person[a]);
    connect(person[b], node);
}


int main() {
    Node *line[11];
    cin >> N >> M >> Q;

    for (int i = 1; i <= M; i++) {
        int num_people;
        cin >> num_people;

        line[i] = new Node(-1);
        Node *prev_node = line[i];

        for (int j = 0; j < num_people; j++) {
            int person_num;
            cin >> person_num;
            
            person[person_num] = new Node(person_num);
            connect(prev_node, person[person_num]);
            prev_node = person[person_num];
        }
    }

    for (int i = 0; i < Q; i++) {
        int command;
        int a, b, c;
        cin >> command;

        switch(command) {
            case 1:
                cin >> a >> b;
                insertFront(person[a], person[b]);
                break;
            case 2:
                cin >> a;
                remove(person[a]);
                break;
            case 3:
                cin >> a >> b >> c;
                insertFrontRange(a, b, person[c]);
                break;
        }
    }

    // answer
    for (int i = 1; i <= M; i++) {
        if (line[i]->next == nullptr) {
            cout << "-1\n";
            continue;
        }

        Node *node = line[i]->next;
        while(node != nullptr) {
            cout << node->num << " ";
            node = node->next;
        }
        cout << "\n";
    }
    return 0;
}