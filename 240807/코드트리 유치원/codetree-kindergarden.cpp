#include <iostream>
using namespace std;

int order = 2;

struct Node {
    Node *next, *prev;
    int num;

    Node(int n): num(n), next(nullptr), prev(nullptr) {};
};

Node* student[100005];

void connect(Node* node1, Node* node2) {
    node1->next = node2;
    node2->prev = node1;
}

void insertFront(int target, int num_student) {
    Node* prev_student = student[target]->prev;

    for (int i = 0; i < num_student; i++) {
        Node* new_student = new Node(order);
        student[order++] = new_student;

        connect(prev_student, new_student);
        prev_student = new_student;
    }
    connect(prev_student, student[target]);
}

void insertBack(int target, int num_student) {
    Node* prev_student = student[target];
    Node* next_student = student[target]->next;

    for (int i = 0; i < num_student; i++) {
        Node* new_student = new Node(order);
        student[order++] = new_student;

        connect(prev_student, new_student);
        prev_student = new_student;
    }
    connect(prev_student, next_student);
}

void print(int target) {
    int prev_student = student[target]->prev->num;
    int next_student = student[target]->next->num;
    
    if (prev_student == -1 || next_student == -1) {
        cout << -1 << "\n";
        return;
    }

    cout << prev_student << " " << next_student << "\n";
}

int main() {
    int Q;
    cin >> Q;

    student[1] = new Node(1);
    connect(new Node(-1), student[1]);
    connect(student[1], new Node(-1));

    for (int i = 0; i < Q; i++) {
        int commmand, target, num_student;
        cin >> commmand;
        switch(commmand) {
            case 1:
                cin >> target >> num_student;
                insertBack(target, num_student);
                break;
            case 2:
                cin >> target >> num_student;
                insertFront(target, num_student);
                break;
            case 3:
                cin >> target;
                print(target);
                break;
        }
    }
    return 0;
}