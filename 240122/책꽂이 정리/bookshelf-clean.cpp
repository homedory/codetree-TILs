#include <iostream>
using namespace std;
#define MAX_K 105

struct Node {
    Node *prev, *next;
    int data;

    Node(int data) : data(data), prev(nullptr), next(nullptr) {}
};

int book_cnt[MAX_K];
Node* head[MAX_K];
Node* tail[MAX_K];

void connect(Node* u, Node* v) {
    if (u != nullptr)
        u->next = v;
    if (v != nullptr)
        v->prev = u;
}

Node* PopFront(int n) {
    Node *node = head[n];

    //bookshelf is empty
    if (node == nullptr)
        return nullptr;

    head[n] = node->next;

    //bookshelf is empty after pop
    if (head[n] == nullptr) {
        tail[n] = nullptr;
    }
    else {
        head[n]->prev = nullptr;
    }
    node->next = nullptr;

    book_cnt[n]--;
    return node;
}

Node* PopEnd(int n) {
    Node *node = tail[n];

    //bookshelf is empty
    if (node == nullptr)
        return nullptr;
    
    tail[n] = node->prev;

    //bookshelf is empty after pop
    if (tail[n] == nullptr) {
        head[n] = nullptr;
    }
    else {
        tail[n]->next = nullptr;
    }
    node->prev = nullptr;

    book_cnt[n]--;
    return node;
}

void InsertEnd(Node* u, int n) {
    //bookshelf was empty
    if (tail[n] == nullptr) {
        head[n] = u;
    }
    connect(tail[n], u);
    tail[n] = u;

    book_cnt[n]++;
}

void InsertFront(Node* u, int n) {
    //bookshelf was empty
    if (head[n] == nullptr) {
        tail[n] = u;
    }
    connect(u, head[n]);
    head[n] = u;

    book_cnt[n]++;
}

void PopFirstAndInsertEnd(int i, int j) {
    Node *node = PopFront(i);

    //'i'th bookshelf is empty
    if (node == nullptr) 
        return;
    
    InsertEnd(node, j);
}

void PopEndAndInsertFront(int i, int j) {
    Node *node = PopEnd(i);

    //'i'th bookshelf is empty
    if (node == nullptr) 
        return;
    
    InsertFront(node, j);
}

void MoveToEnd(int i, int j) {
    //i == j
    if (i == j)
        return;

    //'i'th bookshelf is empty
    if (head[i] == nullptr) 
        return;
    
    //'j'th bookshelf is empty
    if (head[j] == nullptr)
        head[j] = head[i];
    
    connect(tail[j], head[i]);
    tail[j] = tail[i];

    head[i] = tail[i] = nullptr;

    book_cnt[j] += book_cnt[i];
    book_cnt[i] = 0;
}

void MoveToFront(int i, int j) {
    //i == j
    if (i == j)
        return;

    //'i'th bookshelf is empty
    if (head[i] == nullptr) 
        return;
    

    //'j'th bookshelf is empty
    if (tail[j] == nullptr) 
        tail[j] = tail[i];
    
    connect(tail[i], head[j]);
    head[j] = head[i];

    head[i] = tail[i] = nullptr;

    book_cnt[j] += book_cnt[i];
    book_cnt[i] = 0;
}

int main() {
    int N, K, Q;
    

    cin >> N >> K;

    //initialize head and tail
    for (int i = 1; i <= K; i++) {
        head[i] = tail[i] = nullptr;
    }

    head[1] = new Node(1);

    Node *ptr = head[1];
    for (int i = 1; i < N; i++) {
        Node* node = new Node(i+1);
        connect(ptr, node);
        ptr = node;
    }
    book_cnt[1] = N;
    tail[1] = ptr;

    cin >> Q;

    for (int q = 0; q < Q; q++) {
        int n, i, j;
        cin >> n >> i >> j;
        if (n == 1) {
            PopFirstAndInsertEnd(i, j);
        }
        else if (n == 2) {
            PopEndAndInsertFront(i, j);
        }
        else if (n == 3) {
            MoveToFront(i, j);
        }
        else if (n == 4) {
            MoveToEnd(i, j);
        }
    }

    for (int i = 1; i <= K; i++) {
        cout << book_cnt[i] << " ";

        Node *ptr = head[i];
        while(ptr != nullptr) {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << "\n";
    }
    return 0;
}