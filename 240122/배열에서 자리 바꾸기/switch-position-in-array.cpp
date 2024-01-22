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

void PopAndInsertPrev(Node *s, Node *e, Node *v) {
    connect(s->prev, e->next);
    s->prev = e->next = nullptr;

    connect(v->prev, s);
    connect(e, v);
}

void PopAndInsertNext(Node *s, Node *e, Node *v) {
    connect(s->prev, e->next);
    s->prev = e->next = nullptr;

    connect(e, v->next);
    connect(v, s);
}

void PopAndSwap(Node *a, Node *b, Node *c, Node *d) {
    if (a->prev == d) {
        Node *c_prev = c->prev;
        PopAndInsertPrev(c, d, b->next);
        PopAndInsertNext(a, b, c_prev);
    }
    else {
        Node *a_prev = a->prev;
        PopAndInsertPrev(a, b, d->next);
        PopAndInsertNext(c, d, a_prev);
    }
}


int main() {
    int N, Q;
    Node* nodes[MAX_N];

    cin >> N;
    cin >> Q;

    nodes[0] = new Node(0);
    for (int i = 1; i <= N + 1; i++) {
        Node *node = new Node(i);
        nodes[i] = node;
        connect(nodes[i-1], node);
    }

    for (int i = 0; i < Q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        PopAndSwap(nodes[a], nodes[b], nodes[c], nodes[d]);
    }


    Node *ptr = nodes[0]->next;
    while(ptr != nullptr && ptr->data != N + 1) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }

    return 0;
}