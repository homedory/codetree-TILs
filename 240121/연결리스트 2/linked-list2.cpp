#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    Node *prev, *next;
    int data;

    Node(int data): data(data), prev(nullptr), next(nullptr) {}
};

void DeleteNode(Node *node) {
    if (node->prev != nullptr) 
        node->prev->next = node->next;
    if (node->next != nullptr) 
        node->next->prev = node->prev;
    
    node->prev = nullptr;
    node->next = nullptr;
}

void InsertPrev(Node *cur, Node *s) {
    s->prev = cur->prev;
    s->next = cur;
    if (s->prev != nullptr)
        s->prev->next = s;
    if (s->next != nullptr)
        s->next->prev = s;
}

void InsertNext(Node *cur, Node *s) {
    s->prev = cur;
    s->next = cur->next;
    if (s->prev != nullptr) 
        s->prev->next = s;
    if (s->next != nullptr)
        s->next->prev = s;
}

void PrintNode(Node* cur) {
    if (cur->prev != nullptr)
        cout << cur->prev->data << " ";
    else
        cout << "0 ";
    
    if (cur->next != nullptr)
        cout << cur->next->data << "\n";
    else
        cout << "0\n";
    
}

void PrintNextNode(Node* cur) {
    if (cur->next == nullptr)
        cout << "0 ";
    else {
        cout << cur->next->data << " ";
    }
}

int main() {
    int N, Q;
    unordered_map <int, Node*> nodes;

    cin >> N;
    cin >> Q;

    for (int q = 0; q < Q; q++) {
        int x, i, j;
        Node *node_i, *node_j;

        cin >> x;

        if (x == 1) {
            cin >> i;
            if (nodes.find(i) != nodes.end())
                node_i = nodes[i];
            else {
                node_i = new Node(i);
                nodes[i] = node_i;
            }

            DeleteNode(node_i);
        }
        else if (x == 2) {
            cin >> i >> j;
            if (nodes.find(i) != nodes.end())
                node_i = nodes[i];
            else {
                node_i = new Node(i);
                nodes[i] = node_i;
            }

            if (nodes.find(j) != nodes.end())
                node_j = nodes[j];
            else {
                node_j = new Node(j);
                nodes[j] = node_j;
            }
                

            InsertPrev(node_i, node_j);
        }
        else if (x == 3) {
            cin >> i >> j;
            if (nodes.find(i) != nodes.end())
                node_i = nodes[i];
            else {
                node_i = new Node(i);
                nodes[i] = node_i;
            }
                

            if (nodes.find(j) != nodes.end())
                node_j = nodes[j];
            else {
                node_j = new Node(j);
                nodes[j] = node_j;
            }
            
            InsertNext(node_i, node_j);
        }
        else if (x == 4) {
            cin >> i;
            if (nodes.find(i) != nodes.end())
                node_i = nodes[i];
            else {
                node_i = new Node(i);
                nodes[i] = node_i;
            }
            
            PrintNode(node_i);
        }
    }

    for (int i = 1; i <= N; i++) {
        if (nodes.find(i) != nodes.end()) {
            PrintNextNode(nodes[i]);
        }
        else {
            cout << "0 ";
        }
    }

    return 0;
}