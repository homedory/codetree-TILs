#include <iostream>
#include <unordered_map>
using namespace std;

int N, M, Q;

struct Node {
    Node *prev, *next;
    int num;

    Node(int num): num(num), prev(nullptr), next(nullptr) {};
};

void connect(Node *node1, Node *node2) {
    node1->next = node2;
    node2->prev = node1;
}

void combineCircle(Node *node_a, Node *node_b) {
    Node *a_next = (node_a->next != nullptr) ? node_a->next : node_a;
    Node *b_prev = (node_b->prev != nullptr) ? node_b->prev : node_b;
    
    connect(node_a, node_b);
    connect(b_prev, a_next);
}

void splitCircle(Node *node_a, Node *node_b) {
    connect(node_a->prev, node_b);

    Node *node = node_a;
    while(node->next != node_b) {
        node = node->next;
    }
    connect(node, node_a);
}

void printCircle(Node *node) {
    Node *start_node = node;
    int min_num = node->num;

    Node *cur_node = node->next;
    while(cur_node != node) {
        if (min_num > cur_node->num) {
            min_num = cur_node->num;
            start_node = cur_node;
        }
        cur_node = cur_node->next;
    }

    cout << start_node->num << " ";
    cur_node = start_node->prev;
    while(cur_node != start_node) {
        cout << cur_node->num << " ";
        cur_node = cur_node->prev;
    }
    cout << "\n";
}

void insertNode(Node *node1, Node *node2) {
    node2->next = node1->next;
    node2->prev = node1;
    node1->next->prev = node2;
    node1->next = node2;
}

int main() {
    unordered_map<int, Node*> student;
    int N, M, Q;
    cin >> N >> M >> Q;

    for (int i = 0; i < M; i++) {
        int num_student, num;
        cin >> num_student;

        cin >> num;

        Node* new_student = new Node(num);
        new_student->next = new_student;
        new_student->prev = new_student;
        student[num] = new_student;
        
        Node *prev_student = new_student;
        for (int j = 0; j < num_student - 1; j++) {
            cin >> num;

            Node* new_student = new Node(num);
            student[num] = new_student;

            insertNode(prev_student, new_student);
            prev_student = new_student;
        }
    }

    int command, A, B;
    for (int i = 0; i < Q - 1; i++) {
        cin >> command >> A >> B;

        switch(command) {
            case 1:
                combineCircle(student[A], student[B]);
                break;
            case 2:
                splitCircle(student[A], student[B]);
                break;
        }
    }

    cin >> command >> A;
    printCircle(student[A]);


    return 0;
}