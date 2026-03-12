#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// #2
struct Date {
    int day;
    int month;
    int year;
};

struct Person {
    string name;
    Date dateOfBirth;
};

struct ProjectTeam {
    Person MemberA, MemberB;
    Person Leader;
    string projectName;
    double projectBudget;
    Date projectDueDate;
};

// #3
struct Node {
    float node_number;
    string node_name;
    Node *next_node; // ptr to node structure
};
typedef Node* node_ptr;

// #4
struct LinkNode {
    string name;
    int number;
    LinkNode* link;
};
typedef LinkNode* LinkNodePtr;

// #4 print_LL funcion declaration
void printLL(LinkNodePtr h);


int main() {
    // Set precision
    cout << fixed << showpoint << setprecision(2);

    double projectBudget = 1035.50;

    ProjectTeam TheATeam;
    TheATeam.projectBudget = 1045.50;

    TheATeam.MemberB.name = "Pedro Gutierrez";

    TheATeam.Leader.dateOfBirth.year = 1989;

    // #2a
    cout << "The project budget is: $" << TheATeam.projectBudget << "." << endl;

    // #2b
    cout << "MemberB of TheATeam is: " << TheATeam.MemberB.name << "." << endl;

    // #2c
    cout << "Our project leader's birth year is: " << TheATeam.Leader.dateOfBirth.year << "." << endl;

    // #2d
    TheATeam.MemberA.name = "Banana Fana";
    cout << "The name of MemberA of TheATeam is: " << TheATeam.MemberA.name << "." << endl;


    // #3
    Node A, B;

    // #3a
    A.node_name = "Taco";
    A.node_number = 6;

    B.node_name = "Nacho";
    B.node_number = 7;

    cout << A.node_name << " " << B.node_name << endl;
    cout << A.node_number << " " << B.node_number << endl;

    // #3b
    // head->count better than (*head).count

    // #3c
    A.next_node = &B;
    B.next_node = nullptr;

    cout << endl;

    // #4
    // Case 1: 5 nodes
    LinkNodePtr head = new LinkNode{"Taco", 1, nullptr};
    LinkNodePtr n2 = new LinkNode{"Nacho", 2, nullptr};
    LinkNodePtr n3 = new LinkNode{"Burrito", 3, nullptr};
    LinkNodePtr n4 = new LinkNode{"Enchilada", 4, nullptr};
    LinkNodePtr n5 = new LinkNode{"Quesadilla", 5, nullptr};

    // Connect the nodes
    head->link = n2;
    n2->link = n3;
    n3->link = n4;
    n4->link = n5;
    
    // Print the linked list for the populated list
    cout << "5 node list case: " << endl;
    printLL(head);

    cout << endl;

    // Case 2: emp-t
    LinkNodePtr emptyHead = nullptr;
    cout << "Empty list case: " << endl;

    // Print the linked list for the empty list
    printLL(emptyHead);
    cout << endl;

    // Delete new nodes to save memory once both test cases are done running
    delete n5; delete n4; delete n3; delete n2; delete head;

    return 0;
}

// #4 printLL funcion definition
void printLL(LinkNodePtr h) {
    // Check if no nodes present
    // If no nodes, exit
    if (h == nullptr) {
        cout << "This list is empty." << endl;
        return;
    }

    // Print list string if list not empty
    cout << "Printing the list:" << endl;

    // Print each value in each Node
    LinkNodePtr temp = h;
    int count = 0;
    while (temp != nullptr) {
        cout << "Node #" << count << ": ";
        cout << temp->name << ", " << temp->number << endl;
        temp = temp->link;
        count++;
    }
}