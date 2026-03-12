// Demonstrates basic building of a linked list of nodes
//  by Z.Matni (c) 2026 for CS 16
//
#include <iostream>
#include <string>
using namespace std;

// Function to insert nodes
struct Node {
    int num;
    Node* next;
};

// Define type of NodePtr as Node* for easier calling & use later
typedef Node* NodePtr;

struct LinkNode {
    string item;
    int value;
    LinkNode *link;
};

int main() {
    LinkNode NodeX, NodeY, NodeZ;

    NodeX.item = "thing1";
    NodeX.value = 5;

    NodeY.item = "thing2";
    NodeY.value = 7;

    NodeZ.item = "thing3";
    NodeZ.value = 8;

    NodeX.link = &NodeY;
    NodeY.link = &NodeZ;
    NodeZ.link = nullptr;

// Create a pointer that points to the start of this linked list:
    typedef LinkNode* LinkNodePtr;
    LinkNodePtr head;
    head = new LinkNode;
    *head = NodeX;

// Go thru the linked list and add all the values
    int sum = 0;

    // Start at the head pointer, which points to NodeX
    sum += (*head).value;
    head = (*head).link;    // head points to NodeY now

    sum += (*head).value;
    head = (*head).link;    // head points to NodeZ now

    sum += (*head).value;

    cout << "Sum of all values = " << sum << endl;

    return 0;
}
