#include <iostream>
using namespace std;
#define MAX_N 250005

struct Node {
    Node *prev, *next;
    int data;

    Node(int data) : data(data), prev(nullptr), next(nullptr) {}
};

void connect(Node *s, Node *u) {
    if (s != nullptr)
        s->next = u;
    if (u != nullptr)
        u->prev = s;
}


void Swap(Node *a, Node *b, Node *c, Node *d) {
    Node *prevA = a->prev;
    Node *prevC = c->prev;

    connect(prevA, c);
    connect(prevC, a);

    Node *nextB = b->next;
    Node *nextD = d->next;

    connect(b, nextD);
    connect(d, nextB);
}


int main() {
    int N, Q;
    Node* nodes[MAX_N];

    cin >> N;
    cin >> Q;

    nodes[0] = new Node(0);
    for (int i = 1; i <= N; i++) {
        Node *node = new Node(i);
        nodes[i] = node;
        connect(nodes[i-1], node);
    }

    for (int i = 0; i < Q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        Swap(nodes[a], nodes[b], nodes[c], nodes[d]);
    }


    Node *ptr = nodes[0]->next;
    while(ptr != nullptr) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }

    return 0;
}