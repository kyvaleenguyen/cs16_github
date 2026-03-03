// Demonstrates building a linked list of nodes
//  by adding new nodes to the front:
//  head --> node 3 --> node 2 --> node 1 --> node 0
//
//  by Z.Matni (c) 2026 for CS 16
//
#include <iostream>
using namespace std;

struct Node {
    int num;
    Node *next;
};
typedef Node* NodePtr;

// "add to the front" method of inserting nodes
void h_insert_front(NodePtr& head, int val);

// Print the linked list function using NodePtr at head
void print_ll(NodePtr h);


int main() {

    // Currently we are at the very first node in the linked list
    // The head currently points to "nothing" or "nullptr" (instead of using "nullptr" you can also use "NULL")
    NodePtr head = nullptr;

    // Insert new nodes using "add to the front" method at head of node
    h_insert_front(head, 5);
    h_insert_front(head, 7);
    h_insert_front(head, 8);

    // Print linked list from the head
    // Prints each node inserted into the linked list
    //      Note: node indexing is the same as any list indexing (it starts at 0 for the first element)
    print_ll(head);

    
    // Cin experiment with multiple same line inputs
    string nom = "";
    int num;
    cin >> nom >> num;

    return 0;
}


// "add to the front" head insert at front function definition
void h_insert_front(NodePtr& head, int val) {
    NodePtr tmp_p;
    tmp_p = new Node;

    tmp_p->num  = val;
    tmp_p->next = head;

    head = tmp_p;
}

// print linked list function definition
void print_ll(NodePtr h) {
    NodePtr temp = h;
    int count(0);
    while (temp != nullptr) {
        cout << "Node " << count << ": ";
        cout << temp->num << endl;
        temp = temp->next;
        count++;
    }
}
